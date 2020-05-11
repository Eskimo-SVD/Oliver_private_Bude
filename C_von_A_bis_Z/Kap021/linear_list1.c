/* linear_list1.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

struct datum {
   int tag;
   int monat;
   int jahr;
};

struct angestellt {
   char name[MAX];
   char vorname[MAX];
   struct datum alter;
   struct datum eingest;
   long gehalt;
   struct angestellt *next;
};

struct angestellt *next = NULL;
struct angestellt *anfang=NULL;

/* Wir hängen einen Datensatz an oder geben einen neuen ein
 * n=name,v=vornam,at=alter.tage,am=alter.monat,aj=alter.jahr
 * eint=eigestellt tag,einm=eingestellt monat,einj=eingest.
 * Jahr  g=gehalt  */

void anhaengen(char *n, char *v, int at, int am, int aj,
                int eint, int einm, int einj, long g) {
   /* Zeiger zum Zugriff auf die einzelnen Elemente 
    * der Struktur*/
   struct angestellt *zeiger;

  /* Wir fragen ab, ob es schon ein Element in der Liste
   * gibt. Wir suchen das Element, auf das unser Zeiger 
   *  *anfang zeigt. Falls *anfang immer noch auf NULL zeigt,
   *  bekommt *anfang die Adresse unseres 1. Elements und ist 
   *  somit der Kopf (Anfang) unserer Liste  */
   if(anfang == NULL) {
      /* Wir reservieren Speicherplatz für unsere Struktur 
       * für das erste Element der Liste*/
      if((anfang =
       malloc(sizeof(struct angestellt))) == NULL) {
         fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "für anfang\n");
         return;
      }
      strcpy(anfang->name, n);
      strcpy(anfang->vorname, v);
      anfang->alter.tag = at;
      anfang->alter.monat = am;
      anfang->alter.jahr = aj;
      anfang->eingest.tag = eint;
      anfang->eingest.monat = einm;
      anfang->eingest.jahr = einj;
      anfang->gehalt = g;
      /* Somit haben wir unseren Anfang der Liste. Von nun an
       * zeigt der Zeiger anfang immer auf das Element vor ihm.
       * Da dies aber jetzt das 1. Element der Liste war, zeigt 
       * der Zeiger anfang auf den Zeiger next. next zeigt am 
       * Ende immer wieder  NULL   */
      anfang->next=NULL;
   }
   /* Es scheint schon mindestens ein Element in der Liste
    * vorhanden zu sein, da der Anfang nicht == NULL ist. 
    * Jetzt suchen wir so lange nach dem nächsten Element, 
    * bis der *next-Zeiger auf NULL zeigt. Somit haben wir 
    * das Ende der Liste gefunden und können einen neuen 
    * Datensatz anhängen  */
   else {
      zeiger=anfang; /* Wir zeigen auf das 1. Element */
      while(zeiger->next != NULL)
         zeiger=zeiger->next;
      /* Wir reservieren einen Speicherplatz für das letzte
       * Element der Liste und hängen es an.   */
      if((zeiger->next =
       malloc(sizeof(struct angestellt))) == NULL) {
          fprintf(stderr,"Kein Speicherplatz für das "
                         "letzte Element\n");
          return;
      } 
      zeiger=zeiger->next; /* zeiger auf neuen Speicherplatz */
      strcpy(zeiger->name,n);
      strcpy(zeiger->vorname,v);
      zeiger->alter.tag=at;
      zeiger->alter.monat=am;
      zeiger->alter.jahr=aj;
      zeiger->eingest.tag=eint;
      zeiger->eingest.monat=einm;
      zeiger->eingest.jahr=einj;
      /* Wir terminieren wieder unsere Datenstruktur */
      zeiger->gehalt=g;   
      zeiger->next=NULL;
   }
}

/* Funktion zur Eingabe der Daten */
void eingabe(void) {
   char nam[MAX],vorn[MAX];
   int atag,amon,ajahr,eintag,einmon,einjahr;
   long gehalt;
 
   printf("Name........................: ");
   fgets(nam, MAX, stdin);
   printf("Vorname.....................: ");
   fgets(vorn, MAX, stdin);
   printf("Alter...........(tt.mm.jjjj): ");
   scanf("%2d.%2d.%4d",&atag,&amon,&ajahr);
   printf("Eingestellt am..(tt.mm.jjjj): ");
   scanf("%2d.%2d.%4d",&eintag,&einmon,&einjahr);
   printf("Monatsgehalt................: ");
   scanf("%ld",&gehalt);
   getchar();
   /* Eingegebenen Datensatz hinten anhängen */
   anhaengen(nam, vorn, atag, amon, ajahr, eintag,
    einmon, einjahr, gehalt);
}

int main(void) {
   while(1)
      eingabe();
   return EXIT_SUCCESS;
}

