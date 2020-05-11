/* btree3.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255

struct binaer_knoten{
   char ort[MAX];
   unsigned int plz;
   struct binaer_knoten *links;
   struct binaer_knoten *rechts;
};

struct binaer_baum{
   struct binear_knoten *root;
   unsigned int counter;
};

struct binaer_baum *init(void) {
   struct binaer_baum *baum = malloc(sizeof *baum);
   if(baum == NULL) { 
      fprintf(stderr, "Speicherplatzmangel!!!\n");
      return NULL;
   }
   else { /*Initialisieren*/
      baum->root = NULL;
      baum->counter=0;
      return baum;
   }
}

int einfuegen(struct binaer_baum *baum, unsigned int p, char *o){
   struct binaer_knoten *knoten, **neu;

   neu =(struct binaer_knoten **) &baum->root;
   knoten= (struct binaer_knoten *) baum->root;
   for(;;) {
      if(knoten == NULL) {
         /* Haben wir einen freien Platz gefunden? */
         knoten = *neu = malloc(sizeof *knoten);
         if(knoten != NULL) {
            /* Daten rein damit */
            knoten->plz = p;
            strcpy(knoten->ort, o);
            knoten->links=knoten->rechts=NULL;
            baum->counter++;
            /* Beendet die Funktion erfolgreich */
            return 1; 
         }
         else {
            fprintf(stderr, "Speicherplatzmangel\n");
            return 0;
         }
      }
      /* Ist die aktuelle Postleitzahl größer */
      else if(p > knoten->plz)  {
         /* Dann gehts rechts weiter im Baum */
         neu = &knoten->rechts;
         knoten = knoten->rechts;
      }
      else { /* Der letzte Fall, die aktuelle PLZ ist kleiner */
         /* dann eben nach links weiter im Baum */
         neu = &knoten->links;
         knoten = knoten->links;
      }
   }
}

void binaere_suche_plz(const struct binaer_baum *baum,
                       unsigned int p) {
   const struct binaer_knoten *knoten;

   /* Zuerst an die Wurzel */
   knoten = (struct binaer_knoten *) baum->root;
   for(;;) {
      if(knoten == NULL) {
         printf("Keine erfolgreiche Suche!\n");
         return;
      }
      if(p == knoten->plz) {  /* Gefunden */
         printf("Ort zu Postleitzahl %d : %s\n",
            p,knoten->ort);
         return;
      }
      else if(p > knoten->plz)   /* Gesuchtes Element größer  */
         knoten=knoten->rechts;  /* Rechts am Baum weiter     */
      else                       /* Gesuchtes Element kleiner */
         knoten=knoten->links;   /* Links am Baum weiter      */
   }
}

int bin_delete(struct binaer_baum *baum, unsigned int p) {
   /* pointer_z ist das zu löschende Element */
   struct binaer_knoten **pointer_q, *pointer_z, 
                         *pointer_y, *pointer_x;

   pointer_q = (struct binaer_knoten **)&baum->root;
   pointer_z =  (struct binaer_knoten *)baum->root;
   for(;;) {
      if(pointer_z == NULL)
         return 0;
      else if(p == pointer_z->plz) 
         /* zu löschendes Element gefunden */
         break;
      else if(p > pointer_z->plz) {
         /* löschende Element ist größer */
         pointer_q = &pointer_z->rechts; 
         /* rechts weitersuchen */
         pointer_z = pointer_z->rechts;
      }
      else { /* Löschende Element ist kleiner */
         pointer_q = &pointer_z->links;
         /* links weitersuchen */
         pointer_z = pointer_z->links;
      }
   } /* Hierher kommen wir nur durch ein break */

   /* Jetzt müssen wir das zu löschende Element untersuchen
    * pointer_z hat rechts keinen Nachfolger, somit können wir
    * es austauschen gegen den linken Nachfolger ... */
   if(pointer_z->rechts == NULL)
      *pointer_q = pointer_z->links;
   else {
      /* pointer_z hat einen rechten Nachfolger, aber 
       * keinen linken.   */
      pointer_y = pointer_z->rechts;
      if(pointer_y->links == NULL) {
         /* pointer_z->rechts hat keinen linken Nachfolger ... */
         pointer_y->links = pointer_z->links;
         *pointer_q = pointer_y;
      }
      else {  /* es gibt einen linken Nachfolger */
         pointer_x = pointer_y->links;
         /* Jetzt suchen wir so lange, bis es keinen linken
          * Nachfolger mehr gibt */
         while(pointer_x->links != NULL) {
            pointer_y = pointer_x;
            pointer_x = pointer_y->links;
         }
         /* Jetzt haben wir alle Punkte zusammen und 
          * können diese verknüpfen   */
         pointer_y->links = pointer_x->rechts;
         pointer_x->links = pointer_z->links;
         pointer_x->rechts = pointer_z->rechts;
         *pointer_q = pointer_x;
      }
   }
    /* Zu guter Letzt können wir pointer_z freigeben */
   baum->counter--;
   free(pointer_z);
   return 1;
}

int main(void) {
   struct binaer_baum *re;
   char o[MAX];
   unsigned int p;
   int wahl, r;

   re = init();
   if(re == NULL) {
      printf("Konnte keinen neuen binären Baum erzeugen!\n");
      return EXIT_FAILURE;
   }
   else
      printf("Binärbaum wurde erfolgreich Initialisiert\n");

   do {
      printf("\n-1- Neue PLZ hinzufügen\n");
      printf("-2- PLZ suchen\n");
      printf("-3- PLZ löschen\n");
      printf("-4- Ende\n\n");
      printf("Ihre Wahl : ");
      scanf("%d",&wahl);

      if(wahl == 1) {
         printf("Bitte geben Sie eine neue PLZ ein : ");
         do{ scanf("%5d",&p); }while( (getchar()) != '\n' );
         printf("Der Ort dazu : ");
         fgets(o, MAX, stdin);
         r=einfuegen(re, p, strtok(o, "\n") );
         if(r == 0)
            return EXIT_FAILURE;
       }
       else if(wahl == 2) {
          printf("Für welche PLZ suchen Sie einen Ort : ");
          scanf("%5u",&p);
          binaere_suche_plz(re, p);
       } 
       else if(wahl == 3) {
          printf("Welche PLZ wollen Sie löschen : ");
          scanf("%5u",&p);
          bin_delete(re, p);
       }
    } while(wahl != 4);
   return EXIT_SUCCESS;
}



