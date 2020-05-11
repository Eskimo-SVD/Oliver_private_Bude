/* struct5.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

struct adres { 
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
};
              
int cmp_structs(struct adres *str1, struct adres *str2) {
   /* Vorname gleich und */
   if(strcmp(str1->vname, str2->vname) == 0 &&
      /* Nachname gleich und */
      strcmp(str1->nname, str2->nname) == 0 &&
      /* Postleitzahl gleich und */
      (str1->PLZ-str2->PLZ) == 0 &&
      /* Wohnort gleich und */
      strcmp(str1->ort, str2->ort) == 0 &&
      /* geburtsjahr gleich */
      (str1->geburtsjahr-str2->geburtsjahr) == 0) 
         return 0;    /* Beide Strukturen gleich */
   else
      return 1;       /* Strukturen nicht gleich */
}

int main(void) {
   struct adres adresse1={"John","Leroy",1234,"New York",1980 };
   struct adres adresse2={"John","Leroy",1234,"New York",1980 };

   if(cmp_structs(&adresse1, &adresse2) == 0)
      printf("Beide Strukturen sind gleich?!?!\n");
   else
      printf("Die Strukturen weisen Unterschiede auf\n");
   return EXIT_SUCCESS;
}

