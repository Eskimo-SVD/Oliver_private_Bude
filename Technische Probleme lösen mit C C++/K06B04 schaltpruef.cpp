#include "stdafx.h"
/*   Überprüft wird eine eingegebene Zahl, ob sie für ein Schaltjahr
     steht oder nicht
     Eingabe:  jahreszahl
     Rückgabe: 0 - überprüfte Zahl steht für kein Schaltjahr
               1 - überprüfte Zahl steht für ein Schaltjahr       */
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