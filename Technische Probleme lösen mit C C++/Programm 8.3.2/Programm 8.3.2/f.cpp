#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
// Funktion f(x)
// Rückgabe Funktionswert an der Stelle x
// aus steuert die Dokumentation der Funktion: 0 - keine Ausgabe, 1 - Ausgabe
// Autor: Heiderich / Meyer
// --------------------------------------------------------------------------
float f(float x, int& aus)
{
	float y = 0.9 * pow(x,3) - 4.0 * pow (x,2) + 3.02 * x -490.28;
	if (aus == 1)
	{
		printf("\tAnalysiert wird:\n\n");
		printf("\ty = 0.9 * pow(x,3) - 4.0 * pow (x,2) + 3.02 * x -490.28\n\n");
		aus = 0;
	}
	return y;
}