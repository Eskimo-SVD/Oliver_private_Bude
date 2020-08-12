#include "stdafx.h"
/*   �berpr�ft wird ein eingegebener Character-String auf numerischen Inhalt

     Eingabe:  string --> zu pr�fende Zeichenkette
               anz    --> Anzahl zu untersuchende Zeichen in String

     R�ckgabe: 0 - Zeichenkette enth�lt nur numerische Zeichen (g�ltig, o.k.)
               1 - Zeichenkette enth�lt ung�ltige (nichtnumerische) Zeichen */
int numpruef(char *string, int anz)
{
   char num[] = {'0','1','2','3','4','5','6','7','8','9','\0'};
   int  i, j, merk;
   // �berpr�fen der einzelnen Stellen in string
   for(i = 0; i < anz; i++)
   {
      if (string[i] == ' ') string[i] = '\0';
      merk = 1;
      for(j = 0; j <= 10; j++)
      {
         if(string[i] == num[j]) merk = 0;
      }
      if(merk == 1) return (1);
   }
   return(merk);
}