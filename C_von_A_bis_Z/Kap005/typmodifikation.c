/* typmodifikation.c */
#include <stdio.h>

int main (void) {
   short sval;
   double dval;
   long long llval;
   signed char cval;

   printf("Ein short-Wert     : ");
   scanf("%hd", &sval);
   printf("Ein double-Wert    : ");
   scanf("%lf", &dval);
   printf("Ein long long-Wert : ");
   scanf("%Ld", &llval);
   printf("Ein char-Wert : ");
   scanf("%hhd", &cval);

   printf("Der short-Wert ist  %hd\n", sval);
   printf("Der double-Wert ist %lf\n", dval);
   printf("Der long long-Wert ist %Ld\n", llval);
   printf("Der char-Wert ist %hhd\n", cval);
   return 0;
}
