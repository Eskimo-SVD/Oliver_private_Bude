// Programm 6.5 Minimum.cpp: Hauptprojektdatei.
// Programm zur Ermittlung des Minimums von Messwerten
// Autor: Heiderich / Meyer
// ---------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
using namespace System;
void main()
{
   int n, i;
   float pmin, p;
   char weiter, c1 = '\x84', c2 = '\x94', c3 = '\x81';
   // Begrüßung
   printf("\n\nProgramm zur Ermittlung des Minimums von Messwerten\n");
   printf("---------------------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      // Anzahl Messwerte
	  printf("\nBitte geben Sie die Anzahl der Messwerte ein: --> ");
      fflush(stdin);
      scanf("%i",&n);
	  // Initialisierung Minimalwert
	  pmin = 10000.0;
	  printf("\n"); // Leerzeile
	  // Schleife über die Anzahl der Messwerte
	  for (i = 1; i <= n; i++)
	  {
		 printf("Bitte geben Sie den %3i.Messwerte ein: --> ",i);
         fflush(stdin);
         scanf("%f",&p);
	     if (p < pmin) pmin = p;	 
	  }
      // Ausgabe
	  printf("\nDas Minimum der eingegebenen Messwerte betr%cgt: %f\n",c1,pmin);
	  printf("\nM%cchten Sie eine weitere Berechnung durchf%chren?\n",c2,c3);
      printf("(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}