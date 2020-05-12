/*
http://www.informit.com/articles/article.aspx?p=22078
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <arpa/inet.h>      /* for htons() */

#include <openssl/conf.h>
#include <openssl/opensslconf.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>


#define CERT_FILENAME "cert/server.crt"
#define KEY_FILENAME "cert/server.key.insecure"

#define BUFSIZE 1024


static int respond(SSL *ssl, char *mesg, int rcvd, const char *root);


const char *do_accept(int port, const char *root)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    char buf[BUFSIZE];
    int r;
    
    method = TLSv1_1_server_method();   /* create server instance */
    if(!method) return "TLS_server_method";
    
    ctx = SSL_CTX_new(method);         /* create context */
    if(!ctx) return "SSL_CTX_new";
    
     /* set the local certificate from CertFile */
    SSL_CTX_use_certificate_file(ctx, CERT_FILENAME, SSL_FILETYPE_PEM);
     /* set the private key from KeyFile */
    SSL_CTX_use_PrivateKey_file(ctx, KEY_FILENAME, SSL_FILETYPE_PEM);
     /* verify private key */
    if(!SSL_CTX_check_private_key(ctx))
        return "SSL_CTX_check_private_key";
    
    /*--- Standard TCP server setup and connection ---*/
    int sd, client;
    struct sockaddr_in addr;
    sd = socket(PF_INET, SOCK_STREAM, 0); /* create stream socket */
    if(sd<0)
        return "%socket";   /* leading % means unistd.h function */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);         /* select 'port' */
    addr.sin_addr.s_addr = INADDR_ANY;   /* any available addr */
    r=bind(sd, (struct sockaddr*)&addr, sizeof(addr));  /* bind it */
    if(r<0)
        return "%bind";
    r=listen(sd, 10);         /* make into listening socket */
    if(r<0)
        return "%listen";
    client = accept(sd, NULL, NULL);  /* await and accept connections */
    if(accept<0)
        return "%accept";

    int bytes;
    SSL *ssl = SSL_new(ctx);  /* get new SSL state with context */
    if(!ssl)
        return "SSL_new";
    r=SSL_set_fd(ssl, client);    /* set connection to SSL state */
    if(r!=1)
        return "SSL_set_fd";
    r=SSL_accept(ssl);           /* start the handshaking */
    if(r!=1)
        return "SSL_accept";
    
    /* now you can read/write */
    
    bytes = SSL_read(ssl, buf, sizeof(buf)); /* get HTTP request */
    if(bytes<0)
        return "SSL_read";
    if(bytes<0)    // receive error
    {
        return "SSL_read";
    }
    if(bytes==0)    // receive socket closed
    {
        fprintf(stderr,"Client disconnected upexpectedly.\n");
        return NULL;
    }
    r=respond(ssl, buf, bytes, root);
    if(r!=1)
        return "respond";
    
    /* loop */
     /* close connection & clean up */
    client = SSL_get_fd(ssl);      /* get the raw connection */
    if(client<0)
        return "SSL_get_fd";
    SSL_free(ssl);              /* release SSL state */
    close(sd);                /* close connection */
    return NULL;
}

#if 0

int serverLoop(const char *root, int port, int bytes_max, int conn_max)
{
    int listenfd, *clients=malloc(conn_max * sizeof(int));
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char c;    
    
    // Setting all elements to -1: signifies there is no client connected
    int i;
    for (i=0; i<conn_max; i++)
        clients[i]=-1;
    startServer(port);

    // ACCEPT connections
    while (1)
    {
        addrlen = sizeof(clientaddr);
        clients[slot] = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);

        if (clients[slot]<0)
            error ("accept() error");
        else
        {
            if ( fork()==0 )
            {
                respond(slot);
                exit(0);
            }
        }

        while (clients[slot]!=-1) slot = (slot+1)%CONNMAX;
    }

    return 0;
}


#endif


static int stringwrite(SSL *ssl, const char *outmesg)
{
    return SSL_write(ssl, outmesg, strlen(outmesg));
}


/*http://blog.abhijeetr.com/2010/04/very-simple-http-server-writen-in-c.html*/
//client connection
static int respond(SSL *ssl, char *mesg, int rcvd, const char *root)   /* destroys mesg */
{
    char *reqline[3], data_to_send[BUFSIZE], path[BUFSIZE];
    int fd, bytes_read;

    // message received
    printf("DEBUG: %s", mesg);
    reqline[0] = strtok(mesg, " \t\n");
    if(strncmp(reqline[0], "GET\0", 4)==0 )
    {
        reqline[1] = strtok(NULL, " \t");
        reqline[2] = strtok(NULL, " \t\n");
        if( strncmp(reqline[2], "HTTP/1.0", 8)!=0 && strncmp( reqline[2], "HTTP/1.1", 8)!=0 )
        {
            stringwrite(ssl, "HTTP/1.0 400 Bad Request\n");
        }
        else
        {
            if(strncmp(reqline[1], "/\0", 2)==0 )
                reqline[1] = "/index.html";        //Because if no file is specified, index.html will be opened by default (like it happens in APACHE...

            if(strlen(root)+strlen(reqline[1])+1>BUFSIZE)
                return 0;   /* protect the stack */ 
            strcpy(path, root);
            strcat(path, reqline[1]);
            printf("file: %s\n", path);

            if( (fd=open(path, O_RDONLY))!=-1 )    //FILE FOUND
            {
                stringwrite(ssl, "HTTP/1.0 200 OK\n\n");
                while((bytes_read=read(fd, data_to_send, BUFSIZE))>0)
                    SSL_write(ssl, data_to_send, bytes_read);
            }
            else
                stringwrite(ssl, "HTTP/1.0 404 Not Found\n"); //FILE NOT FOUND
        }
    }
    return 1;
}


void init_ssl_lib(void)
{
    (void)SSL_library_init();

    //manOpenSSL_add_all_algorithms();   /* load & register cryptos */
    //SSL_load_error_strings();     /* load all error messages */

    SSL_load_error_strings();

    /* ERR_load_crypto_strings(); */
  
    OPENSSL_config(NULL);
    
    /* Include <openssl/opensslconf.h> to get this define */
#if defined (OPENSSL_THREADS)
    fprintf(stdout, "Warning: thread locking is not implemented\n");
#endif
}


int main(int argc, char *argv[])
{
    const char *s;
    int r;
    
    if(argc<3)
    {
        printf("usage: %s <port> <path>\n", argv[0]);
        return 1;
    }
    r=strlen(argv[2]);
    if(r!=0 && argv[2][r-1]=='/')
    {
        argv[2][r-1]='\x00';
    }
    
    init_ssl_lib();
    s=do_accept(atol(argv[1]), argv[2]);
    if(s!=NULL)
    {
        if(s[0]!='%')
        {
            char buf[120];
            puts(ERR_error_string(ERR_get_error(), buf));
        }
        else
        {
            perror(s+1);
        }
        return 9;
    }
    return 0;
}
