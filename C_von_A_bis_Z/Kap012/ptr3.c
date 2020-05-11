/* ptr3.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int x=5;
   int *y;

   printf("Adresse x=%p, Wert x=%d\n", &x, x);

   /*  Führt bei manchen Systemen zum Programmabsturz 
    *  ggf. auskommentieren  */
   printf("Adresse *y=%p, Wert *y=%d(unsinn)\n", &y, *y);
   printf("\ny=&x;\n\n");

   /* y hat jetzt die Adresse von x */
   y =& x;              
   printf("Adresse  x=%p, Wert x=%d\n", &x, x);
   printf("Adresse *y=%p, Wert *y=%d\n", &y, *y);
   printf("\nAdresse auf die y zeigt ist %p\n", y);
   printf("und das ist die Adresse von x = %p\n", &x);

   printf("\nACHTUNG!!!\n\n");
   *y=10;
   printf("*y=10\n\n");
   printf("Adresse  x=%p, Wert  x=%d\n", &x, x);
   printf("Adresse *y=%p, Wert *y=%d\n", &y, *y);
   printf("\nAdresse auf die y zeigt ist %p\n", y);
   printf("weiterhin die von x (%p)\n", &x);
   return EXIT_SUCCESS;
}


