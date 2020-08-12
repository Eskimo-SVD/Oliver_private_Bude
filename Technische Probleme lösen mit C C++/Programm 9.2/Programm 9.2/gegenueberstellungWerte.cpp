// Funktion zur Gegenüberstellung
// Messwerte / Funktionswerte
// Autor: Heiderich / Meyer
// ------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void gegenueberstellungWerte(float x[], float y[], int anz, float m, float b)
{
	int i;
	float yre; // rechnerischer Funktionswert
	printf("\n\n\t+-----------------------+---------------+\n");
	printf("\t|    Wertepaar (x|y)    | y - errechnet |\n");
	printf("\t+-----------+-----------+---------------+\n");
	printf("\t|     x     |     y     |               |\n");
	printf("\t+-----------+-----------+---------------+\n");
	for (i = 0; i < anz; i++)
	{
		yre = m * x[i] + b;
		printf("\t| %9.3f | %9.3f |    %9.3f  |\n",x[i],y[i],yre);
	}
	printf("\t+-----------+-----------+---------------+\n");
	getch();
}