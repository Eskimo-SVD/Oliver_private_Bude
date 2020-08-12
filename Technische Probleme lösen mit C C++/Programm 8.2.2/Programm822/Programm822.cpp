// Programm822.cpp: Hauptprojektdatei.

#include "stdafx.h"

using namespace System;

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>


using namespace System;

void main()
{
   int i;
   char * farbe[]={"schwarz","braun",  "rot", "orange","gelb","gruen",
	               "blau",   "violett","grau","weiss", "gold","silber","farblos"};
   char gr[]=  {'x','x','x','x','x','x','x','x','x','x','-','-','-',
                'x','x','x','x','x','x','x','x','x','x','-','-','-',
                'x','x','x','x','x','x','x','x','x','x','x','x','-',
                '-','x','x','-','-','x','-','-','-','-','x','x','x'};
   float twert[]={0.,1.,2.,0.,0.,0.5,0.,0.,0.,0.,5.,10.,20.};
   char cfarbe[7], rep,cProzent='%';
   int ring_farbe[4], rf;
   float widerstand;

   do
   {
      system("cls");
      printf("\n\n\tFarbtabelle:\n");
      printf("\t============\n\n");
      printf("\t                             R i n g\n");
      printf("\t| Farbe   | Kennzifer | 1 | 2 | 3 | 4 |\n");
      printf("\t+---------+-----------+---+---+---+---+\n");
      for (i = 0; i <= 12; i++)
      {
         strcpy(cfarbe,farbe[i]);
         printf("\t| %7s | %9i | %c | %c | %c | %c |\n",cfarbe,i,gr[i],gr[i+13],gr[i+26],gr[i+39]);
      }
      printf("\n\n");
      for (i = 1; i <= 4; i++)
      {
         do
         {
            printf("\tBitte Kennziffer fuer den %i.Ring angeben: ",i);
            scanf("%i",&ring_farbe[i-1]);
         }
         while(gr[(i-1)*13+ring_farbe[i-1]]!='x');
      }
      system("cls");
	  // Korrektur 3.Ring gold oder silber
	  rf = ring_farbe[2];
	  if (rf == 10) rf = -1;
	  if (rf == 11) rf = -2;
      widerstand = (ring_farbe[0]*10.+ring_farbe[1])*pow(10.,rf);
      printf("\n\n\tDer von Ihnen definierte Widerstand mit der Kennung\n\n");
      printf("\t%s - ",strcpy(cfarbe,farbe[ring_farbe[0]]));
      printf("%s - ",  strcpy(cfarbe,farbe[ring_farbe[1]]));
      printf("%s - ",  strcpy(cfarbe,farbe[ring_farbe[2]]));
      printf("%s - ",  strcpy(cfarbe,farbe[ring_farbe[3]]));
      if (widerstand < 1000)
	  {
          printf("\tbesitzt den Wert von %.3f Ohm",widerstand);
	  }
	  else if (widerstand < 1000000)
	  {
		  printf("\tbesitzt den Wert von %.3f kOhm",widerstand/1000.);
	  }
	  else
	  {
		  printf("\tbesitzt den Wert von %.3f MOhm",widerstand/1000000.);
	  }
      printf(" mit +-%2.1f%c Toleranz",twert[ring_farbe[3]],cProzent);
      printf("\n\n\tweitere Auswertungen? (j/n) ");
      scanf("%s",&rep);
   }
   while(rep=='j'||rep=='J');
}