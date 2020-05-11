/* browser.c */
#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
   char *p;

   print_header();
   print_html_header("Wer bin ich?");
   p = getenv("HTTP_USER_AGENT");
   if(p!=NULL)
      printf("Sie browsen mit : %s\n",p);
   else
      printf("Konnte HTTP_USER_AGENT nicht ermitteln!\n");
   print_html_end();
   return EXIT_SUCCESS;
}

