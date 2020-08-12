// Programm 8.3.1 Inkrementverfahren.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Nullstellen
// nach dem Inkrementverfahren
// Autor: Heiderich / Meyer
// ---------------------------------------------------------
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
	float xu, xo, epsilon, dx, x;
	int vz;
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Nullstellen\n");
	printf("\t     nach dem Inkrementverfahren\n");
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
		dx = ( xo - xu ) / 10.;
		vz = signum( f(xu) );
		x = xu;
		do
		{
			x += dx;
		} while ( vz == signum(f(x)) );
		xu = x - dx;
		xo = x;
		printf("\n\txu = %10.6f  xo = %10.6f\n\n",xu,xo);
	} while ( abs(xu-xo) > epsilon );
	// Ausgabe Ergebnisse
	printf("\n\tdie Funktion besitzt eine Nullstelle zwischen\n");
	printf("\txu = %f   und   xo = %f\n",xu,xo);
	getch();
}