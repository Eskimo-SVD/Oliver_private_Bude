// Funktion zum Einlesen von Messwerten
// Autor: Heiderich / Meyer
// ------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void eingabeMesswerte(float x[], float y[], int* anz)
{
   int anzahl, i;
   printf("\n\n\n\tEingabe der Messwerte\n");
   printf("\t---------------------\n\n");
   do
   {
      printf("\tBitte geben Sie die Anzahl ( < 100 !) der Messwerte an: ");
      fflush(stdin);
      scanf("%i",&anzahl);
   }while (anzahl >= 100);
   *anz = anzahl;
   for (i = 0; i < anzahl; i++)
   {
      printf("\n\tx[%2i] = ",i+1);
      fflush(stdin);
      scanf("%f",&x[i]);
      printf("\ty[%2i] = ",i+1);
      fflush(stdin);
      scanf("%f",&y[i]);
   }
}

// Funktion zur Berechnung und
// zur Ausgabe der linearen Funktion
// Autor: Heiderich / Meyer
// ---------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void ausgabeFunktion(float x[],float y[],int anz,float* m,float* b)
{
   float sxy  = 0.0; // Summe xi*yi
   float sx2  = 0.0; // Summe xi*xi
   float sx   = 0.0; // Summe über xi
   float sy   = 0.0; // Summe über yi 
   float sxsy = 0.0; // Produkt der Summen über x und y
   int i;
   for (i = 0; i < anz; i++)
   {
      sxy  = sxy + x[i] * y[i];
      sx2  = sx2 + x[i] * x[i];
      sx   = sx  + x[i];
      sy   = sy  + y[i];
   }
   *m = (anz * sxy - sx * sy) / (anz * sx2 - sx * sx); 
   *b = (sx2 * sy - sx * sxy) / (anz * sx2 - sx * sx);
   // Ausgabe der linearen Funktion
   printf("\n\n\tdie lineare Funktion zu den %2i Koordinatenpaaren lautet:",anz);
   printf("\n\n\t y = %f * x ",*m);
   if (*b >= 0.0) printf("+ %f",*b);
   else           printf("%f",*b);
   getch();
}

// Funktion zur Gegenüberstellung
// Messwerte / Funktionswerte
// Autor: Heiderich / Meyer
// ------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void gegenueberstellungWerte(float x[],float y[],int anz,float m, float b)
{
   int i;
   float yre; // rechnerischer Funktionswert
   printf("\n\n\t+-----------------------+---------------+\n");
   printf("\t|    Wertepaar (x|y)    | y - errechnet |\n");
   printf("\t+-----------+-----------+---------------+\n");
   printf("\t|     x     |     y     |               |\n");
   printf("\t+-----------+-----------+---------------+\n");
   for (i = 0; i < anz; i++)
   {
      yre = m * x[i] + b;
      printf("\t| %9.3f | %9.3f |    %9.3f  |\n",x[i],y[i],yre);
   }
   printf("\t+-----------+-----------+---------------+\n");
   getch();
}

// Funktion zur Ausgabe der Abweichungen
// Autor: Heiderich / Meyer
// -------------------------------------
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
void gegenueberstellungAbweichung(float x[],float y[],int anz, float m, float b)
{
   float sx2  = 0.0; // Summe xi*xi
   float sx   = 0.0; // Summe über xi
   float sv2  = 0.0; // Summe über vi*vi 
   float delta_m;    // mittlerer Fehler von m
   float delta_b;    // mittlerer Fehler von b
   int i;
   for (i = 0; i < anz; i++)
   {
      sx2  = sx2 + x[i] * x[i];
      sx   = sx  + x[i];
      sv2  = sv2 + pow((y[i] - (m * x[i] + b)),2);
   }
   delta_b = sqrt( (sx2*sv2)/((anz-2)*anz*sx2-(anz-2)*sx*sx) ); 
   delta_m = sqrt( anz * sv2 / (anz * sx2 - sx * sx) );
   // Ausgabe der mittleren Fehler:
   printf("\n\n\tdie Abweichungen betragen zu den %2i Koordinatenpaaren betragen:",anz);
   printf("\n\n\tdelta_m  = %f\n",delta_m);
   printf("\tdelta_b  = %f\n",delta_b);
   printf("\n\tFehlerquadratsumme = %f",sv2);
   getch();
}