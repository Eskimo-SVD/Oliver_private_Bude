/* check_access.c */
#ifdef __unix__
    #include <unistd.h>
    #define EXIST F_OK
    #define EXEC  X_OK
    #define WRITE W_OK
    #define READ  R_OK
#else
    #include <io.h>
    #define EXIST 00
    #define EXEC  01
    #define WRITE 02
    #define READ  04
#endif
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if(argc == 1) {
      fprintf(stderr, "Mindestens eine Datei angeben!\n");
      return EXIT_FAILURE;
   }
   while(*++argv) {
      printf("%s : \n", *argv);
      /* Existiert die Datei? */
      if(access(*argv, EXIST) != -1) {
         /* Lesen und Schreiben nicht erlaubt */
         if(access(*argv, WRITE|READ) == -1) {
            /* Nur lesen? */
            if(access(*argv, READ) != -1)
               printf("... ist lesbar\n");
            /* Nur schreiben? */
            else if(access(*argv, WRITE) != -1) 
               printf("... ist schreibbar\n");
         }
         else
            printf("ist Lesen und schreiben erlaubt\n");
         /* Datei ausführbar? */
         if(access(*argv, EXEC) != -1)
            printf("... ist ausführbar\n");
      }
      else {
         fprintf(stderr, "...existiert nicht\n");
         return EXIT_FAILURE;
      }
   } 
   return EXIT_SUCCESS;
}

