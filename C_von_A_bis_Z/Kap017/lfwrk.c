/* lfwrk.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>

int main(int argc, char *argv[]) {
   struct stat laufwerknr;

   if(argc==1) {
      fprintf(stderr, "usage:%s Datei1 Datei2 Datei3\n", *argv);
      return EXIT_FAILURE;
   }
   while(*++argv) {
      printf("%s = Laufwerk : ",*argv);
      if(stat(*argv, &laufwerknr) == -1) {
         fprintf(stderr,"..Fehler bei stat...!\n");
         return EXIT_FAILURE;
      }
      else
         printf("%c (%d)\n",
            laufwerknr.st_dev + 'A',laufwerknr.st_dev);
   }
   return EXIT_SUCCESS;
}

