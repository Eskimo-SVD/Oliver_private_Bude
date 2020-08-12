#include "C_Bruch.h"
#include "stdio.h"

// Implementierung der Klassen-Methoden

// Standardkonstruktor
C_Bruch::C_Bruch()
{
}

// �berladener Konstruktor
C_Bruch::C_Bruch(int nr)
{
	printf("\n\tBitte Zaehler des %i.Bruchs angeben: ",nr);
	scanf("%i",&zaehler);
	do
	{
		printf("\tBitte Nenner  des %i.Bruchs angeben: ",nr);
		scanf("%i",&nenner);
		if (nenner == 0)
		{
			printf("\n\n\tNenner duerfen nicht 0 sein!!\n");
			printf("\tEingabe bitte korrigieren!!\n\n");
		}
	} while(nenner == 0);
}

// �berladener Konstruktor
C_Bruch::C_Bruch(int neuZaehler, int neuNenner)
{
	zaehler = neuZaehler;
	nenner  = neuNenner;
}

// Destruktor
C_Bruch::~C_Bruch()
{
}

// Zuweisung Z�hler
void C_Bruch::setZaehler(int neuZaehler)
{
	zaehler = neuZaehler;
}

// Zuweisung Nenner
void C_Bruch::setNenner(int neuNenner)
{
	nenner  = neuNenner;
}

// R�ckgabe Z�hler
int C_Bruch::getZaehler()
{
	return zaehler;
}

// R�ckgabe Nenner
int C_Bruch::getNenner()
{
	return nenner;
}

// Addition von Br�chen - R�ckgabe Bruch
C_Bruch C_Bruch::bruchAddition(C_Bruch summand)
{
	C_Bruch result;
	result.zaehler = zaehler * summand.nenner + summand.zaehler * nenner;
	result.nenner  = nenner * summand.nenner;
	return result;
}

// Subtraktion von Br�chen - R�ckgabe Bruch
C_Bruch	C_Bruch::bruchSubtraktion(C_Bruch subtrahend)
{
	C_Bruch result;
	result.zaehler = zaehler * subtrahend.nenner - subtrahend.zaehler * nenner;
	result.nenner  = nenner * subtrahend.nenner;
	return result;
}

// Multiplikation von Br�chen - R�ckgabe Bruch
C_Bruch	C_Bruch::bruchMultiplikation(C_Bruch faktor)
{
	C_Bruch result;
	result.zaehler = zaehler * faktor.zaehler;
	result.nenner  = nenner * faktor.nenner;
	return result;
}

// Division von Br�chen - R�ckgabe Bruch
C_Bruch	C_Bruch::bruchDivision(C_Bruch divisor)
{
	C_Bruch result;
	result.zaehler = zaehler * divisor.nenner;
	result.nenner  = nenner * divisor.zaehler;
	return result;
}

// K�rzen von Br�chen - R�ckgabe Bruch
C_Bruch	C_Bruch::bruchKuerzen()
{
	C_Bruch result;
	int sign = 1;
	if (zaehler < 0)
	{
		sign = -sign;
		zaehler = -zaehler;
	}
	if (nenner < 0)
	{
		sign = -sign;
		nenner = -nenner;
	}
	int teiler = ggT(zaehler,nenner);
	result.zaehler = sign * zaehler / teiler;
	result.nenner  = nenner / teiler;
	return result;
}

// Ermittlung des gr��ten gemeinsamen Teilers zweier Zahlen 
// (wird beim k�rzen gebraucht)
int C_Bruch::ggT(int z1,int z2)
{
	int rest;
	while(z2 > 0)
	{
		rest = z1 % z2;
		z1 = z2;
		z2 = rest;
	}
	return z1;
}

// Dokumentation (Ausgabe) von Br�chen
void C_Bruch::bruchDoku()
{
	if (zaehler != 0)
	{
		printf("\tBruch = %i / %i\n",zaehler,nenner);
	}
	else
	{
		printf("\tBruch = 0\n");
	}
}