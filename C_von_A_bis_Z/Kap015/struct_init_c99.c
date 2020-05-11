/* struct_init_c99.c */
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
void ausgabe(struct adres x) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s\n",   x.vname);
   printf("Nachname........:%s\n",   x.nname);
   printf("Postleitzahl....:%ld\n",x.PLZ);
   printf("Ort.............:%s\n",   x.ort);
   printf("Geburtsjahr.....:%d\n", x.geburtsjahr);
}

int main(void) {
   struct adres adressen1 = {
      "Jürgen",
      "Wolf",
      .ort   = "Mering"
   };
   struct adres adressen2 = {
      .ort   = "Mering",
      .PLZ   = 1234,
      .nname = "Wolf",
   };
   struct adres adressen3 = {
      .PLZ    = 1234,
      "Mering",
      1974  
   };

   ausgabe(adressen1);
   ausgabe(adressen2);
   ausgabe(adressen3);
   return EXIT_SUCCESS;
}

