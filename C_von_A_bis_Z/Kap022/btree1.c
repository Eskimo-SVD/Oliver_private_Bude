/* btree1.c */
#include <stdio.h>
#include <stdlib.h>

struct knoten{
   int wert;
   struct knoten *links;
   struct knoten *rechts;
};
typedef struct knoten KNOTEN;

/* Globale Variable */
int zahl;

KNOTEN *einordnen(KNOTEN *zeiger)  {
   if(zeiger == NULL) {
      zeiger = malloc(sizeof(KNOTEN));
      if(zeiger==NULL) {
         printf("Konnte keinen Speicherplatz reservieren!\n");
         exit (EXIT_FAILURE);
      }
      zeiger->wert=zahl;
      zeiger->links=zeiger->rechts=NULL;
   }
   else if(zeiger->wert >= zahl)
      zeiger->links=einordnen(zeiger->links);
   else if(zeiger->wert < zahl)
      zeiger->rechts=einordnen(zeiger->rechts);
   return (zeiger);
}

int main(void) {
   KNOTEN *wurzel=NULL;

   do {
      printf("Bitte Zahl eingeben : ");
      scanf("%d",&zahl);
      wurzel=einordnen(wurzel);
   } while(zahl != 0);
   return EXIT_SUCCESS;
}

