/* 8dame.c */
#include <stdio.h>
#include <stdlib.h>

int dame_in_gefahr(int *schachbrett) {
   /* x==nach unten; y==nach rechts */
   int x,y; 
   for(x=0; x<7; x++)
      /* Ist auf feld[x] eine Dame? */
      if(schachbrett[x]) 
      for(y=x+1; y<=7; y++)
         /* Ist auf feld[y] eine Dame? */
         if(schachbrett[y])  {
            /* Wir überprüfen ob sich die beiden 
             * Damen kollidieren? */
            /* beide Damen in der selben Zeile? */
            if(schachbrett[x]==schachbrett[y])
               return 1; /* Kollision in gleicher Zeile */
            /* diagonal? */
            if(abs(x-y)==abs(schachbrett[x]-schachbrett[y]))
              return 2; /* Kollision in der diagonalen */
         }
   return 0; /* kein Kollision! */
}

int dame(int *schachbrett, int position) {
   int x = 1, i;
   static int counter = 1;

   while(x <= 8) {
      /* Wir setzten die Dame mit der
       * Nummer x an feld[position] */
      schachbrett[position]=x;
      if(!dame_in_gefahr(schachbrett)) {
         if(position) {
            /* die nächste Dame */
            if(dame(schachbrett,position-1))
               return 1; /* Dame in dieser Position setzten */
         }
         else {
            printf("Loesungs-Nr.%2d : ", counter++);
            for(i=0; i<8; i++)
               printf("(%d,%d)", i+1, schachbrett[i]);
            printf("\n");
         }
      }
      x++;
   }
   schachbrett[position] = 0;
   return 0;
}

int main(void) {
   int schachbrett[8], x;
   
   for(x=0; x < 8; x++)
      schachbrett[x] = 0;
   dame(schachbrett,7);
   return EXIT_SUCCESS;
}

