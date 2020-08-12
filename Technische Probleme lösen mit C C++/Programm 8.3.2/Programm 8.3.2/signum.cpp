#include "stdafx.h"
// Signum-Funktion
// Funktion untersucht eine vorgegebene Zahl auf ihr
// Vorzeichen
// Rückgabe: +1, falls zahl > 0
//            0, falls zahl = 0
//           -1, falls zahl < 0
// Autor: Heiderich / Meyer
// -------------------------------------------------
int signum(float zahl)
{
	if (zahl > 0)      return 1;
	else if (zahl < 0) return -1;
	else               return 0;
}