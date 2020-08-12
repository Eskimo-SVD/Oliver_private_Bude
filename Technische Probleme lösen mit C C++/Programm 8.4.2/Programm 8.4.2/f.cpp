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
	float y = x;
	if (aus == 1)
	{
		printf("\tFl%cchenberechnung f%cr:\n\n",char(132),char(129));
		printf("\tf(x) = x\n");
		aus = 0;
	}
	return y;
}