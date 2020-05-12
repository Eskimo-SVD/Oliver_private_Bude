/* my_stat.c */
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>

int main (int argc, char **argv) {
  DIR *dir;

  struct dirent *dirzeiger;
  const char *rwx = "rwxrwxrwx";
  int bits[]= {
     S_IRUSR,S_IWUSR,S_IXUSR,/*Zugriffsrechte User*/
     S_IRGRP,S_IWGRP,S_IXGRP,/*Zugriffsrechte Gruppe*/
     S_IROTH,S_IWOTH,S_IXOTH /*Zugriffrechte der Rest*/
  };
  /* Arbeits-Verzeichnis �ffnen */
  if((dir=opendir(".")) == NULL) {
    fprintf(stderr,"Fehler bei opendir: %s\n", strerror(errno));
    return (EXIT_FAILURE);
  }

  /* Das komplette Verzeichnis auslesen */
  while((dirzeiger=readdir(dir)) != NULL) {
    struct stat attribut;
    int i;
    char l_rwx[10];
    l_rwx[9] = '\0';

    if(stat(dirzeiger->d_name, &attribut) == -1) {
      fprintf(stderr,"Fehler bei stat: %s\n", strerror(errno));
      return (EXIT_FAILURE);
    }
    /* Dateiart erfragen */
    if( S_ISREG(attribut.st_mode) )
      printf("Regul�re Datei           : ");
    else if( S_ISDIR(attribut.st_mode) )
      printf("Verzeichnis              : ");
    else if( S_ISCHR(attribut.st_mode) )
      printf("zeichorient. Ger�tedatei : ");
    else if( S_ISBLK(attribut.st_mode) )
      printf("blockorient. Ger�tedatei : ");
    else if( S_ISFIFO(attribut.st_mode) )
      printf("FIFO oder named Pipe     : ");
    else
      printf("Unbekannte Datei          : ");
    /* Dateinamen ausgeben */
    printf("%-20s [",dirzeiger->d_name);
    /* Einfache Zugriffsrechte erfragen */
    l_rwx[0]='\0';
    for(i=0; i<9; i++) { /*Wenn nicht 0, dann gesetzt*/
      l_rwx[i]=(attribut.st_mode & bits[i]) ? rwx[i] : '-';
    }
    l_rwx[9]='\0';
    printf("%s]\n",l_rwx);
  }
  closedir(dir);
  return EXIT_SUCCESS;
}
