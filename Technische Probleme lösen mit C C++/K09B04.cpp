// Programm 932.cpp: Hauptprojektdatei.
// Auswertung von "Q = ( A oder !B) und C"
// Q wird hier als Funktion implementiert
// Autor: Heiderich / Meyer
// ---------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Prototyp der Funktion q()
short int q(short int, short int, short int);
using namespace System;
void main()
{
   short int ina; // Eingang A
   short int inb; // Eingang B
   short int inc; // Eingang C
   printf("\n\tQ = (A || !B) && C:\n");
   printf("\t-------------------\n\n");
   printf("\t A B C | Q\n");
   printf("\t-------+---\n");
   for (inc = 0; inc <= 1; inc++)
   {
      for (inb = 0; inb <= 1; inb++)
      {
         for (ina = 0; ina <= 1; ina++)
         {
            printf("\t %1i %1i %1i | %1i\n",ina,inb,inc,q(ina,inb,inc));
         }
      }
   }
   getch();
}
short int q(short int a, short int b, short int c)
{
   return ((a || !b) && c);
}