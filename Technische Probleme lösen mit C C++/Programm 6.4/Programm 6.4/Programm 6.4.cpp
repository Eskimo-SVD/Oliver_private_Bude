// Programm 6.4.cpp: Hauptprojektdatei.
// Programm zur Überprüfung von Schaltjahren
// Autor: Heiderich / Meyer
// -----------------------------------------
#include "stdafx.h"
#include "numpruef.h"
#include "schaltpruef.h"
#include <stdio.h>
#include <stdlib.h>
using namespace System;
void main()
{
   int i, inum, jahr, ischalt;
   char weiter, eingabe[4], c1 = '\x9a', c2 = '\x81', c3 = '\x84', c4 = '\x94';
   // Begrüßung
   printf("\n\nProgramm zur %cberpr%cfung von Schaltjahren\n",c1,c2);
   printf("-----------------------------------------\n");
   // Beginn der Wiederholungssteuerung
   do
   {
      printf("\nBitte geben Sie eine Jahreszahl ein: --> ");
      // Initialisierung von eingabe
	  for (i = 0; i < 4; i++)
      {
         eingabe[i] = '\0';
      }
	  fflush(stdin);
      scanf("%s",&eingabe);
	  // Numerikprüfung von eingabe
	  inum = numpruef(eingabe, 4);
      if (inum == 0)
      {
	     // Einlesen von eingabe nach jahr
         sscanf(eingabe,"%i",&jahr);
		 // Schaltjahrprüfung
		 ischalt = schaltpruef(jahr);
         if (ischalt==1)
		 {
			printf("\nDie von Ihnen vorgegebene Jahreszahl %i steht f%cr ein Schaltjahr\n",jahr,c2);
		 }
		 else
		 {
			printf("\nDie von Ihnen vorgegebene Jahreszahl %i steht f%cr kein Schaltjahr\n",jahr,c2);
		 }
	  }
	  else
	  {
         printf("\nIhre Eingabe '%s' enth%clt ung%cltige Zeichen!!\n",eingabe,c3,c2);
         printf("Bitte korrigieren!!\n");
      }
      printf("\nM%cchten Sie eine weitere %cberpruefung durchf%chren?\n",c4,c1,c2);
      printf("(W)eiter oder (E)nde. Ihre Wahl: --> ");
      fflush(stdin);
	  scanf("%c",&weiter);
   }
   while(weiter=='w'||weiter=='W');
}