/* inttypes.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
   int_least8_t i8;
   int_least32_t i32;

   printf("Wert für int_least8_t eingeben : ");
   scanf("%" SCNdLEAST8 , &i8 );
   printf("Wert für int_least32_t eingeben: ");
   scanf("%" SCNdLEAST32 , &i32 );
    
   printf("i8  : " "%10" PRIdLEAST8 "\n", i8 );
   printf("i32 : " "%10" PRIdLEAST32 "\n", i32 );
  
   return EXIT_SUCCESS;
} 

