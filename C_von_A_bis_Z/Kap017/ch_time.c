/* ch_time.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __unix__
      #include <sys/stat.h>
      #include <sys/types.h>
#else
      #include <sys\stat.h>
#endif

int main(int argc, char *argv[]) {
   struct stat attribut;
   unsigned long sizeofall=0;

   if(argc == 1) {
      if(stat(*argv, &attribut) == -1) {
         fprintf(stderr,"Fehler bei stat....\n");
         return EXIT_FAILURE;
      }
      else {
         printf("Größe von %s = %ld Bytes\n",
            *argv,attribut.st_size);
         printf("letzter Zugriff : %s",
            ctime(&attribut.st_atime));
         printf("letzte Aenderung: %s",
            ctime(&attribut.st_mtime));
         return EXIT_SUCCESS;
      }
   }
   else {
      while(*++argv) {
         if(stat(*argv, &attribut) == -1) {
            fprintf(stderr,"Fehler bei stat....\n");
            return EXIT_FAILURE;
         }
         else {
            printf("Größe von %s = %ld Bytes\n",
                *argv,attribut.st_size);
            printf("letzter Zugriff : %s",
               ctime(&attribut.st_atime));
            printf("letzte Aenderung: %s\n",
               ctime(&attribut.st_mtime));
            sizeofall += attribut.st_size;
         }
      }
   } 
   printf("Größe aller Dateien in der "
          "Kommandozeile = %ld Bytes",sizeofall);
   printf("= %ld KB\n",sizeofall/=1024);
   return EXIT_SUCCESS;
}

