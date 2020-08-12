// Programm933.cpp: Hauptprojektdatei.
// Erstellung einer Tabelle mit Dualzahlen
// Eingabe: Anzahl der Zustände
// Ausgabe: Tabelle der Dualzahlen
// Autor: Heiderich / Meyer
// ----------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "dualtabelle.h" 
using namespace System;
void main()
{
   int anz;        // Anzahl der Eingänge
   int anz_zeile;  // Anzahl der Zeilen im Array
   int anz_spalte; // Anzahl der Spalten im Array
   int i, j;       // Hilfsvariablen
   // Begrüßung
   printf("\n\n\tProgramm zur Erstellung einer Tabelle\n");
   printf("\t   von Dualzahlen f%cr \"n\" Eing%cnge\n",char(129),char(132));
   printf("\t-------------------------------------\n");
   // Eingabe der Anzahl der Eingänge
   printf("\n\tBitte geben Sie die Anzahl der Eing%cnge an: ",char(132));
   fflush(stdin);
   scanf("%i",&anz);
   // dynamisches Allocieren eines zweidimensionalen Arrays
   // mit 2^n Zeilen
   // und n   Spalten
   // Vorsicht: so erhält die erste Zeile den Index "0"
   //           und die erste Spalte ebenfalls den Index "0"
   // besser hier:
   // dynamisches Allocieren eines zweidimensionalen Arrays
   // mit 2^n + 1 Zeilen
   // und n + 1   Spalten
   anz_zeile  = (int)pow(2.,anz) + 1;
   anz_spalte = anz + 1;
   /* "dual" ist Zeiger auf short int-Zeiger */
   short int ** dual;
   /* Speicher reservieren für die short int-Zeiger (=zeile) */
   dual = (short int **)malloc(anz_zeile * sizeof(short int *));
   if (NULL == dual) {
      printf("Kein Virtueller RAM mehr vorhanden ... !");
      getch();
	  exit(0);
   }
   /* Jetzt noch Speicher reservieren für die einzelnen Spalten
    * der i-ten Zeile */
   for(i = 0; i < anz_zeile; i++) 
   {
      dual[i] = (short int *)malloc(anz_spalte * sizeof(short int));
      if (NULL == dual[i]) 
	  {
         printf("Kein Speicher mehr f%cr Zeile %d\n",char(129),i);
         getch();
		 exit(0);
      }
   }
   // Aufruf der Belegungsfunktion
   // Übergabeparamter: Anzahl Eingänge, zweidimensionales Array
   dualtabelle(anz,dual);
   // Ausgabe der Tabelle
   for (i = 1; i <= pow(2.,anz); i++)
   {
	   printf("\n\t");
	   for (j = 1; j <= anz; j++)
	   {
		   printf(" %1i ",dual[i][j] );
	   }
   }
   getch();
}