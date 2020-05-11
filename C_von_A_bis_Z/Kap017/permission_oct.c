/* permission_oct.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
   struct stat attribut;

   while(*++argv) { /*Einzelne Argumente durchlaufen*/
      printf("%18s = ",*argv);
      if(stat(*argv, &attribut) == -1) {
         fprintf(stderr,"Fehler bei stat?!?...\n");
         return EXIT_FAILURE;
      }
      printf("%o\n", attribut.st_mode & 0777);
   }
   return EXIT_SUCCESS;
}

