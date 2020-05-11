/* txt2html_example.c */
#include <stdio.h>
#include <stdlib.h>

/* nchars = Anzahl der Zeichen  */
/* tag    = Sonderzeichen in HTML  */
/* ziel   = Datei, in die geschrieben wird */

void sonderzeichen(int nchars, char *tag, FILE *ziel) {
   int i;
   char zeichen;

   for(i = 0; i < nchars; i++) {
      zeichen = tag[i];
      putc(zeichen, ziel);
   }
}

int main(int argc, char **argv) {
   FILE *q, *z;
   int zeichen;

   if(argc < 3) {
      printf("Benutzung : %s quelle ziel\n", *argv);
      return EXIT_FAILURE;
   }

   q = fopen(argv[1], "r");
   z = fopen(argv[2], "w");
   if(q == NULL || z == NULL) {
      printf("Fehler bei Oeffnen einer Datei ...\n");
      return EXIT_FAILURE;
   }
   while((zeichen=getc(q)) != EOF) {
      if(zeichen=='<')
         sonderzeichen(4,"&lt;", z);
      else if(zeichen=='>')
         sonderzeichen(4,"&gt;", z);
      else if(zeichen=='\"')
         sonderzeichen(6,"&quot;",z);
      else if(zeichen=='&')
         sonderzeichen(5,"&amp;",z);
      else if(zeichen=='ä')
         sonderzeichen(6 ,"&auml;",z);
      else if(zeichen=='Ä')
         sonderzeichen(6 ,"&Auml;",z);
      else if(zeichen=='ö')
         sonderzeichen(6 ,"&ouml;",z);
      else if(zeichen=='Ö')
         sonderzeichen(6 ,"&Ouml;",z);
      else if(zeichen=='ü')
         sonderzeichen(6 ,"&uuml;",z);
      else if(zeichen=='Ü')
         sonderzeichen(6 ,"&Uuml;",z);
      else if(zeichen=='ß')
         sonderzeichen(6 ,"&szlig;",z);
      else
         putc(zeichen, z);
   }
   return EXIT_SUCCESS;
}

