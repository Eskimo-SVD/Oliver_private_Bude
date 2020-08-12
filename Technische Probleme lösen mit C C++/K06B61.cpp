// Programm 6.6.1.cpp: Hauptprojektdatei.
// Ermittlung der Anzahl der Dekaden bei logarithmischer Achsenteilung
// Autor: Heiderich/Meyer
// -------------------------------------------------------------------
#include "stdafx.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
#include "stdio.h"

using namespace System;

void main()
{
   float wert_oben, wert_unten;
   char weiter, c1 = '\x9a', c2 = '\x81', c3 = '\x94', c4 = '\xE1';
   int od, ud, dk;
   // Begrüßung
   printf("\n\n\tProgramm zur %cberpr%cfung logarithmischer Teilungen\n",c1,c2);
   printf("\t--------------------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      printf("\n\tBitte geben Sie den oberen Wert an:  ");
	  fflush(stdin);
      scanf("%f",&wert_oben);
	  printf("\tBitte geben Sie den unteren Wert an: ");
	  fflush(stdin);
      scanf("%f",&wert_unten);
	  // Ermittlung der oberen Dekade
	  od = log10(wert_oben) + 1;
	  // Ermittlung der unteren Dekade
	  ud = log10(wert_unten);
	  // Anzahl der Dekaden
	  dk = od - ud;
	  // Ausgabe
	  printf("\n\tgr%c%cere Dekade    : %i",c3,c4,(int)pow(10.,od));
	  printf("\n\tkleinere Dekade   : %i",(int)pow(10.,ud));
	  printf("\n\tAnzahl der Dekaden: %i\n",dk);
      printf("\n\tM%cchten Sie eine weitere %cberpr%cfung durchf%chren?\n",c3,c1,c2,c2);
      printf("\t(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}