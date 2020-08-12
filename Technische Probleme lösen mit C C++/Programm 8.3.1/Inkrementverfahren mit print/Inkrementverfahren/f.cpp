#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
// Funktion f(x)
// Rückgabe Funktionswert an der Stelle x
// Autor: Heiderich / Meyer
// --------------------------------------
float f(float x)
{
	float y = 0.9 * pow(x,3) - 4.0 * pow (x,2) + 3.02 * x -490.28;
	printf("\tx = %10.6f f(x) = %10.6f\n",x,y);
	return y;
}