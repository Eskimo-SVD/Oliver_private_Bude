/* file_size.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static int filesize( const char *name ) {
   struct stat st;
   if(stat(name , &st) < 0) {
      fprintf(stderr, "Fehler bei stat: %s\n", strerror(errno));
      return -1;
    }
   printf("Gr��e in st_size  : %d Bytes\n",(int)st.st_size);
   return 1;
}

int main(int argc, char **argv) {
   const char *ptr;

   if(argc < 2) {
         printf("usage: %s datei\n",argv[0]);
         return EXIT_FAILURE;
      }
   ptr = argv[1];
   /* Gr��e der Datei abfragen */
   if( filesize( ptr ) < 0)
      return EXIT_FAILURE;
   return EXIT_SUCCESS;
}
