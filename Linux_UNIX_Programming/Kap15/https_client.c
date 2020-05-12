/* https://wiki.openssl.org/index.php/SSL/TLS_Client */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/conf.h>
#include <openssl/opensslconf.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>

//const char * const PREFERRED_CIPHERS = "HIGH:!aNULL:!kRSA:!PSK:!SRP:!MD5:!RC4:!SHA1";
const char * const PREFERRED_CIPHERS = "HIGH";

const char * const GET_COMMAND = "GET %s HTTP/1.1\r\n"
                  "Host: %s\r\n"
                  "Connection: close\r\n\r\n";


int verify_callback(int preverify, X509_STORE_CTX* x509_ctx);


const char *do_get(const char *hostname, int hostport, const char *rsrc, FILE *outf)
{
    long res = 1;
    
    SSL_CTX* ctx = NULL;
    BIO *web = NULL;
    SSL *ssl = NULL;
    int buflen = strlen(hostname)+strlen(GET_COMMAND)+strlen(rsrc);
    char *buf = alloca(buflen);
    
    const SSL_METHOD* method = TLSv1_2_client_method();
    if(!method) return "TLS_client_method";
    
    ctx = SSL_CTX_new(method);
    if(!ctx) return "SSL_CTX_new";
    
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, verify_callback);
    
    SSL_CTX_set_verify_depth(ctx, 4);
    
    const long flags = SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION;
    SSL_CTX_set_options(ctx, flags);
    
    res = SSL_CTX_load_verify_locations(ctx, "cert/server.crt", NULL);
    if(res!=1) return "SSL_CTX_load_verify_locations";
    
    web = BIO_new_ssl_connect(ctx);
    if(!web) return "BIO_new_ssl_connect";

    sprintf(buf, "%s:%d", hostname, hostport); printf("DEBUG: %s\n", buf);
    res = BIO_set_conn_hostname(web, buf);
    if(res!=1) return "BIO_set_conn_hostname";
    
    BIO_get_ssl(web, &ssl);
    if(!ssl) return "BIO_get_ssl";
    
    res = SSL_set_cipher_list(ssl, PREFERRED_CIPHERS);
    if(res!=1) return "SSL_set_cipher_list";
    
    res = SSL_set_tlsext_host_name(ssl, hostname);
    if(res!=1) return "SSL_set_tlsext_host_name";
    
    res = BIO_do_connect(web);
    if(res!=1) return "BIO_do_connect";
    
    res = BIO_do_handshake(web);
    if(res!=1) return "BIO_do_handshake";
    
    /* Step 1: verify a server certificate was presented during the negotiation */
    X509* cert = SSL_get_peer_certificate(ssl);
    if(cert) { X509_free(cert); } /* Free immediately */
    else
        return "SSL_get_peer_certificate";
    
    /* Step 2: verify the result of chain verification */
    //res = SSL_get_verify_result(ssl);
    //if(!(X509_V_OK == res)) return "SSL_get_verify_result";
    
    /* Step 3: hostname verification */
    /* An exercise left to the reader */
    
    sprintf(buf, GET_COMMAND, rsrc, hostname);
    BIO_puts(web, buf);
    
    int len = 0;
    do
    {
      len = BIO_read(web, buf, buflen-1);
      buf[buflen-1]=0; /* no matter how long it is, do terminate it */
                
      if(len>0 && outf)
        fputs(buf, outf);
    
    } while (len > 0 || BIO_should_retry(web));
    
    if(web != NULL)
      BIO_free_all(web);
    
    if(NULL != ctx)
      SSL_CTX_free(ctx);
  
    return NULL;
}


int verify_callback(int preverify, X509_STORE_CTX* x509_ctx)
{
    return 1;
}


void init_ssl_lib(void)
{
    (void)SSL_library_init();

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
    const char *r;
    
    if(argc<4)
    {
        printf("usage: %s <hostname> <port> <path>\n", argv[0]);
        return 1;
    }
    
    if(argv[3][0]!='/')
    {
        fputs("Path must start with a slash '/'.\n", stderr);
        return 2;
    }
    
    init_ssl_lib();
    r=do_get(argv[1],atol(argv[2]),argv[3],NULL);
    printf("do_get() return value = %s\n", r?r:"NULL (=OKAY)");
    if(r!=NULL)
    {
        char buf[120];
        puts(ERR_error_string(ERR_get_error(), buf));
    }
    return (r!=NULL)?9:0;
}
