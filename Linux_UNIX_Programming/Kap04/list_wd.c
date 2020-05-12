/* list_wd.c */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main (void) {
  DIR *dp;
  struct dirent *ep;
  static int files = 0;

  dp = opendir (".");
  if (dp != NULL) {
      while ((ep = readdir (dp)) != NULL) {
#ifdef _DIRENT_HAVE_D_TYPE
           switch(ep->d_type) {
                 case DT_REG     : printf("Normale Datei : ");
                                   break;
                 case DT_DIR     : printf("Verzeichnis   : ");
                                   break;
                 /* ... */
                 case DT_UNKNOWN : printf("???       : ");
                                   break;
              }
#endif
           printf("%s\n", ep->d_name);
           files++;
        }
      closedir (dp);
    }
  else
      perror ("Kann Verzeichnis nicht �ffnen");
  printf("--- Insg. %d Dateien im Verzeichnis ---\n",files);
  return EXIT_SUCCESS;
}
