/* alignment2.c */
#include <stdio.h>
#include <stdlib.h>

/* L�sst sich dieses Listing nicht �bersetzen,
 * entfernen Sie __attribute__((packed)) und
 * verwenden stattdessen #pragma pack(1)
 */ 

/* #pragma pack(1) */
struct speicher {
   char x;
   int z;
} __attribute__ ((packed));

int main(void) {
   struct speicher test;

   printf("%u Bytes\n", sizeof(test));
   return EXIT_SUCCESS;
}

