#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
// "dual" ist Zeiger auf short int-Zeiger 
// daher kann mit "normalen" Indizes auf die Zeilen
// und Spalten des zweidimensionalen Arrays "gezeigt"
// werden (also wie bei einer zweidimensionalen Matrix)
// Die Felder werden in Zeilenrichtung von 1 bis 2^n
// und in Spaltenrichtung von 1 bis n belegt um später
// keine Indextransformation durchführen zu müssen!
void dualtabelle(int anz, short int** dual)
{
   int anz_zeile;  // Anzahl der Zeilen im Array
   int i, j, k;    // Hilfsvariablen
   anz_zeile  = (int)pow(2.,anz);
   float s = 0.5;
   i = 0;
   for (j = anz; j >= 1; j--) // Schliefe über Spalten
   {
	   s*=2.;
	   do                     // Schleife über Zeilen
	   {
		   for (k = 1; k <=s; k++)
	       {
		      i++;
			  dual[i][j] = 0;
	       }
	       for (k = 1; k <= s; k++)
	       {
			  i++;
		      dual[i][j] = 1;
	       }
	   } while (i < anz_zeile);
	   i = 0;
   }
}