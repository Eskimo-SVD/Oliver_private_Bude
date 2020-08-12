#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
// Funktion f(x) = ax³+bx²+cx+d
// Übergabe: a, b, c, d, x
// Rückgabe: Funktionswert an der Stelle x
// Autor: Heiderich / Meyer
// ---------------------------------------
float f(float a,float b,float c,float d,float x)
{
	return a * pow(x,3) + b * pow (x,2) + c * x + d;
}
// Funktion f'(x)=3ax²+2bx+c (1.Ableitung von f(x))
// Übergabe: a, b, c, x, aus
// Rückgabe: Funktionswert der 1.Ableitung an der Stelle x,
//           also die Steigung von f(x) an der Stelle x
// Autor: Heiderich / Meyer
// --------------------------------------------------------
float f_Strich(float a,float b,float c,float x)
{
	return 3.0 * a * pow(x,2) + 2.0 * b * x + c;
}