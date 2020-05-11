/* implizitCasts.c */
#include <stdio.h>

int main(void) {
   // Nachkommateil wird weggelassen
   int float2int = 3.8; 
   // Höherwertigen Bits werden abgeschnitten
   char int2char = 1000; 
   float char2float = 'A'; 
   float long2float = 444444444; 

   printf("float2int : %d\n", float2int ); 
   printf("int2char  : %c\n", int2char ); 
   printf("char2float: %f\n", char2float ); 
   printf("long2float: %f\n", long2float ); 
   return 0; 
}
