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
	float y = 0.5 * pow(x,2);
	if (aus == 1)
	{
		printf("\tFl%cchenberechnung f%cr:\n\n",char(132),char(129));
		printf("\tf(x) = 0.5 * x%c\n",char(253));
		aus = 0;
	}
	return y;
}