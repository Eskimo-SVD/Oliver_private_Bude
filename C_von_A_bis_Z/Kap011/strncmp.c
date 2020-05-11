/* strncmp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str1[] = "aaaa";
   char str2[] = "aabb";
   int i;

   for(i = strlen(str1); i > 0; i--) {
      if(strncmp( str1, str2, i) != 0)
         printf("Die ersten %d Zeichen der Strings "
                "sind nicht gleich\n",i);
         else {
            printf("Ab Zeichen %d sind "
                   "beide Strings gleich\n",i);
            /* Weiter vergleich sind nicht mehr nötig */
            break; 
         }
   }
   return EXIT_SUCCESS;
}

