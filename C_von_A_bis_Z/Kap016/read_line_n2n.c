/* read_line_n2n.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

char temp[BUF];
char puffer[BUF];
int i;  /* Zeilenzaehler */

/* Lesen von Zeile n1 bis Zeile n2 */
char *getsline_number(int n1,int n2, FILE *file) {
   for(i = 0; i < n1-1; i++)
      /* Bis zur n1-ten Zeile lesen */
      if(fgets(temp, BUF, file) == NULL)
         return NULL; /* Zeile scheint nicht zu existieren */
   /* Jetzt beginnt das eigentliche Lesen */
   printf("\n\n");
   for(i = n1; i <= n2; i++) {
      if(fgets(puffer,BUF,file) == NULL)
         /* Stream ist jetzt in der n-ten Zeile */
         return NULL;  /* Zeile scheint nicht zu existieren */
      printf("Zeile %d : %s", i, puffer);
   }
}

int main(int argc, char *argv[]) {
   FILE *f;
   int line1, line2;
   char *linenr;

   if(argc < 2) {
      fprintf(stderr, "Verwendung : %s datei\n", *argv);
      return EXIT_FAILURE;
   }
   f = fopen(argv[1],"r");
   if(f == NULL) {
      printf("Fehler bei fopen()...\n");
      return EXIT_FAILURE;
   }
   printf("von Zeile wollen Sie lesen : ");
   scanf("%d", &line1);
   printf("bis Zeile wollen Sie lesen : ");
   scanf("%d", &line2);

   if(line2 < line1) {
      fprintf(stderr, "bis-Zeile kann nicht "
                      "grösser sein, wie von-Zeile!\n");
      return EXIT_FAILURE;
   }
   linenr=getsline_number(line1,line2, f);
   if(linenr == NULL) {
      fprintf(stderr, "Fehler beim Lesen "
                      "der %d-ten Zeile??\n",i);
      return EXIT_FAILURE;
   }
   printf("\n");
   return EXIT_SUCCESS;
}

