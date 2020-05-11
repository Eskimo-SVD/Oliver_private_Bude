/* while2.c */
#include <stdio.h>

int main(void) {
   int zahl, summe=0;
   printf("Summenberechnung\nBeenden der Eingabe mit 0 \n");

   while(1) {    /* Endlosschleife, weil: 1 ist immer wahr */
      printf("Bitte Wert eingeben > ");
      scanf("%d", &zahl);
      if(zahl == 0)    /*  Haben wir 0 eingegeben ...?   */
         break;        /* ... dann raus aus der Schleife */
      else
         summe+=zahl;
   }
   printf("Die Summe aller Werte beträgt: %d\n", summe);
   return 0;
}

