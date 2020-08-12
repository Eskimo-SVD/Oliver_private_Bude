#include "stdafx.h"
/*   �berpr�ft wird eine eingegebene Zahl, ob sie f�r ein Schaltjahr
     steht oder nicht
     Eingabe:  jahreszahl
     R�ckgabe: 0 - �berpr�fte Zahl steht f�r kein Schaltjahr
               1 - �berpr�fte Zahl steht f�r ein Schaltjahr       */
int schaltpruef(int jahreszahl)
{
   int pruef;
   pruef = jahreszahl / 4;
   if (jahreszahl == pruef*4)
   {
      pruef = jahreszahl / 100;
      if (jahreszahl == pruef*100)
      {
         pruef = jahreszahl / 400;
         if (jahreszahl == pruef*400) return (1);
         else                         return (0);
      }
      else                            return (1);
   }
   else                               return (0);
}