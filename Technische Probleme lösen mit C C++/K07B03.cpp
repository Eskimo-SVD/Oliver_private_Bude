// Bruchrechnung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "C_Bruch.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// Erzeugung und Versorgung von Bruch1
	C_Bruch b1 = C_Bruch(1);
	// Erzeugung und Versorgung von Bruch2
	C_Bruch b2 = C_Bruch(2);
	// Deklaration von Ergbenisbruch (Standardkonstruktor wird aufgerufen)
	C_Bruch erg;

	printf("\n\tAusgabe von Bruch1:\n");
	b1.bruchDoku();
	printf("\tevtl. gekuerzt:\n");
	b1 = b1.bruchKuerzen();
	b1.bruchDoku();
	
	printf("\n\tAusgabe von Bruch2:\n");
	b2.bruchDoku();
	printf("\tevtl. gekuerzt:\n");
	b2 = b2.bruchKuerzen();
	b2.bruchDoku();
	
	printf("\n\tAddition von Bruch1 und Bruch2:\n");
	erg = b1.bruchAddition(b2);
	erg.bruchDoku();
	printf("\tevtl. gekuerzt:\n");
	erg = erg.bruchKuerzen();
	erg.bruchDoku();
	
	printf("\n\tSubtraktion von Bruch1 und Bruch2:\n");
	erg = b1.bruchSubtraktion(b2);
	erg.bruchDoku();
	printf("\tevtl. gekuerzt:\n");
	erg = erg.bruchKuerzen();
	erg.bruchDoku();
	
	printf("\n\tMultiplikation von Bruch1 und Bruch2:\n");
	erg = b1.bruchMultiplikation(b2);
	erg.bruchDoku();
	printf("\tevtl. gekuerzt:\n");
	erg = erg.bruchKuerzen();
	erg.bruchDoku();
	
	printf("\n\tDivision von Bruch1 und Bruch2:\n");
	if (b2.getZaehler() == 0)
	{
		printf("\n\tDivision nicht moeglich, da Zaehler von\n");
		printf("\tBruch2 0 ist!!\n");
	}
	else
	{
		erg = b1.bruchDivision(b2);
		erg.bruchDoku();
		printf("\tevtl. gekuerzt:\n");
		erg = erg.bruchKuerzen();
		erg.bruchDoku();
	}
	getch();
	
	return 0;
}