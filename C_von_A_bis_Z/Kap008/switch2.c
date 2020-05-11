/* switch2.c */
#include <stdio.h>

int main(void) {
   int a;
   printf("Bitte eine Zahl von 1-5 eingeben: ");
   scanf("%d", &a); 

   switch(a) {
      case 1: printf("Das war Eins oder...");
      case 2: printf("...Zwei \n"); 
              break;
      case 3: printf("Das war Drei \n");
              break;
      case 4: printf("Das war Vier..."); 
      case 5: printf("...oder Fünf \n");
              break;
      }      /* Ende switch */
   return 0;
}

