// Programm 6.5 größte Abweichung.cpp: Hauptprojektdatei.
// Programm zur Ermittlung von Mittelwert, Maximums, Minimum
// und der größten Abweichung vom Mittelwert von Messwerten
// Autor: Heiderich / Meyer
// ----------------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
using namespace System;
void main()
{
   int n, i;
   float sp, pmittel, p, pmax, pmin, gab;
   //                   ö            ß            ä            ü
   char weiter, c1 = '\x94', c2 = '\xE1', c3 = '\x84', c4 = '\x81';
   // Begrüßung
   printf("\n\nProgramm zur Ermittlung von Mittelwert, Maximum, Minimum\n");
   printf("und der gr%c%cten Abweichung vom Mittelwert von Messwerten\n",c1,c2);
   printf("--------------------------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      // Anzahl Messwerte
	  printf("\nBitte geben Sie die Anzahl der Messwerte ein: --> ");
      fflush(stdin);
      scanf("%i",&n);
	  // Initialisierungen
	  sp = 0.0;
	  pmax = 0.0;
	  pmin = 10000.0;
	  printf("\n"); // Leerzeile
	  // Schleife über die Anzahl der Messwerte
	  // mit Summenbildung, ermittlung von Maximum und Minimum
	  for (i = 1; i <= n; i++)
	  {
		 printf("Bitte geben Sie den %3i.Messwerte ein: --> ",i);
         fflush(stdin);
         scanf("%f",&p);
		 sp += p;
		 if (p > pmax) pmax = p;
		 if (p < pmin) pmin = p;
	  }
      // Berechnung Mittelwert
	  pmittel = sp / n;
	  // maximale Abweichung
	  if (pmittel-pmin > pmax -pmittel)
	  {
		  gab = pmittel - pmin;
	  }
	  else
	  {
		  gab = pmax - pmittel;
	  }
	  // Ausgabe
	  printf("\nErgebnisse:\n");
	  printf("-----------\n\n");
	  printf("Mittelwert . . . . . . . . . . . : %6.2f\n",pmittel);
	  printf("Maximum  . . . . . . . . . . . . : %6.2f\n",pmax);
	  printf("Minimum  . . . . . . . . . . . . : %6.2f\n",pmin);
	  printf("gr%c%cte Abweichung vom Mittelwert : %6.2f\n",c1,c2,gab);
	  printf("\nM%cchten Sie eine weitere Berechnung durchf%chren?\n",c1,c4);
      printf("(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}