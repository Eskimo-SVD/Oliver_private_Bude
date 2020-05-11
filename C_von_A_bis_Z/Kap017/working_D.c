/* working_D.c */
#ifdef __unix__
    #include <unistd.h>
#elif __WIN32__ || _MS_DOS_
    #include <dir.h>
#else
    #include <direct.h> /* Visual C++ */
#endif
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char puffer[200];

   if(getcwd(puffer,sizeof(puffer)) == NULL) {
      fprintf(stderr, "Fehler bei getcwd ...\n");
      return EXIT_FAILURE;
   }
   printf("Working-Directory: %s\n", puffer);
   return EXIT_SUCCESS;
}

