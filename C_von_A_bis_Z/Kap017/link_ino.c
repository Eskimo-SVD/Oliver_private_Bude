/* link_ino.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
   struct stat attribut;

   while(*++argv) {
      if(stat(*argv,&attribut) < 0) {
         fprintf(stderr, "Fehler bei stat ...\n");
         return EXIT_FAILURE;
       }
       printf("\n%18s\n",*argv);
       printf("Anzahl Links  : %d\n",attribut.st_nlink);
       printf("Inode Nummer  : %d\n\n",attribut.st_ino);
   }
   return EXIT_SUCCESS;
}

