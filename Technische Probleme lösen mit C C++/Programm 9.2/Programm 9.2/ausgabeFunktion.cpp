// Funktion zur Berechnung und
// zur Ausgabe der linearen Funktion
// Autor: Heiderich / Meyer
// ---------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void ausgabeFunktion(float x[], float y[], int anz, float* m, float* b)
{
	float sxy  = 0.0; // Summe xi*yi
	float sx2  = 0.0; // Summe xi*xi
	float sx   = 0.0; // Summe über xi
	float sy   = 0.0; // Summe über yi 
	float sxsy = 0.0; // Produkt der Summen über x und y
	int i;
	for (i = 0; i < anz; i++)
	{
       sxy  = sxy + x[i] * y[i];
	   sx2  = sx2 + x[i] * x[i];
	   sx   = sx  + x[i];
	   sy   = sy  + y[i];
	}
	*m = (anz * sxy - sx * sy) / (anz * sx2 - sx * sx); 
	*b = (sx2 * sy - sx * sxy) / (anz * sx2 - sx * sx);
	// Ausgabe der linearen Funktion
	printf("\n\n\tdie lineare Funktion zu den %2i Koordinatenpaaren lautet:",anz);
	printf("\n\n\t y = %f * x ",*m);
    if (*b >= 0.0) printf("+ %f",*b);
	else           printf("%f",*b);
	getch();
}