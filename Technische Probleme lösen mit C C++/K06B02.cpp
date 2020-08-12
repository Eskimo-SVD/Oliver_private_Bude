// Programm 6.2.cpp: Hauptprojektdatei.
// Programm zur Polygonflächenberechnung nach Gauß
// Autor: Heiderich / Meyer
// -----------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace System;
int main()
{
	int n, i;
	float a;
	char antwort;
	// Begrüßung
    printf("\n\nProgramm zur Polygonfl\x84\chenberechnung nach Gau\xE1\n");
    printf("-----------------------------------------------\n");
    // Beginn der Wiederholungssteuerung
	do
	{
		// Eingabe der Anzahl der Eckpunkte
		printf("\nBitte geben Sie die Anzahl der Eckpunkte an: ");
		fflush(stdin);
		scanf("%i",&n);
		// dynamisches Anlegen der Felder
		float *x = (float*)malloc(n * sizeof(float));
		float *y = (float*)malloc(n * sizeof(float));
		if(x == NULL || y == NULL) 
		{
			printf("Kein Virtueller RAM mehr verfuegbar ...\n");
			return EXIT_FAILURE;
		}
		// Eingabe der Koordinaten
		printf("\nEingabe der Koordinaten:\n\n");
		for (i = 0; i <= n; i++)
		{
			printf("%4i.Ecke    x-Koordinate: ",i);
			fflush(stdin);
			scanf("%f",&x[i]);
			printf("             y-Koordinate: ");
			fflush(stdin);
			scanf("%f",&y[i]);
		}
		// Initialisierung der Fläche (Nullsetzen)
		a = 0.0;
		// Berechnung der Fläche nach dem Gauß-Algorithmus
		for (i = 0; i <= n-1; i++)
		{
			a = a + (x[i]*y[i+1] - x[i+1]*y[i]);
		}
		a = a / 2.0;
		// Ausgabe der Ergebnisse
		printf("\nDie berechnete Fl\x84\che betr\x84\gt %.2fFE\n",a);
		// Wiederholungssteuerung
		printf("\nerneute Anwendung? (j/n)");
		fflush(stdin);
		scanf("%c",&antwort);
	} while (antwort =='j' || antwort == 'J');
	return 0;
}