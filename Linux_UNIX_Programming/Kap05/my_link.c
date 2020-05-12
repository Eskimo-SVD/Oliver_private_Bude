/* my_link.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define HARD_LINK "hard_link"
#define SYM_LINK  "sym_link"
#define MAX 255

static int attribute( const char *name ) {
  struct stat st;
  if(stat(name , &st) < 0) {
    fprintf(stderr, "Fehler bei stat: %s\n", strerror(errno));
    return -1;
  }
  printf("Anzahl Links  : %d\n",st.st_nlink);
  return 1;
}

int main(int argc, char **argv) {
  const char *ptr;
  char buf[MAX];
  int n;

  if(argc < 2) {
    printf("usage: %s datei\n", argv[0]);
    return EXIT_FAILURE;
  }

  ptr = argv[1];
  /* Anzahl der Links erfragen */
  if( attribute( ptr ) < 0)
    return EXIT_FAILURE;

  /* Einen harten Link erzeugen */
  if((link(ptr, HARD_LINK)) == -1) {
    printf("Konnte keinen Hardlink erstellen\n");
    return EXIT_FAILURE;
  }
  printf("Nach dem Funktionsaufruf von link()\n");
  /* Wieder die Anzahl der Links erfragen */
  if(attribute( ptr ) < 0)
    return EXIT_FAILURE;

  if((symlink(ptr, SYM_LINK)) == -1) {
    printf("Konnte keinen Sym. Link erstellen\n");
    return EXIT_FAILURE;
  }
  printf("Nach dem Funktionsaufruf von symlink()\n");
  /* Wieder die Anzahl der Links erfragen */
  if(attribute( ptr ) < 0)
    return EXIT_FAILURE;
  /* Denn Namen anzeigen, worauf der symbolische Link verweist */
  n=readlink(SYM_LINK, buf, MAX);

  printf("Der symbolische Link \"%s\"  zeigt auf"
         " \"%.*s\"\n",SYM_LINK, n, buf);
  /* Links wieder entfernen */
  unlink(HARD_LINK);
  unlink(SYM_LINK);
  return EXIT_SUCCESS;
}
