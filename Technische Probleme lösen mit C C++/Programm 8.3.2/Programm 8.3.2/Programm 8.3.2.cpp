// Programm 8.3.2.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Nullstellen
// nach der "regula falsi"
// Autor: Heiderich / Meyer
// ---------------------------------------
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
	float xu, xo, epsilon, xM;
	int iaus = 1;
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Nullstellen\n");
	printf("\t        nach der ""regula falsi""\n");
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
		xM = xo - (( xo - xu ) / ( f(xo,iaus) - f(xu,iaus) )) * f(xo,iaus);
		printf("\tIntervall: [%10.6f, %10.6f]\n",xu,xo);
		if ( signum( f(xM,iaus) ) == signum( f(xu,iaus) ) ) xu = xM;
		else                                                xo = xM;
	} while ( abs( f(xM,iaus) ) > epsilon );
	// Ausgabe Ergebnisse
	printf("\n\tdie Funktion besitzt eine Nullstelle bei x = %f\n",xM);
	getch();
}