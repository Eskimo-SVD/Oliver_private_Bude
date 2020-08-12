// Programm 6.1.cpp: Hauptprojektdatei.
// Programm zur Umrechnung von Temperaturen
// °C <==> °F <==> K
// Autor: Heiderich / Meyer
// ----------------------------------------
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
using namespace System;
void main()
{
   // Deklarationen
   float tempEin, tempAus;   // Temperaturen
   int systemEin, systemAus; // Temperatursysteme
   int rechnung; // Seuerungsvariable für die Berechnung
   char antwort; // Steuerungsvariable für eine Wiederholung
   // Begrüssung
   printf("\n\nProgramm zur Umrechnung von Temperaturen\n");
   printf("----------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      // Eingabefehler abfangen, Abfrage wird wiederholt bis zur
      // gültigen Eingabe eines Einheitensystems
      do
	  {
	     printf("\naus welchem Einheitensystem soll umgerechnet werden?\n\n");
		 // 0xF8 stellt das Grad-Zeichen hexadezimal aus der ASCII-Tabelle dar!
	     printf("1: \xF8\C     2: \xF8\F     3: K\n\n");
	     printf("Ihre Wahl: ");
		 fflush(stdin);
	     scanf("%i",&systemEin);
	  } while (systemEin != 1 && systemEin != 2 && systemEin != 3);
	  // Eingabe der Temperatur
	  printf("\nbitte geben Sie die umzurechnende Temperatur an: ");
	  fflush(stdin);
	  scanf("%f",&tempEin);
	  // Eingabe Zielsystem
	  printf("\nin welches Einheitensystem soll umgerechnet werden?\n\n");
	  switch(systemEin)
	  {
	     case 1: printf("2: \xF8\F     3: K\n\n");
			     break;
		 case 2: printf("1: \xF8\C     3: K\n\n");
			     break;
		 case 3: printf("1: \xF8\C     2: \xF8\F\n\n");
	  }
	  do
	  {
		 printf("Ihre Wahl: ");
	     fflush(stdin);
	     scanf("%i",&systemAus);
	     // Plausibilitätsprüfung !
	  } while ((systemEin == 1 && systemAus != 2 && systemAus != 3) ||
		       (systemEin == 2 && systemAus != 1 && systemAus != 3) ||
			   (systemEin == 3 && systemAus != 1 && systemAus != 2));
      // Umrechnung und Ausgabe
	  // Steuerungsvariable Berechnung
	  rechnung = systemEin * 10 + systemAus;
	  switch(rechnung)
	  {
	     // °C ==> °F
	     case 12: tempAus = tempEin * 1.8 + 32.0;
			      printf("\n\n%.2f\xF8\C = %.2f\xF8\F\n\n",tempEin,tempAus);
			      break;
		 // °C ==> K
		 case 13: tempAus = tempEin + 273.15;
			      printf("\n\n%.2f\xF8\C = %.2fK\n\n",tempEin,tempAus);
			      break; 
		 // °F ==> °C
		 case 21: tempAus = (tempEin - 32.0) * 5.0 / 9.0;
			      printf("\n\n%.2f\xF8\F = %.2f\xF8\C\n\n",tempEin,tempAus);
			      break;
		 // °F ==> K
		 case 23: tempAus = (tempEin + 459.67) * 5.0 / 9.0;
			      printf("\n\n%.2f\xF8\F = %.2fK\n\n",tempEin,tempAus);
			      break;
		 // K ==> °C
		 case 31: tempAus = tempEin - 273.15;
			      printf("\n\n%.2fK = %.2f\xF8\C\n\n",tempEin,tempAus);
			      break;
		 // K ==> °F
		 case 32: tempAus = tempEin * 1.8 - 459.67;
			      printf("\n\n%.2fK = %.2f\xF8\F\n\n",tempEin,tempAus);
	  }
      // Wiederholung gewünscht?
      printf("\n\nerneute Berechnung? (j/n)");
	  fflush(stdin);
	  scanf("%c",&antwort);
   } while(antwort == 'j' || antwort == 'J');
}