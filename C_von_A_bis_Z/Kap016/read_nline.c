/* read_nline.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

char temp[BUF];
char puffer[BUF];

/* Auslesen der n-ten Zeile */
char *getsline_number(int n, FILE *file) {
   int i;

   for(i = 0; i < n-1; i++)
      if(fgets(temp, BUF, file) == NULL)
         /* Bis zur n-ten Zeile lesen */
         return NULL; /* Zeile scheint nicht zu existieren */
   /* Stream ist jetzt in der n-ten Zeile */     
   if(fgets(puffer,BUF,file) == NULL)
      return NULL; /* Zeile scheint nicht zu existieren */
   return puffer; /* Zeile an Aufrufer zurück */
}

int main(int argc, char **argv) {
   FILE *f;
   unsigned int line;
   char *linenr;

   if(argc < 2) {
      fprintf(stderr, "Verwendung : %s datei\n",*argv);
      return EXIT_FAILURE;
   }
   f = fopen(argv[1],"r");
   if(f == NULL) {
      printf("Fehler beim Öffnen");
      return EXIT_FAILURE;
   }
   printf("Welche Zeile wollen Sie lesen : ");
   scanf("%d",&line);

   linenr=getsline_number(line, f);
   if(linenr == NULL) {
      fprintf(stderr, "Fehler beim Lesen der"
                      " %d-ten Zeile??\n",line);
      return EXIT_FAILURE;   
    }
   printf("Zeile %d : %s\n", line, linenr);
   return EXIT_SUCCESS;
}

