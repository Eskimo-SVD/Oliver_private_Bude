/* void_ptr2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str1[]="Hallo";
   char str2[]="Hallo";
   int num1[] = { 1,2,3,4,5,6 };
   int num2[] = { 1,3,5,7,9,1 };
   int cmp;
   /* Casts sind nicht unbedingt nötig */
   cmp=memcmp( (char *)str1, (char *)str2, sizeof(str1));
   if(cmp ==0)
      printf("Beide Strings sind gleich\n");
   else
      printf("Die Strings sind nicht gleich\n");
   /* Casts sind nicht unbedingt nötig */
   cmp=memcmp((int *)num1,(int *)num2, sizeof(num1)/sizeof(int));
   if(cmp == 0)
      printf("Der Inhalt der beiden Zahlenarrays ist gleich\n");
   else
      printf("Die Zahlenarrays sind unterschiedlich\n");
   return EXIT_SUCCESS;
}

