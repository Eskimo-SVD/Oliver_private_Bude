/* logic_not1.c */
#include <stdio.h>

int main(void) {
   int checknummer;

   printf("Bitte geben Sie Ihren Code-Schlüssel ein: ");
   scanf("%d", &checknummer);

   if( ! (checknummer == 4711) ) {
      printf("Error - Falscher Code-Schlüssel \n");
   }
   else {
      printf("Success -  Login erfolgreich \n");
    }
   return 0;
}

