// Programm 9.2.cpp: Hauptprojektdatei.
// Programm zur Berechnung von Ausgleichsgeraden
// nach der Fehlerquadrat-Methode mit Menuesteuerung
// Autor: Heiderich / Meyer
// -------------------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "eingabeMesswerte.h"
#include "ausgabeFunktion.h"
#include "gegenueberstellungWerte.h"
#include "gegenueberstellungAbweichung.h"
using namespace System;
void main()
{
	char auswahl;      // Steuerungsgröße, Auswahl aus Menue
	int wieder = 0;    // Steuerungsgröße zum Löschen des Monitors
	float mess_x[100]; // x-Koordinaten der Messwerte
	float mess_y[100]; // y-Koordinaten der Messwerte
	int anzahl;        // Anzahl der Messwerte (Eingabe)
	float m;           // Steigung der Ausgleichsgeraden
	float b;           // y-Achsen-Schnittpunkt der Ausgleichsgeraden
	bool ok1 = false;  // Menue-Punkt (1) abgearbeitet
	bool ok2 = false;  // Menue-Punkt (2) abgearbeitet
	// Begrüßung
    do
	{
		// Ausgabe des Hauptmenues
		// ggfls. Bildschirm löschen
		if (wieder == 0)
		{
			printf("\n\n\tAusgleichsrechnung f%cr eine lineare Funktion\n",char(129));
			printf("\t--------------------------------------------\n");
			wieder = 1;
		}
		else system("cls");
		printf("\n\t        M e n u e\n\n");
		printf("\tEingabe der Messwerte ................ (1)\n");
		printf("\tAusgabe der linearen Funktion ........ (2)\n");
		printf("\n\tGegen%cberstellung\n",char(129));
		printf("\tFunktionswerte - Messwerte ........... (3)\n");
		printf("\tAbweichungen ......................... (4)\n");
		printf("\n\tProgrammende ......................... (5)\n");
		printf("\n\tBitte w%chlen Sie: ",char(132));
		fflush(stdin);
		scanf("%c",&auswahl);
		// Steuerung über auswahl
		switch(auswahl)
		{
		   case '1': eingabeMesswerte(mess_x, mess_y, &anzahl);
			         // sind neue Messwerte eingegeben, so muss Auswahl (2)
			         // erneut aufgerufen werden bevor (3) oder (4)
			         ok1 = true;
					 ok2 = false;
			         break;
 		   case '2': if (ok1)
					 {
						 ausgabeFunktion(mess_x, mess_y, anzahl, &m, &b);
						 ok2 = true;
					 }
					 else 
					 {
						 printf("\n\n\tzun%cchst Messwerte eingeben!!",char(132));
						 getch();
					 }
			         break;
		   case '3': if (ok2)
					 {
						 gegenueberstellungWerte(mess_x, mess_y, anzahl, m, b);
					 }
					 else
					 {
						 if (ok1) printf("\n\n\tzun%cchst lineare Funktion ausgeben!!",char(132));
						 else     printf("\n\n\tzun%cchst Messwerte eingeben!!",char(132));
						 getch();
					 }
			         break;
		   case '4': if (ok2)
					 {
						 gegenueberstellungAbweichung(mess_x, mess_y, anzahl, m, b);
					 }
					 else
					 {
						 if (ok1) printf("\n\n\tzun%cchst lineare Funktion ausgeben!!",char(132));
						 else     printf("\n\n\tzun%cchst Messwerte eingeben!!",char(132));
						 getch();
					 }
			         break;
		   case '5': break;
		   default:  printf("\n\n\tfehlerhafte Eingabe (%c)\n",auswahl);
			         printf("\tbitte korrigieren!");
					 getch();
		}
	}while(auswahl!='5');
}