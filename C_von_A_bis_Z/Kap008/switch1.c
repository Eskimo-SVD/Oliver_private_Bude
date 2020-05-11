/* switch1.c */
#include <stdio.h>

int main(void) {
   int a;
   printf("Bitte eine Zahl von 1-5 eingeben: ");
   scanf("%d", &a); 

   switch(a) {
      case 1: printf("Das war eins \n");
              break;
      case 2: printf("Das war zwei \n"); 
              break;
      case 3: printf("Das war drei \n");
              break;
      case 4: printf("Das war vier \n"); 
              break; 
      case 5: printf("Das war fünf \n");
              break;
      }      /* Ende switch */
   return 0;
}

