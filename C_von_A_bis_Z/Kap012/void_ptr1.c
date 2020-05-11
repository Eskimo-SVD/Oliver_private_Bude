/* void_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int a = 10;
   char *string = "void-Zeiger";
   void *ptr;

   /* void-Zeiger auf Variable int a */
   ptr = (int *)&a;
   printf("ptr = %p a=%p\n",ptr,&a);
   /* void-Zeiger auf string */

   ptr = (char *)string;
   printf("ptr = %p string = %p\n",ptr,string);
   return EXIT_SUCCESS;
}

