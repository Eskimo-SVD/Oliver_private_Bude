// Programm 8.5.1.cpp: Hauptprojektdatei.
// Platine_Konsole
// Dimensionierung von Platinen
// Autor: Heiderich / Meyer
// ------------------------------------------
#include "stdafx.h"
#include "Platine.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace System;

void main()
{
	// Deklarationen
	char ausw;			// Steuerung der switch-Anweisung
	char ein_bez[256];  // Bezeichnung der Platine
	float ein_laenge;	// Länge der Platine (Eingabe)
	float ein_breite;	// Breite der Platine (Eingabe)
	C_Platine p1;         // Instanz (Objekt) der Klasse Platine
	int aendern_bez = 0;// Änderungskennziffer: Attribute können erst geändert werden,
	int aendern_lae = 0;// wenn sie zuvor eingegeben wurden!
	int aendern_bre = 0;
	do
	{
		system("cls");
		printf("\n\tHerzlich Willkommen bei der Dimensionierung von Platinen\n");
		printf("\t--------------------------------------------------------\n\n");
		printf("\t1: Eingabe einer Bezeichnung\n");
		printf("\t2: Eingabe einer L%cnge  l [mm]\n",char(132));
		printf("\t3: Eingabe eines Breite b [mm]\n\n");
		printf("\t4: %cnderung der Bezeichnung\n",char(142));
		printf("\t5: %cnderung der L%cnge  l [mm]\n",char(142),char(132));
		printf("\t6: %cnderung des Breite b [mm]\n\n",char(142));
		printf("\t7: Dokumentation und Ausgabe\n\n");
		printf("\tE: Programmende\n\n");
		printf("\tBitte Auswahl treffen: ");
		fflush(stdin);
		ausw = getch();
		printf("%c",ausw);
		switch(ausw)
		{
			case '1': if (aendern_bez == 1)
					  {
						  printf("\n\n\tEingabe der Bezeichnung bereits erfolgt!\n");
						  printf("\tBitte Auswahl ==> 4\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  aendern_bez = 1; // Änderungskennziffer setzen
	  					  printf("\n\n\tBitte geben Sie eine Bezeichnung ein: ");
						  fflush(stdin);
						  scanf("%s",ein_bez);
						  p1.setBezeichnung(ein_bez);
					  }
				      break;
			case '2': if (aendern_lae == 1)
					  {
						  printf("\n\n\tEingabe der L%nge bereits erfolgt!\n",char(132));
						  printf("\tBitte Auswahl ==> 5\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  aendern_lae = 1; // Änderungskennziffer setzen
	  					  printf("\n\n\tBitte geben Sie eine L%cnge ein: ",char(132));
						  fflush(stdin);
						  scanf("%f",&ein_laenge);
						  p1.setLaenge(ein_laenge);
					  }
					  break;
			case '3': if (aendern_bre == 1)
					  {
						  printf("\n\n\tEingabe der Breite bereits erfolgt!\n");
						  printf("\tBitte Auswahl ==> 6\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  aendern_bre = 1; // Änderungskennziffer setzen
	  					  printf("\n\n\tBitte geben Sie eine Breite ein: ");
						  fflush(stdin);
						  scanf("%f",&ein_breite);
						  p1.setBreite(ein_breite);
					  }
					  aendern_bre = 1; // Änderungskennziffer setzen
				      break;
			case '4': if (aendern_bez == 0)
					  {
						  printf("\n\n\teine %cnderung der Bezeichnung ist erst nach einer\n",char(142));
						  printf("\tErsteingabe m%cglich! Bitte zuerst Auswahl ==> 1\n",char(148));
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  printf("\n\n\tBisherige Bezeichnung: %s\n\n",p1.getBezeichnung());
						  printf("\tBitte geben Sie eine neue Bezeichnung ein: ");
						  fflush(stdin);
						  scanf("%s",ein_bez);
						  p1.setBezeichnung(ein_bez);
					  }
					  break;
			case '5': if (aendern_lae == 0)
					  {
						  printf("\n\n\teine %cnderung der L%cnge l ist erst nach einer\n",char(142),char(132));
						  printf("\tErsteingabe m%cglich! Bitte zuerst Auswahl ==> 2\n",char(148));
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  printf("\n\n\tBisherige L%cnge: %.2f mm\n\n",char(132),p1.getLaenge());
						  printf("\tBitte geben Sie eine neue L%cnge ein: ",char(132));
						  fflush(stdin);
						  scanf("%f",&ein_laenge);
						  p1.setLaenge(ein_laenge);
					  }
					  break;
			case '6': if (aendern_bre == 0)
					  {
						  printf("\n\n\teine %cnderung der Breite b ist erst nach einer\n",char(142));
						  printf("\tErsteingabe m%cglich! Bitte zuerst Auswahl ==> 3\n",char(148));
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  printf("\n\n\tBisherige Breite: %.2f mm\n\n",p1.getBreite());
						  printf("\tBitte geben Sie eine neue Breite ein: ");
						  fflush(stdin);
						  scanf("%f",&ein_breite);
						  p1.setBreite(ein_breite);
					  }
					  break;
			case '7': if (aendern_bez == 0)
					  {
						  printf("\n\n\teine Berechnung ist erst nach Eingabe der Bezeichnung m%cglich!\n",char(148));
						  printf("\tBitte zuerst Auswahl ==> 1\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else if (aendern_lae == 0)
					  {
						  printf("\n\n\teine Berechnung ist erst nach Eingabe der L%cnge l m%cglich!\n",char(132),char(148));
						  printf("\tBitte zuerst Auswahl ==> 2\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else if (aendern_bre == 0)
					  {
						  printf("\n\n\teine Berechnung ist erst nach Eingabe des Breite r m%cglich!\n",char(148));
						  printf("\tBitte zuerst Auswahl ==> 3\n");
						  printf("\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  else
					  {
						  system("cls");
						  p1.ausgabeKonsole();
						  printf("\n\n\tweiter mit beliebiger Taste ......");
						  getch();
					  }
					  break;
			case 'e':
			case 'E': break;
			default:  printf("\n\n\tfalsche Eingabe! bitte korrigieren!\n");
					  printf("\tweiter mit beliebiger Taste ......");
					  getch(); 
		} 
	} while(ausw != 'e' && ausw != 'E');
}