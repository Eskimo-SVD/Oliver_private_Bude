/* sizeof_type.c */
#include <stdio.h>

int main(void) {
   printf("char     : %d Byte\n" , sizeof(char));
   printf("int      : %d Bytes\n", sizeof(int));
   printf("long     : %d Bytes\n", sizeof(long int));
   printf("float    : %d Bytes\n", sizeof(float));
   printf("double   : %d Bytes\n", sizeof(double));
   printf("66       : %d Bytes\n", sizeof(66));
   printf("Hallo    : %d Bytes\n", sizeof("Hallo"));
   printf("A        : %d Bytes\n", sizeof((char)'A'));
   printf("34343434 : %d Bytes\n", sizeof(34343434));
   return 0;
}

