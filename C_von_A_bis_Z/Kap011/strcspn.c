/* strcspn.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[] = "Das ist ein Teststring";
   int  pos;

   pos = strcspn( string, "Ttg" );
   printf("Erstes Auftreten von T, t oder g an Pos.: %d\n",pos);
   return EXIT_SUCCESS;
}

