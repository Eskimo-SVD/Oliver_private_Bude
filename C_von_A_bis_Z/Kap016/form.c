/* form.c */
#include <stdio.h>
#include <stdlib.h>
#define NUMITEMS 4

char *namen[4] = {
   "Jürgen", "Fatma", "Gismo", "Jonathan"
};

int main(void) {
   int schleife;
   char temp[4][80];
   char name[20];
   int alter;
   long lohn;

   /* Wir erstellen Namen, Alter und Gehalt. Alter und Gehalt 
    * werden durch Zufallszahlen erzeugt. Mit sprintf schreiben
    * wir die Daten formatiert int temp */
   for (schleife = 0; schleife < NUMITEMS; ++schleife)
      sprintf(temp[schleife], "%s %d %ld"
         ,namen[schleife], rand()%20+18, rand()+27500L);

   /* Wir erstellen eine Kopfzeile */
   printf("%4s | %-20s | %5s | %9s\n",
       "#","Name","Alter","Gehalt");
   printf(" ----------------------------------------"
          "----------\n");

   /* Mit sscanf lesen wir die Daten formatiert aus temp aus, 
    * dort wo wir zuvor mit sprintf die Daten formatiert 
    *  geschrieben haben */
   for (schleife=0; schleife < NUMITEMS; ++schleife) {
      sscanf(temp[schleife],"%s %d %ld",(char*)&name,&alter,&lohn);
      printf("%4d | %-20s | %5d | %9ld\n",
         schleife+1,name,alter,lohn);
   }
   return EXIT_SUCCESS;
}

