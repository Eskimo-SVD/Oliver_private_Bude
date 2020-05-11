/* int_limit.c */
#include <stdio.h>
#include <limits.h>

int main(void) {
   printf("int-Wert mindestens : %d\n", INT_MIN);
   printf("int-Wert maximal    : %d\n", INT_MAX);
   printf("unsigned int max.   : %u\n", UINT_MAX);
   printf("int benötigt %d Byte (%d Bit) Speicher\n",
      sizeof(int), sizeof(int) * CHAR_BIT);
   return 0;
}

