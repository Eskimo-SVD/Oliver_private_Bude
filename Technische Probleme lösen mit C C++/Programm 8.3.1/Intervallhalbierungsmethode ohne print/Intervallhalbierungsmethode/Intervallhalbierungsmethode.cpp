// Programm 8.3.1 Intervallhalbierungsmethode.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Nullstellen
// nach dem Intervallhalbierungsverfahren
// Autor: Heiderich / Meyer
// ------------------------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "signum.h"
#include "f.h"
#include <math.h>
using namespace System;
void main()
{
	float xu, xo, epsilon, xm;
	int vz, aus = 1;
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Nullstellen\n");
	printf("\tnach dem Intervallhalbierungs-Verfahren\n");
    printf("\t---------------------------------------\n");
    // Eingabe der Intervallgrenzen und der Genauigkeit
	printf("\n\tBitte geben Sie die untere Intervallgrenze      xu an: ");
	fflush(stdin);
	scanf("%f",&xu);
	printf("\n\tBitte geben Sie die obere  Intervallgrenze      xo an: ");
	fflush(stdin);
	scanf("%f",&xo);
	printf("\n\tBitte geben Sie die gew%cnschte Genauigkeit epsilon an: ",char(129));
	fflush(stdin);
	scanf("%f",&epsilon);
	printf("\n");
	do
	{
		xm = ( xo + xu ) / 2.;
		if ( signum( f(xm,aus) ) == signum ( f(xu,aus) ) ) xu = xm;
		else                                               xo = xm;
	} while ( abs(xu-xo) > epsilon || f(xm,aus) == 0.0);
	// Ausgabe Ergebnisse
	printf("\n\tdie Funktion besitzt eine Nullstelle zwischen\n");
	printf("\txu = %f   und   xo = %f\n",xu,xo);
	getch();
}