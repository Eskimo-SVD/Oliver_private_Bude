/* red_memory.c */
#include <stdio.h>
#include <stdlib.h>
#define MIN_LEN 256

int main(void) {
   int *ptr;
   char jn;
   static size_t len = 8192;  /* Speicheranforderung */

   do {
      ptr = malloc(len);
      /* Speicher konnte nicht alloziert werden */
      if(ptr == NULL) {
         len /= 2;  /* Versuchen wir es mit der Hälfte */
         ptr = malloc(len);
         if(ptr == NULL) {
            printf("Konnte keinen Speicher allozieren. "
                   " Weiter versuchen? (j/n): ");
            scanf("%c", &jn);
            fflush(stdin);
         }
      }
      else
         /* Erfolg. Speicherreservierung - Schleifenende */
         break; 
   /* So lange weiterprobieren, bis 'n' gedrückt wurde oder
    * len weniger als MIN_LEN beträgt */
   } while(jn != 'n' && len > MIN_LEN); 

   if(len <= MIN_LEN)
      printf("Speicherandforderung abgebrochen!!\n");
   return EXIT_SUCCESS;
}

