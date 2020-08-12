// Programm 8.4.1.cpp: Hauptprojektdatei.
// Flächenberechnung (numerische Integration)
// mit Riemannschen Ober- und Untersummen
// Autor: Heiderich / Meyer
// ------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "f.h"
using namespace System;
void main()
{
	// Deklaration der Variablen
	int n;         // Anzahl Teilintervalle
	float a;       // untere Intervallgrenze
	float b;       // obere Intervallgrenze
	float delta_x; // Breite der Teilintervalle
	float xi;      // i. Stützwert
	float oS;      // Obersumme
	float uS;      // Untersumme
	float aU;      // Fläche aus Untersummen
	float aO;      // Fläche aus Obersummen
	int iaus = 1;  // Steuervariable zur Dokumentation von f(x)
	int i;         // Zählersteuerungsvariable (for-Schleifen)
    // Begrüßung
    printf("\n\n\t   Programm zur Fl%cchenberechnung\n",char(132));
	printf("\tmit Riemannschen Ober- und Untersummen\n");
    printf("\t--------------------------------------\n");
    // Eingabe der Intervallgranzen und Anzahl Teilintervalle
	printf("\n\tBitte geben Sie die untere Intervallgrenze  a  an: ");
	fflush(stdin);
	scanf("%f",&a);
	printf("\tBitte geben Sie die obere  Intervallgrenze  b  an: ");
	fflush(stdin);
	scanf("%f",&b);
	printf("\tBitte geben Sie die Anzahl der Teilintervalle  an: ");
	fflush(stdin);
	scanf("%i",&n);
	printf("\n");
	// Berechnung der Breite der Teilintervalle
	delta_x = (b - a) / n;
	// Initialisierung der Summenvariablen
	uS = 0.0;
	oS = 0.0;
	// Berechnung der Untersumme
	for (i = 0; i <= n-1; i++)
	{
		xi = a + i * delta_x;
		uS += f(xi, iaus);
	}
	// Berechnung der Fläche aus den Untersummen
	aU = uS * delta_x;
	// Berechnung der Obersumme
	for (i = 1; i <= n; i++)
	{
		xi = a + i * delta_x;
		oS += f(xi, iaus);
	}
	// Berechnung der Fläche aus den Obersummen
	aO = oS * delta_x;
	// Ausgabe Ergebnisse
	printf("\n\tdie Fl%cchenberechnung findet statt im Intervall [%.2f, %.2f]\n",char(132),a,b);
	printf("\n\tdie Fl%cche der Untersummen betr%cgt AU = %10.4f FE\n",char(132),char(132),aU);
	printf("\n\tdie Fl%cche der Obersummen  betr%cgt AO = %10.4f FE\n",char(132),char(132),aO);
	getch();
}