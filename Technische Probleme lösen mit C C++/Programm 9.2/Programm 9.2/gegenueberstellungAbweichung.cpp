// Funktion zur Ausgabe der Abweichungen
// Autor: Heiderich / Meyer
// -------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
void gegenueberstellungAbweichung(float x[], float y[], int anz, float m, float b)
{
	float sx2  = 0.0; // Summe xi*xi
	float sx   = 0.0; // Summe über xi
	float sv2  = 0.0; // Summe über vi*vi 
	float delta_m;    // mittlerer Fehler von m
	float delta_b;    // mittlerer Fehler von b
	int i;
	for (i = 0; i < anz; i++)
	{
       sx2  = sx2 + x[i] * x[i];
	   sx   = sx  + x[i];
	   sv2  = sv2 + pow((y[i] - (m * x[i] + b)),2);
	}
	delta_b = sqrt( (sx2*sv2) / ((anz - 2) * anz * sx2 - (anz - 2)* sx * sx) ); 
	delta_m = sqrt( anz * sv2 / (anz * sx2 - sx * sx) );
	// Ausgabe der mittleren Fehler:
	printf("\n\n\tdie Abweichungen betragen zu den %2i Koordinatenpaaren betragen:",anz);
	printf("\n\n\tdelta_m  = %f\n",delta_m);
    printf("\tdelta_b  = %f\n",delta_b);
	printf("\n\tFehlerquadratsumme = %f",sv2);
	getch();
}