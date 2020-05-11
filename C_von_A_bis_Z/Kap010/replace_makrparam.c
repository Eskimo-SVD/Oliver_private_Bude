/* replace_makrparam.c */
#include <stdio.h>
#include <stdlib.h>
/* Bei Linux muss für math.h der Compilerflag -lm 
 * mit angegeben werden:
 * gcc -o strkont strkont.c -lm
 */
#include <math.h>

#define wurzel(zahl)\
   printf(#zahl" von %f = %f\n",zahl,sqrt(zahl))
#define summe(zahl1,zahl2)\
   printf(#zahl1 "+" #zahl2 " = %d\n",zahl1+zahl2)
#define gibaus(string)\
   printf(#string"\n")
#define wertvon(zahl,format)\
   printf(#zahl" = "format"\n",zahl)

int main(void) {
   float Wurzel;
   int Wert1 = 100, Wert2 = 150, integer = 20;
   char character = 's';
   float floating = 5.550f;

   printf("Zahl eingeben : ");
   scanf("%f",&Wurzel);
   wurzel(Wurzel);
   summe(Wert1,Wert2);
   gibaus(Hallo Welt);
   wertvon(character,"%c");
   wertvon(integer,"%d");
   wertvon(floating,"%f");
   return EXIT_SUCCESS;
}

