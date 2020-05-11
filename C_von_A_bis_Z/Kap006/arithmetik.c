/* arithmetik.c */
#include <stdio.h>

int main(void) {
   int zahl1,zahl2,zahl3;
   int ergeb;

   zahl1=10;
   zahl2=20;
   zahl3=30;

   printf("Zahl 1= %d\n",zahl1);
   printf("Zahl 2= %d\n",zahl2);
   printf("Zahl 3= %d\n",zahl3);

   // Möglichkeit 1: zuerst Berechnung, dann Ausgabe
   ergeb=zahl1+zahl2+zahl3;
   printf("Summe aller Zahlen:%d\n",ergeb);

   // Möglichkeit 2: wie oben, nur mit Ausgabe in einem Schritt
   ergeb=zahl3-zahl2;
   printf("%d - %d = %d\n",zahl3,zahl2,ergeb);

   /* Möglichkeit 3: mit Anzeige
    * und Berechnung am Ende der
    * 'printf'-Anweisung         */
   printf("%d * %d = %d\n",zahl1,zahl1,zahl1*zahl1);

   // Möglichkeit 4: weitere 'printf'-Berechnung
   printf("Zahl 3 / Zahl 1 =%d\n",zahl3/zahl1);

   // Möglichkeit 5: wieder eine mit 'printf'
   printf("Zahl 1 + x-Beliebige Zahl =%d\n",zahl1+11);

   // Ein Klammerbeispiel
   ergeb=(zahl1+zahl2)/zahl3;
   printf("(%d + %d)/%d = %d\n",zahl1,zahl2,zahl3,ergeb);
   return 0;
}

