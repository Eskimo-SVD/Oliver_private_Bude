/* env.c */
#include <stdio.h>
#include <stdlib.h>

/* Listing gibt alle vorhandenen Environment-Variablen aus */

char *env[] =  { 
   "AUTH_TYPE", "CONTENT_LENGTH", "CONTENT_TYPE",
   "GATEWAY_INTERFACE", "HTTP_ACCEPT", "HTTP_CONNECTION",
   "HTTP_HOST", "HTTP_REFERER", "HTTP_USER_AGENT",
   "PATH_INFO", "PATH_TRANSLATET", "QUERY_STRING",
   "REMOTE_ADDR", "REMOTE_HOST", "REMOTE_IDENT",
   "REMOTE_USER", "REQUEST_METHOD", "SCRIPT_NAME",
   "SERVER_NAME", "SERVER_PORT", "SERVER_PROTOCOL",
   "SERVER_SOFTWARE" , NULL
};

/* Die Kopfzeile eines Standard-HTML-Dokuments
 * titel: String, der als Titel erscheinen soll
 */   
void print_html_header(char *titel) {
   printf("<html><head>\n");
   printf("<title>%s</title>\n",titel);
   printf("</head><body><pre>\n");
}

/* Das Ende eines HTML-Dokuments */
void print_html_end(void) {
   printf("</pre></body></html>\n");
}

/* Damit überhaupt ein HTML-Dokument ausgegeben wird */
void print_header(void) {
   printf("Content-Type: text/html\n\n");
}

/* Inhalt der Environment-Variable ausgeben*/
void environment(const char *s) {
   char *p;

   p = getenv(s);
   printf ("%s", s);
   if(p!=NULL)
      printf (" = %s", p);
   else
      printf(" = (<i>keine Angaben</i>)");
   printf ("<BR>\n");
}

int main(void) {
   int i;

   print_header();
   print_html_header("CGI-Umgebungsvariablen ausgeben - 2\n");
   for(i=0; env[i] != NULL; i++)
      environment(env[i]);
   print_html_end();
   return EXIT_SUCCESS;
}

