/* b_c_file.c */
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   struct stat statpuffer;

   if(argc == 1) {
      fprintf(stderr, "usage: %s Datei1 Datei2 ....\n", *argv);
      return EXIT_FAILURE;
   }
   while(*++argv) {
      printf("%s: ",*argv);
      if(stat(*argv, &statpuffer) == -1)
         fprintf(stderr,"Fehler bei stat...\n");
      else {
         printf("dev = %2d/%2d",major(statpuffer.st_dev),
                                minor(statpuffer.st_dev));
         if(S_ISCHR(statpuffer.st_mode)||
            S_ISBLK(statpuffer.st_mode)) {
            printf("-> rdev = %2d/%2d (%s",
               major(statpuffer.st_rdev),
               minor(statpuffer.st_rdev),
               (S_ISCHR(statpuffer.st_mode))?"zeichen" :"block");
            printf("orientiert");
         }
      }
      printf("\n");
   } 
   return EXIT_SUCCESS;
}

