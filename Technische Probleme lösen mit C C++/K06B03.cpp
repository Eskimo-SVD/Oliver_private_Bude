// Programm 6.3.cpp: Hauptprojektdatei.
// Programm zur Berechnung einer Brückenkonstruktion
// Autor: Heiderich / Meyer
// -------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace System;
void main()
{
	int n, i;
	float delta_x, xi, lxi;
	char antwort, c1 = '\x81', c2 = '\x84';
	// Begrüßung
    printf("\n\nProgramm zur Berechnung einer Br%cckenkonstruktion\n",c1);
    printf("-------------------------------------------------\n");
    // Beginn der Wiederholungssteuerung
	do
	{
		// Eingabe der Anzahl der Stäbe
		printf("\nBitte geben Sie die Anzahl der St%cbe an: ",c2);
		fflush(stdin);
		scanf("%i",&n);
		// Berechnung der Abstände
		// Vorsicht: "138" statt "138.0" führt zu einer int-Division!
		delta_x = 138.0 / (n-1);
		// Ausgabe Tabellenkopf
		printf("\nErgebnisse der Br%cckenberechnung:\n",c1);
		printf("---------------------------------\n\n");
		printf("Anzahl der St%cbe : %i\n",c2,n);
		printf("Abstand der St%cbe: %.2f m\n",c2,delta_x);
		// Ausgabe Tabellenkopf
		printf("\nStab-Nr. |  bei x | Stabl%cnge\n",c2);
		printf("         |    [m] |      [m]\n");
		printf("---------+--------+----------\n");
		// Berechnung der Länge der Stäbe und Ausgabe
		for (i = 0; i <= n-1; i++)
		{
			xi = i * delta_x;
			lxi = 29.0 - ( -0.005461 * pow(xi-69, 2) + 26 );
			printf("   %2i    | %6.2f |   %6.2f \n",i+1,xi,lxi);
		    printf("---------+--------+----------\n");
		}
		printf("\nerneute Anwendung? (j/n)");
		fflush(stdin);
		scanf("%c",&antwort);
	} while (antwort =='j' || antwort == 'J');
}