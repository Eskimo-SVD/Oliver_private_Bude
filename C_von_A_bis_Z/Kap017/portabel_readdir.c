/* portabel_readdir.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
#include <dirent.h>
#include <sys/types.h>

/* UNIX-Funktion zum Ausgeben des kompl. Verzeichnisses */
void list_dir(const char *path) {
   DIR *dirptr; 
   struct dirent *dir; 

   if ((dirptr=opendir(path)) == NULL) 
      return;
   while((dir=readdir(dirptr)) != NULL) 
      printf("%s\n",dir->d_name);
   closedir(dirptr);
}

#elif __WIN32__ || _MSC_VER
#include <windows.h>
/* Win32-Funktion zum Ausgeben des kompl. Verzeichnisses */
void list_dir(const char *path) { 
   WIN32_FIND_DATA dir;
   HANDLE fhandle;
   char directory[256];

   /* Unsicher, besser wäre falls vorhanden snprintf() */
   sprintf(directory,"%s\\*.*",path);
   /* Handle auf das Verzeichnis director */
   if ((fhandle=FindFirstFile(directory,&dir)) !=
                             INVALID_HANDLE_VALUE) {
      do {  /* Verzeichnis auslesen */
         printf("%s\n", dir.cFileName);
      } while(FindNextFile(fhandle,&dir));
   }
   FindClose(fhandle);
}
#endif 

int main(int argc,char *argv[]) { 
   if (argc < 2)
      list_dir(".");
   else
      list_dir(argv[1]);
   return EXIT_SUCCESS;
}

