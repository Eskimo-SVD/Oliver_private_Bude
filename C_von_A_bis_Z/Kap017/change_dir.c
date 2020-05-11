/* change_dir.c */
#ifdef __linux__
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <unistd.h>
   #define MODUS ,0711)
#elif _WIN32__ || _MS_DOS_
    #include <dir.h>
    #define MODUS )
#else
    #include <direct.h>
    #define MODUS )
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
   char pfadname[200];

   printf("Wie soll der neue Ordner heissen : ");
   scanf("%199s",pfadname);
   if(mkdir(pfadname MODUS == -1)
      printf("Konnte kein neues Verzeichnis erstellen\n");
   else {
      printf("Neues Verzeichnis namens %s erstellt\n", pfadname);
      printf(" --> (%s)\n", strerror(errno));
   }

   /* Jetzt wollen wir in das neue Verzeichnis wechseln */
   if(chdir(pfadname) == -1) {
      printf("Konnte nicht in das Verzeichnis wechseln\n");
      return EXIT_FAILURE;
   }
   else
      printf("Erfolgreich nach %s gewechselt!\n", pfadname);
   /*testfile im Verzeichnis erstellen*/
   fopen("testfile", "w");
   return EXIT_SUCCESS;
}

