// Programm 8.2.4.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Fourier-Koeffizienten
// Autor: Heiderich / Meyer
// -------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// die folgende Zeile ist erforderlich für mathematische Konstanten,
// die aus math.h benutzt werden sollen (hier M_PI <== pi)
#define _USE_MATH_DEFINES  
#include <math.h>
using namespace System;
void main()
{
	int n, i, k;
	float delta_x, sa0, s_sin, s_cos, xi;
	// Deklaration der Arrays für Messwerte und Koeffizienten
	// Um den Index 0 übergehen zu können, werden die Dimensionen
	// höher angegeben. Wird der Index 0 mitverwendet, ist eine
	// Indextransformation (Verschiebung) erforderlich!
	float f[101];
	float a0, s[51], c[51];
	// Begrüßung
    printf("\n\n\tProgramm zur Berechnung von Fourier-Koeffizienten\n");
    printf("\t-------------------------------------------------\n");
    // Eingabe der Anzahl der Messwerte
	do
	{
	   printf("\n\tBitte geben Sie die Anzahl der Messwerte an: ");
	   fflush(stdin);
	   scanf("%i",&n);
	   // Überprüfung der Eingabe - wegen der Dimensionierung des Arrays f[],
	   // darf n nicht groeßer als 100 sein (evtl. dyn. dimensionieren) 
	   if (n > 100)
	   {
	      printf("\n\n\tung%cltige Eingabe (%i)!\n\n",char(129),n);
		  printf("\tg%cltige Werte: <= 100!\n\n",char(129));
		  getch();
       }
	}while (n > 100);
	// Berechnung delta_x
	delta_x = 2.0 * M_PI / n;  // M_PI als Konstante aus math.h
	// Eingabe der Messwerte und Aufsummierung für den Mittelwert
	sa0 = 0.; // Initialisierunf der Summe für den arithmetischen Mittelwert
	printf("\n\tEingabe der %i Messwerte:\n\n",n);
	for (i = 1; i <= n; i++)
	{
		printf("\t%2i.Messwert: ",i);
		fflush(stdin);
		scanf("%f",&f[i]);
		sa0 += f[i];
	}
	// Mittelwert
	a0 = sa0 / n;
	// Berechnung der Koeffizienten s[k] und c[k]
	for(k = 1; k <= n/2 -1; k++)
	{
		// Initialisieung der Summen
		s_sin = 0.0;
		s_cos = 0.0;
		for (i = 1; i <= n; i++)
		{
			xi = i * delta_x;
			s_sin += f[i] * sin( k * xi );
			s_cos += f[i] * cos( k * xi );
		}
		s[k] = 2.0 / n * s_sin;
		c[k] = 2.0 / n * s_cos;
	}
	// Berechnung des Koeffizienten c[n/2]
	// Initialisieung der Summe
	s_cos = 0.0;
	for (i = 1; i <= n; i++)
	{
		xi = i * delta_x;
		s_cos += f[i] * cos( n / 2.0 * xi );
	}
	c[n/2] = 1.0 / n * s_cos;
	// Ausgabe Ergebnisse
	printf("\n\n\tErrechnete Fourrier-Koeffizienten:\n");
	printf("\t----------------------------------\n");
	printf("\n\tarithmetischer Mittelwert a0 = %12.4e\n\n",a0);
	// Tabellenkopf
    printf("\t+-------------+-------------------+-------------------+\n");
	printf("\t| harmonische | SIN-Koeffizienten | COS-Koeffizienten |\n");
	printf("\t+-------------+-------------------+-------------------+\n");
	for(k = 1; k <= n/2 -1; k++)
	{
		printf("\t|     %2i      |    %12.4e   |    %12.4e   |\n",k,s[k],c[k]);
	    printf("\t+-------------+-------------------+-------------------+\n");
	}
	printf("\t|     %2i      |        ---        |    %12.4e   |\n",n/2,c[n/2]);
	printf("\t+-------------+-------------------+-------------------+\n");
	getch();
}