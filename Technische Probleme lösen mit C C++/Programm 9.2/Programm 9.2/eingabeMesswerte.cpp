// Funktion zum Einlesen von Messwerten
// Autor: Heiderich / Meyer
// ------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void eingabeMesswerte(float x[], float y[], int* anz)
{
	int anzahl, i;
	printf("\n\n\n\tEingabe der Messwerte\n");
	printf("\t---------------------\n\n");
	do
	{
		printf("\tBitte geben Sie die Anzahl ( < 100 !) der Messwerte an: ");
		fflush(stdin);
		scanf("%i",&anzahl);
	}while (anzahl >= 100);
	*anz = anzahl;
	for (i = 0; i < anzahl; i++)
	{
		printf("\n\tx[%2i] = ",i+1);
		fflush(stdin);
		scanf("%f",&x[i]);
		printf("\ty[%2i] = ",i+1);
		fflush(stdin);
		scanf("%f",&y[i]);
	}
}