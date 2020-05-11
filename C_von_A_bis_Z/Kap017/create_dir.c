/* create_dir.c */
#ifdef __unix__
   #include <sys/types.h>
   #include <sys/stat.h>
   #define MODUS ,0711)
#elif __WIN32__ || _MS_DOS_
    #include <dir.h>
    #define MODUS )
#else
    #include <direct.h>  /* Visual C++ */
    #define MODUS )
#endif
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char pfadname[200];

   printf("Wie soll der neue Ordner heissen: ");
   scanf("%199s",pfadname);
   if(mkdir(pfadname MODUS == -1) /*Nicht schön, aber portabler*/
      printf("Konnte kein neues Verzeichnis erstellen\n");
   else
      printf("Neues Verzeichnis namens %s erstellt\n",pfadname);
   return EXIT_SUCCESS;
}

