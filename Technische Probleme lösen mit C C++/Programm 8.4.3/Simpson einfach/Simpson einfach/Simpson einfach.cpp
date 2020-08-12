// Simpson einfach.cpp: Hauptprojektdatei.
// Flächenberechnung (numerische Integration)
// nach der Simpsonschen Regel
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
	int n;         // Anzahl Teilintervalle - n muss gerade sein!
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
	printf("\t nach der Simpsonschen Regel\n");
    printf("\t------------------------------\n");
    // Eingabe der Intervallgranzen und Anzahl Teilintervalle
	printf("\n\tBitte geben Sie die untere Intervallgrenze  a  an: ");
	fflush(stdin);
	scanf("%f",&a);
	printf("\tBitte geben Sie die obere  Intervallgrenze  b  an: ");
	fflush(stdin);
	scanf("%f",&b);
	// Teilintervall mit Plausibilitätsprüfung
	do
	{
		printf("\tBitte geben Sie die Anzahl der Teilintervalle  an: ");
	    fflush(stdin);
	    scanf("%i",&n);
		if (n / 2 * 2 != n) printf("\tn muss gerade sein!!\n");
	}while (n / 2 * 2 != n);
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
		else
		{
			if (i / 2 * 2 != i) s += 4.0 * f(xi,iaus);
			else                s += 2.0 * f(xi,iaus);
		}
	}
	// Berechnung der Fläche aus der Summe
	aF = delta_x / 3. * s;
	// Ausgabe Ergebnisse
	printf("\n\tdie Fl%cchenberechnung findet statt im Intervall [%.2f, %.2f]\n",char(132),a,b);
	printf("\n\tdie Fl%cche betr%cgt A = %10.6f FE\n",char(132),char(132),aF);
	printf("\n\tbei einer Berechnung mit %i Teilintervallen\n",n);
	getch();
}