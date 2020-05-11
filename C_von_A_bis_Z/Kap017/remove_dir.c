/* remove_dir.c */
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

int makedir(char *dir) {
   if(mkdir(dir MODUS != -1)
      if(chdir(dir) != -1)
         return 0;
   return -1;
}

int main(void) {
   char pfadname[200];

   printf("Wie soll der neue Ordner heissen : ");
   scanf("%199s",pfadname);

   if(makedir(pfadname) == -1) {
      printf("Konnte kein neues Verzeichnis erstellen\n");
      printf(" --> (%s)\n", strerror(errno));  
   }
   /* testfile im Verzeichnis erstellen */
   fopen("testfile","w");

   if(rmdir(pfadname) == -1) {
      printf("Konnte Verzeichnis %s nicht löschen!!\n",pfadname);
      printf(" --> (%s)\n", strerror(errno));  
   }
   return EXIT_SUCCESS;
}

