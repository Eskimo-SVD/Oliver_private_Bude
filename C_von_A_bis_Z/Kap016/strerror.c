/* strerror.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
   FILE *fp;

   fp = fopen("keinedatei.dat", "r");
   if (NULL == fp) {
      fprintf(stderr, "%s\n", strerror(errno));
      return EXIT_FAILURE;
   }   
   return EXIT_SUCCESS;
}

