// Programm934.cpp: Hauptprojektdatei.
// Erstellung einer Wahrheitstabelle für das
// Problem Q = (A || !B) && C
// Eingabe: Anzahl der Zustände (hier 3)
// Ausgabe: Wahrheitstabelle
// Autor: Heiderich / Meyer
// ------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "dualtabelle.h" 
#include "q.h"
using namespace System;
void main()
{
   int anz;           // Anzahl der Eingänge
   short int a;       // Wert Eingang A
   short int b;       // Wert Eingang B
   short int c;       // Wert Eingang C
   int anz_zeile;     // Anzahl der Zeilen im Array
   int anz_spalte;    // Anzahl der Spalten im Array
   int i;             // Hilfsvariable
   short int ** dual; // zweidimensionales Array der Dualzahlen
   // Begrüßung
   printf("\n\n\tProgramm zur Erstellung einer Wahrheitstabelle\n");
   printf("\t     f%cr das Problem \"Q = (A || !B) && C\"\n",char(129));
   printf("\t----------------------------------------------\n");
   // Anzahl der Eingänge setzen
   anz = 3;
   // dynamisches Allocieren eines zweidimensionalen Arrays
   anz_zeile  = (int)pow(2.,anz) + 1;
   anz_spalte = anz + 1;
   dual = (short int **)malloc(anz_zeile * sizeof(short int *));
   if (dual == NULL)
   {
      printf("Kein RAM mehr vorhanden ... !");
      getch();
	  exit(0);
   }
   for(i = 0; i < anz_zeile; i++) 
   {
      dual[i] = (short int *)malloc(anz_spalte * sizeof(short int));
      if (dual[i] == NULL) 
	  {
         printf("Kein RAM mehr f%cr Zeile %d\n",char(129),i);
         getch();
		 exit(0);
      }
   }
   // Aufruf der Belegungsfunktion für die Dualzahlentabelle
   dualtabelle(anz,dual);
   // Ausgabe der Tabelle
   printf("\n\t A B C | Q\n");
   printf("\t-------+---\n");
   for (i = 1; i <= pow(2.,anz); i++)
   {
	   // Belegung der Eingänge aus der Dualzahlentabelle
	   a = dual[i][1];
	   b = dual[i][2];
	   c = dual[i][3];
	   // Ausgabe
	   printf("\t %1i %1i %1i | %1i\n",a,b,c,q(a,b,c));
   }
   getch();
}