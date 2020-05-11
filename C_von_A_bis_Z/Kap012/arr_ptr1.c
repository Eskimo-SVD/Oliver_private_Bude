/* arr_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int element[8]= { 1, 2, 4, 8, 16, 32, 64, 128 };
   int *ptr;
   int i;

   ptr = element;
   printf("Der Wert auf den *ptr zeigt ist %d\n", *ptr);
   printf("Durch *ptr+1 zeigt er jetzt auf %d\n", *(ptr+1));
   printf("*(ptr+3) = %d\n", *(ptr+3));
   printf("\nJetzt alle zusammen : \n");
   for(i=0; i<8; i++)
      printf("element[%d]=%d \n", i, *(ptr+i));
   return EXIT_SUCCESS;
}

