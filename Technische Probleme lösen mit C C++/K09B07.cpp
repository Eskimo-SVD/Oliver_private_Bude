// Programm935.cpp: Hauptprojektdatei.
// Erstellung einer Wahrheitstabelle für das Problem
// Q1 = (A&&B&&C)||(A&&!B&&!C)||(!A&&B&&!C)||(!A&&!B&&C)
// Q2 = (A&&B&&C)||(A&&B&&!C) ||(A&&!B&&C) ||(!A&&B&&!C)
// Eingabe: Anzahl der Zustände (hier 3)
// Ausgabe: Wahrheitstabelle für Q1 und Q2
// Autor: Heiderich / Meyer
// -----------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "dualtabelle.h"
#include "q1.h"
#include "q2.h"
using namespace System;
void main()
{
   int anzE;          // Anzahl der Eingänge
   int anzA;          // Anzahl der Eingänge
   short int a;       // Wert Eingang A
   short int b;       // Wert Eingang B
   short int c;       // Wert Eingang C
   int anz_zeile;     // Anzahl der Zeilen in den Arrays
   int anz_spalteE;   // Anzahl der Spalten im Array Eingänge
   int anz_spalteA;   // Anzahl der Spalten im Array Ausgänge
   int i;             // Hilfsvariable
   short int ** dual; // zweidimensionales Array der 3 Eingänge
   short int ** q;    // zweidimensionales Array der 2 Ausgänge
   // Begrüßung
   printf("\n\n\tProgramm zur Erstellung einer Wahrheitstabelle f%cr die Probleme\n",char(129));
   printf("\n\t\"Q1 = (A&&B&&C)||(A&&!B&&!C)||(!A&&B&&!C)||(!A&&!B&&C)\" und\n");
   printf("\n\t\"Q2 = (A&&B&&C)||(A&&B&&!C) ||(A&&!B&&C) ||(!A&&B&&C)\"\n");
   printf("\t---------------------------------------------------------------\n");
   // Anzahl der Eingänge setzen
   anzE = 3;
   // Anzahl der Ausgänge setzen
   anzA = 2;
   // dynamisches Allocieren zweier zweidimensionaler Arrays
   anz_zeile   = (int)pow(2.,anzE) + 1;
   anz_spalteE = anzE + 1;
   anz_spalteA = anzA + 1;
   dual = (short int **)malloc(anz_zeile * sizeof(short int *));
   if (dual == NULL)
   {
      printf("Kein RAM mehr vorhanden f%cr dual ... !",char(129));
      getch();
      exit(0);
   }
   q = (short int **)malloc(anz_zeile * sizeof(short int *));
   if (q == NULL)
   {
      printf("Kein RAM mehr vorhanden f%cr  q  ... !",char(129));
      getch();
      exit(0);
   }
   for(i = 0; i < anz_zeile; i++)
   {
      dual[i] = (short int *)malloc(anz_spalteE*sizeof(short int));
      if (dual[i] == NULL)
      {
         printf("Kein RAM mehr f%cr Zeile %d von dual\n",char(129),i);
         getch();
         exit(0);
      }
      q[i] = (short int *)malloc(anz_spalteA * sizeof(short int));
      if (q[i] == NULL)
      {
         printf("Kein RAM mehr f%cr Zeile %d von q\n",char(129),i);
         getch();
         exit(0);
      }
   }
   // Aufruf der Belegungsfunktion für die Dualzahlentabelle
   dualtabelle(anzE,dual);
   // Erstellung der Wahrheitstabelle
   for (i = 1; i < anz_zeile; i++)
   {
   // Belegung der Eingänge aus der Dualzahlentabelle
   a = dual[i][1];
   b = dual[i][2];
   c = dual[i][3];
   // Ermittlung der Ausgänge
   q[i][1] = q1(a,b,c);
   q[i][2] = q2(a,b,c);
   }
   // Ausgabe der Tabelle
   printf("\n\t A B C | Q1 Q2\n");
   printf(  "\t-------+-------\n");
   for (i = 1; i < anz_zeile; i++)
   {
      printf("\t %1i %1i %1i | %1i  %1i\n",dual[i][1],dual[i][2],dual[i][3],q[i][1],q[i][2]);
   }
   getch();
}