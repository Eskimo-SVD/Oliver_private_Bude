/* struct4.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct adres { 
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
};

/*Funktion zur Ausgabe des Satzes*/
void ausgabe(struct adres *struct_ptr) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s",struct_ptr->vname);
   printf("Nachname........:%s",struct_ptr->nname);
   printf("Postleitzahl....:%ld\n",struct_ptr->PLZ);
   printf("Ort.............:%s",struct_ptr->ort);
   printf("Geburtsjahr.....:%d\n",struct_ptr->geburtsjahr);
}

struct adres *eingabe(void) {
   static struct adres *adressen;
   adressen = malloc(sizeof(struct adres));
   printf("Vorname : ");
   fgets(adressen->vname, MAX, stdin);
   printf("Nachname : ");
   fgets(adressen->nname, MAX, stdin);
   printf("Postleitzahl : ");
   do {scanf("%ld",&adressen->PLZ);} while(getchar()!= '\n');
   printf("Wohnort : ");
   fgets(adressen->ort, MAX, stdin);
   printf("Geburtsjahr : ");
   do {
      scanf("%ld",&adressen->geburtsjahr);
   }while(getchar()!='\n' );
   return adressen;
}

int main(void) {
   struct adres *adresse1, *adresse2;

   adresse1=eingabe();
   adresse2=eingabe();

   ausgabe(adresse1);
   ausgabe(adresse2);
   return EXIT_SUCCESS;
}

