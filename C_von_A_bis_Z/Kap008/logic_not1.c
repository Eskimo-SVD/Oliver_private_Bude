/* logic_not1.c */
#include <stdio.h>

int main(void) {
   int checknummer;

   printf("Bitte geben Sie Ihren Code-Schl�ssel ein: ");
   scanf("%d", &checknummer);

   if( ! (checknummer == 4711) ) {
      printf("Error - Falscher Code-Schl�ssel \n");
   }
   else {
      printf("Success -  Login erfolgreich \n");
    }
   return 0;
}

