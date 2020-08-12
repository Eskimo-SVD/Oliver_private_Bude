// Programm 8.3.3.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Nullstellen
// nach dem Newton-Verfahren
// Autor: Heiderich / Meyer
// ---------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "f.h"
#include <math.h>
using namespace System;
void main()
{
	float xS, xN, epsilon;
	float a, b, c, d;
	int iaus = 1;
    bool schalter = true;
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Nullstellen\n");
	printf("\t       nach dem Newton-Verfahren\n");
	printf("\t f%cr eine beliebige Funktion 3.Ordnung\n",char(129));
    printf("\t---------------------------------------\n");
    // Eingabe der Koeffizienten, des Startwertes und der Genauigkeit
	printf("\n\tBerechnet wird eine Nullstelle von:\n");
	printf("\tf(x) = a * x%c + b * x%c + c * x + d\n\n",char(252), char(253));
	printf("\tBitte geben Sie den Koeffizienten a an: ");
	fflush(stdin);
	scanf("%f",&a);
	printf("\tBitte geben Sie den Koeffizienten b an: ");
	fflush(stdin);
	scanf("%f",&b);
	printf("\tBitte geben Sie den Koeffizienten c an: ");
	fflush(stdin);
	scanf("%f",&c);
	printf("\tBitte geben Sie den Koeffizienten d an: ");
	fflush(stdin);
	scanf("%f",&d);
	printf("\n\tf(x) = %.2f * x%c + %.2f * x%c + %.2f * x + %.2f\n\n",a,char(252),b,char(253),c,d);
	printf("\n\tBitte den Startwert      xS    angeben: ",char(129));
	fflush(stdin);
	scanf("%f",&xS);
	printf("\n\tund die gew%cnschte Genauigkeit epsilon: ",char(129));
	fflush(stdin);
	scanf("%f",&epsilon);
	printf("\n");
	do
	{
		if (schalter) schalter = false;
		else          xS = xN;
		xN = xS - f(a,b,c,d,xS) / f_Strich(a,b,c,xS);		
	} while ( abs( xN - xS ) > epsilon );
	// Ausgabe Ergebnisse
	printf("\n\tdie Funktion besitzt eine Nullstelle bei x = %f\n",xN);
	getch();
}