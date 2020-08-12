// Programm 8.4.2.cpp: Hauptprojektdatei.
// Flächenberechnung (numerische Integration)
// nach der Trapezregl
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
	float s;       // Summe
	float aF;      // Fläche aus Summe
	int iaus = 1;  // Steuervariable zur Dokumentation von f(x)
	int i;         // Zählersteuerungsvariable (for-Schleifen)
    // Begrüßung
    printf("\n\n\tProgramm zur Fl%cchenberechnung\n",char(132));
	printf("\t     nach der Trapezregel\n");
    printf("\t------------------------------\n");
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
	// Initialisierung der Summenvariable
	s = 0.0;
	// Berechnung der Summe der Funktionswerte
	for (i = 0; i <= n; i++)
	{
		xi = a + i * delta_x;
		if (i == 0 || i == n) s += f(xi,iaus);
		else                  s += 2.0 * f(xi,iaus);
	}
	// Berechnung der Fläche aus der Summe
	aF = delta_x / 2. * s;
	// Ausgabe Ergebnisse
	printf("\n\tdie Fl%cchenberechnung findet statt im Intervall [%.2f, %.2f]\n",char(132),a,b);
	printf("\n\tdie Fl%cche betr%cgt A = %10.4f FE\n",char(132),char(132),aF);
	getch();
}