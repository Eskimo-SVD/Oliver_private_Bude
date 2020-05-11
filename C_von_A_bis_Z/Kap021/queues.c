/* queues.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct reservierung {
   char name[MAX];
   char vorname[MAX];
   int rnummer;
   struct reservierung *previous;
};

struct reservierung *dummy;
static int nummer = 1;

int schlange_init(void) {
   if((dummy = malloc(sizeof(struct reservierung))) != NULL)  {
      strcpy(dummy->name,"dummy");
      strcpy(dummy->vorname,"dummy");
      dummy->rnummer=0;
      dummy->previous=NULL;
      return 1;
   }
   else {
      fprintf(stderr,"Konnte keinen Speicher reservieren!!\n");
      return 0;
   }
}

/* Wir hängen ein neues Element an das Ende der Schlange */
int put(struct reservierung *neu) {
   struct reservierung *zeiger;

   /* Ist es das 1. Element in der Schlange? */
   if(dummy->previous == NULL) { /* Es ist das 1. Element */
      dummy->previous=neu;
      neu->previous=NULL;
      return 1;
   }
   /* Es ist nicht das 1. Element */
   else {
      zeiger=dummy;
      /* Wir suchen das Ende der Schlange */
      while(zeiger->previous != NULL)
         zeiger=zeiger->previous;
      zeiger->previous=neu;
      neu->previous=NULL;
      return 1;
   }
}

/* Wir benötigen das 1. Element der Liste, das wir auch als 1. 
 * eingegeben haben  */
void get(void) {
   struct reservierung *zeiger;

   /* Ist überhaupt etwas in der Schlange? */
   if(dummy->previous != NULL) { /* Es ist...! */
      zeiger=dummy->previous;
      dummy->previous=zeiger->previous;
      free(zeiger);
   }
   else
      fprintf(stderr,"Es sind keine Patienten "
                     "im Wartezimmer.....\n");
}

void eingabe(void) {
   struct reservierung *neu;
   char n[MAX],vn[MAX];

   if((neu=(struct reservierung *)
     malloc(sizeof(struct reservierung))) != NULL) {
      printf("Name.....: ");
      fgets(n, MAX, stdin);   
      strcpy(neu->name, strtok(n,"\n"));
      printf("Vorname..: ");
      fgets(vn, MAX, stdin);
      strcpy(neu->vorname,strtok(vn,"\n"));
      printf("Nummer...: ");
      printf("%d\n",neu->rnummer = nummer++);
      neu->previous=NULL;
      put(neu);
   }
}

void ausgabe(void) {
   if(dummy->previous != NULL) {
      printf("\n%s, %s Nummer.: %d \n\n",
      dummy->previous->name,dummy->previous->vorname,
      dummy->previous->rnummer);
      get();
   }
   else
      printf("Keine Patienten im Wartezimmer vorhanden!!!\n");
}

int main(void) {
   int wahl;

   schlange_init();
   do {
      printf("-1- Reservierung eingeben\n");
      printf("-2- Nächster Patient\n");
      printf("-3- Programmende\n\n");
      printf("Ihre Wahl : ");
      scanf("%d",&wahl);
      getchar();
      switch(wahl) {
         case 1  : eingabe();
                   break;
         case 2  : ausgabe();
                   break;
         case 3  : if(dummy->previous != NULL) {
                      printf("Es sind noch Patienten"
                             " im Wartezimmer!!!\n");
                      wahl = 4; /* Abhauen gilt nicht */
                   }
                   break;
         case 4  : break;
         default : printf("Falsche Eingabe!!\n\n");
      }
   } while(wahl != 3);
   printf("\n\nFeierabend\n");
   return EXIT_SUCCESS;
}

