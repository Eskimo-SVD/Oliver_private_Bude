/* array13.c */
#include <stdio.h>
#include <stdlib.h>

/* Bilanz aus 5 Spielen */
#define SPIELE 5
#define WIN    3
#define LOSE   0
#define REMIS  1

/* Alle Elemente mit 0 initialisieren */
int Bayern[SPIELE]  = { 0 };
int Borussia[SPIELE]= { 0 };

/* Funktion zum Zaehlen der Punkte */
void punkte(int bm[], int bd[], int count) {
   if(bm[count] > bd[count]) {
      bm[count] = WIN;  /* 3 Punkte für Bayern */
      bd[count] = LOSE;
   }
   else if(bm[count] < bd[count]) {
      bm[count] = LOSE; 
      bd[count] = WIN;  /* 3 Punkte für Borussia */
   }
   else if(bm[count] == bd[count]) {
      bm[count] = REMIS; /* 1Punkt für jeden - Unentschieden */
      bd[count] = REMIS;
   }
}

int main(void) {
   unsigned int tor1, tor2;
   unsigned int tmptor1 = 0, tmptor2 = 0;
   unsigned int punkte_bay = 0, punkte_bor = 0;
   unsigned int count=0;        /* Indexzaehler */

   /* Eingabe des Anwenders */
   printf("Eingabe der letzten %d Spiele\n", SPIELE);

   while(count != SPIELE) {
         printf("%d. Spiel : Bayern - Borrusia\n", count+1);
         printf("Tor(e) Bayern   : ");
         scanf("%2u", &tor1);
         Bayern[count] = tor1;
         printf("Tor(e) Borussia : ");
         scanf("%2u", &tor2);
         Borussia[count] = tor2;

         tmptor1 += tor1;         /*Tore zaehlen Bayern*/
         tmptor2 += tor2;         /*Tore zaehlen Borussia*/
         /* Werte an Funktion punkte() uebergeben */
         punkte(Bayern, Borussia, count); 

         /* Punkte zaehlen */    
         punkte_bay += Bayern[count];
         punkte_bor += Borussia[count];
         /* Nächstes Spiel */
         count++;
   }
   /* Ausgabe der Statistik */
   printf("\n\nStatistik der letzten %d Spiele\n\n", SPIELE);
   printf("Bayern - Borussia\n");
   printf("Punkte : %2d : %2d\n", punkte_bay, punkte_bor);
   printf("Tore   : %2d : %2d\n", tmptor1, tmptor2);
   return EXIT_SUCCESS;
}

