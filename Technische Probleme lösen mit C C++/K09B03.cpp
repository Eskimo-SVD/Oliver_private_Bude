// Programm 931.cpp: Hauptprojektdatei.
// Programm zum Testen logischer Verknüpfungen
// Autor: Heiderich / Meyer
// -------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace System;
void main()
{
   short int ina; // Eingang A
   short int inb; // Eingang B
   short int q;   // Ausgang Q
   printf("\n\tDarstellung der \"und\"-Verkn%cpfung:\n",char(129));
   printf("\t----------------------------------\n\n");
   printf("\t A B | Q\n");
   printf("\t-----+---\n");
   for (ina = 0; ina <= 1; ina++)
   {
      for (inb = 0; inb <=1; inb++)
      {
         q = ina && inb;
         printf("\t %1i %1i | %1i\n",ina,inb,q);
      }
   }
   printf("\n\tDarstellung der \"oder\"-Verkn%cpfung:\n",char(129));
   printf("\t-----------------------------------\n\n");
   printf("\t A B | Q\n");
   printf("\t-----+---\n");
   for (ina = 0; ina <= 1; ina++)
   {
      for (inb = 0; inb <=1; inb++)
      {
         q = ina || inb;
         printf("\t %1i %1i | %1i\n",ina,inb,q);
      }
   }
   printf("\n\tDarstellung der Negation:\n");
   printf("\t-------------------------\n\n");
   printf("\t E | Q\n");
   printf("\t---+---\n");
   for (ina = 0; ina <= 1; ina++)
   {
      q = !ina;
      printf("\t %1i | %1i\n",ina,q);
   }
   getch();
}