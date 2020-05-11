/* realloc1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n=0, max=10, z,i;
   int *zahlen=NULL;

   /* Wir reservieren Speicher für 10 int-Werte mit calloc */
   zahlen = calloc(max, sizeof(int));
   if(NULL == zahlen) {
      printf("Kein Virtueller RAM mehr vorhanden ... !");
      return EXIT_FAILURE;
   }
   printf("Zahlen eingeben --- Beenden mit 0\n");
   /* Endlossschleife */
   while(1) {
      printf("Zahl (%d) eingeben : ", n+1);
      scanf("%d", &z);
      if(z==0)
         break;
      /* Reservierung von Speicher während der Laufzeit 
       * des Programms mit realloc */
       if(n >= max) {
          max += max;
          zahlen = realloc(zahlen,max*sizeof(int));
          if(NULL == zahlen) { 
             printf("Kein Virtueller RAM mehr vorhanden ... !");
             return EXIT_FAILURE; 
          }
          printf("Speicherplatz reserviert "
                 " (%d Bytes)\n", sizeof(int) * max);
       }
       zahlen[n++] = z;
   }
   printf("Folgende Zahlen wurden eingegeben ->\n\n");
   for(i = 0; i < n; i++)
      printf("%d ", zahlen[i]);
   printf("\n");
   free(zahlen);
   return EXIT_SUCCESS;
}

