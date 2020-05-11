/* ptr9.c */
#include <stdio.h>
#include <stddef.h>  /* für ptrdiff_t */
#include <stdlib.h>

int main(void) {
   char *ptr1, *ptr2;
   ptrdiff_t diff; /* Primitiver Datentyp */
   char string[] = { "Hallo Welt\n" };

   /* ptr2 auf Anfangsadresse von string */
   ptr2 = string;  
   /* ptr1 6 Bytes weiter von der Adresse ptr2 platzieren */
   ptr1 = ptr2 + 6;
   /* Wie weit liegen beide Zeiger voneinander entfernt */
   diff = ptr1-ptr2;
   printf("Differenz der beiden Zeiger : %d Bytes\n",diff); 
   printf("%s",ptr1);  /* Welt       */
   printf("%s",ptr2);  /* Hallo Welt */
   return EXIT_SUCCESS;
}

