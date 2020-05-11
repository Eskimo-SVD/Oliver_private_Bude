/* file_chk.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
      #include <unistd.h>
      #include <sys/stat.h>
      #include <sys/types.h>
#else
      #include <sys\stat.h>
#endif

int main(int argc, char *argv[]) {
   struct stat attribut;

   if(argc == 1) {
      printf("%s = ",*argv);
      if(stat(*argv, &attribut) == -1) {
         fprintf(stderr,"Fehler bei stat ...\n");
         return EXIT_FAILURE;
      }
      if(attribut.st_mode & S_IFREG)
         printf("Reguläre Datei\n");
      else if(attribut.st_mode & S_IFDIR)
         printf("Directory\n");
      else if(attribut.st_mode & S_IFCHR)
         printf("Gerätedatei\n");
      else
         printf("Unbekannte Datei\n");
   }
   else {
      while(*++argv) {
         printf("%s = ",*argv);
         if(stat(*argv, &attribut) == -1) {
            fprintf(stderr,"Fehler bei stat (2)...\n");
            return EXIT_FAILURE;
         }
         if(attribut.st_mode & S_IFREG)
            printf("Reguläre Datei\n");
         else if(attribut.st_mode & S_IFDIR)
            printf("Directory\n");
         else if(attribut.st_mode & S_IFCHR)
            printf("Gerätedatei\n");
         else
            printf("Unbekannte Datei\n");
      }/*Ende while*/
   }
   return EXIT_SUCCESS;
}

