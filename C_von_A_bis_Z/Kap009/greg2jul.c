/* greg2jul.c */
#include <stdio.h>

/* Umrechnung vom gregorianischen zum julianischen Datum */
void greg2jul(int tag, int monat, int jahr) {
   int k, l, jd;
   k = (monat - 14) / 12;
   l = jahr + k + 4800;
   jd = tag - 32075 + 1461 *l / 4 + 367 *
      ((monat-2-12*k) / 12) - 3 * ((l+100) / 100) / 4;
   printf(" sind %d Tage vergangen\n",jd);
}

int main(void) {
   int tag,monat,jahr;

   printf("Eingabe (Tag)  : ");
   scanf("%d",&tag);
   printf("Eingabe (Monat): ");
   scanf("%d",&monat);
   printf("Eingabe (Jahr) : ");
   scanf("%d",&jahr);

   printf("Seit dem 1.1.4713 v.Chr. bis %2d.%2d.%4d",
      tag,monat,jahr);
   greg2jul(tag, monat, jahr);
   return 0;
}

