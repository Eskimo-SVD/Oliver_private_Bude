// Programm 6.6.2.cpp: Hauptprojektdatei.
// Heissleiter mit logarithmischer Teilung
// Autor: Heiderich/Meyer
// ---------------------------------------
#include "stdafx.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
#include "stdio.h"

using namespace System;

void main()
{
   float tu, tm, delta_t, achsenlaenge, t;
   float b, ro, ru, rm, yo, yu, rt, lc;
   char weiter, c1 = '\x84', c2 = '\x81', c3 = '\x94', c4 = '\xE1';
   char cg = '\xF8';
   int od, ud, dk;
   // Begrüßung
   printf("\n\n\tHeissleiter mit logarithmischer Teilung\n");
   printf("\t---------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      printf("\n\tBitte geben Sie den unteren Temeraturwert an [%cC]: ",cg);
	  fflush(stdin);
      scanf("%f",&tu);
	  // Umrechnung in Kelvin
	  tu += 273.;
	  printf("\tBitte geben Sie den oberen  Temeraturwert an [%cC]: ",cg);
	  fflush(stdin);
      scanf("%f",&tm);
	  // Umrechnung in Kelvin
	  tm += 273.;
	  printf("\tBitte geben Sie die Schrittweite an [%cC]         : ",cg);
	  fflush(stdin);
      scanf("%f",&delta_t);
	  printf("\n\tBitte geben Sie die Achsenl%cnge an [cm]          : ",c1);
	  fflush(stdin);
      scanf("%f",&achsenlaenge);
	  b = 3440.;
      ro = 5000.;
	  ru = ro * exp(b*(1./tu - 1./293.));
	  rm = ro * exp(b*(1./tm - 1./293.));
	  if (rm > ru)
	  {
		  yo = rm;
		  yu = ru;
	  }
	  else
	  {
		  yo = ru;
		  yu = rm;
	  }
	  // Ermittlung der oberen Dekade
	  od = log10(yo) + 1;
	  // Ermittlung der unteren Dekade
	  ud = log10(yu);
	  // Anzahl der Dekaden
	  dk = od - ud;
	  // Ausgabe
	  printf("\n");
	  printf("\n\t+----------------------------------------+");
	  printf("\n\t|     Heissleiter / log. Einteilung      |");
	  printf("\n\t+----------------------------------------+");
      printf("\n\t|   t [%cC]   |   RT [Ohm]   |   l [cm]   |",cg);
	  printf("\n\t+----------------------------------------+");
      for (t = tu; t <= tm; t += delta_t)
	  {
	     rt = ro * exp(b*(1./t - 1./293.));	
		 lc = achsenlaenge / dk * (log10(rt) - 1.);
		 printf("\n\t|  %7.1f   |   %8.2f   |   %6.2f   |",t-273, rt, lc);
	  }
	  printf("\n\t+----------------------------------------+");
	  printf("\n\t| Zeichnungsmassstab:                    |");
	  printf("\n\t| -------------------                    |");
	  printf("\n\t| Gesamth%che der Zeichnung [cm]:%8.2f |",c3,achsenlaenge);
	  printf("\n\t| Anzahl der Dekaden           :%8i |",dk);
	  printf("\n\t| Abstand zwischen Dekaden [cm]:%8.2f |",achsenlaenge / dk);
	  printf("\n\t| Beschriftung gr%c%cte Dekade   :%8i |",c3,c4,(int)pow(10.,od));
	  printf("\n\t| Beschriftung kleinste Dekade :%8i |",(int)pow(10.,ud));
	  printf("\n\t+----------------------------------------+");
      printf("\n\n\tM%cchten Sie eine weitere Berechnung durchf%chren?\n",c3,c2);
      printf("\t(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}