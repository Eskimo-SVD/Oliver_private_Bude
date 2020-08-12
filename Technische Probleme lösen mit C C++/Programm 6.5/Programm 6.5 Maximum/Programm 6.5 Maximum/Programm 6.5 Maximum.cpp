// Programm 6.5 Maximum.cpp: Hauptprojektdatei.
// Programm zur Ermittlung des Maximums von Messwerten
// Autor: Heiderich / Meyer
// ---------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
using namespace System;
void main()
{
   int n, i;
   float pmax, p;
   char weiter, c1 = '\x84', c2 = '\x94', c3 = '\x81';
   // Begrüßung
   printf("\n\nProgramm zur Ermittlung des Maximums von Messwerten\n");
   printf("---------------------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      // Anzahl Messwerte
	  printf("\nBitte geben Sie die Anzahl der Messwerte ein: --> ");
      fflush(stdin);
      scanf("%i",&n);
	  // Initialisierung Maximalwert
	  pmax = 0.0;
	  printf("\n"); // Leerzeile
	  // Schleife über die Anzahl der Messwerte
	  for (i = 1; i <= n; i++)
	  {
		 printf("Bitte geben Sie den %3i.Messwerte ein: --> ",i);
         fflush(stdin);
         scanf("%f",&p);
	     if (p > pmax) pmax = p;	 
	  }
      // Ausgabe
	  printf("\nDas Maximum der eingegebenen Messwerte betr%cgt: %f\n",c1,pmax);
	  printf("\nM%cchten Sie eine weitere Berechnung durchf%chren?\n",c2,c3);
      printf("(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}