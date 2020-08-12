// Programm 8.2.1cpp: Hauptprojektdatei.
// Programm zur Berechnung von Widerstandsreihen E 6 - E 96
// Autor: Heiderich / Meyer
// --------------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace System;
void main()
{
	int n, m, i, tol;
	float ru, r, ro;
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Widerstandsreihen E 6 - E 96\n");
    printf("\t--------------------------------------------------------\n");
    // Eingabe der Nr. der E-Reihe
	printf("\n\tBitte geben Sie die Nr. der E-Reihe an: ");
	fflush(stdin);
	scanf("%i",&n);
	// Überprüfung der Eingabe
	if (n!=6 && n!=12 && n!=24 && n!=48 && n!=96)
	{
		printf("\n\n\tung%cltige Eingabe (%i)!\n\n",char(129),n);
		printf("\tg%cltige Werte: 6, 12, 24, 48 oder 96!\n\n",char(129));
	}
	else
	{
		// Eingabe des Dekadenfaktors
		printf("\n\tBitte geben Sie den Dekadenfaktor m an: ");
		fflush(stdin);
		scanf("%i",&m);
		// Berechnung der Toleranz
		tol = (int)(120./n);
		// Ausgabe Tabellenkopf
		printf("\n\t+--------------------------------------+\n");
		printf("\t|       Widerstandsreihe E - %2i        |\n",n);
		printf("\t+--------------------------------------+\n");
		printf("\t|      - %2i%% |     R      |      + %2i%% |\n",tol,tol);
		printf("\t+--------------------------------------+\n");
		// Berechnung der Widerstandswerte
		for (i = 0; i <= n-1; i++)
		{
		   float h1 = pow(10.,1./n);
		   float h2 = pow(h1,i);
		   float h3 = pow(10.,m);
		   r = pow(pow(10.,1./n),i) * pow(10.,m);
		   ru = r * (1 - tol/100.);
		   ro = r * (1 + tol/100.);
		   printf("\t| %10.5f | %10.5f | %10.5f |\n",ru, r, ro);
		}
		printf("\t+--------------------------------------+\n\n\n");
	}
}