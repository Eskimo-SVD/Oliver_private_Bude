/* manipulate_time.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
   FILE *q,*z;
   struct stat attribut;
   char buf[1024];
   int i;
   struct utimbuf zeit;  /*Siehe Funktion utimes()*/

   if(stat(argv[1],&attribut) < 0) {
      fprintf(stderr, "Fehler bei stat ...\n");
      return EXIT_FAILURE;
   }
   zeit.actime = attribut.st_atime;
   zeit.modtime= attribut.st_mtime;

   q=fopen(argv[1],"r");
   z=fopen(argv[2],"w");
   if(q == NULL || z == NULL) {
      fprintf(stderr,"Fehler bei fopen ...\n");
      return EXIT_FAILURE;
   }
   while( (i=fread(buf, 1, 1024, q)) > 0 )
      fwrite(buf, 1, i, z);

   /* Wichtig!!! Ohne den Stream zu schlieﬂen, wird die
    * aktuelle Zeit verwendet, da die Datei erst nach
    * return 0 beendet wird  */
   fclose(q);
   fclose(z);
   /* Jetzt die Zeit von quelle in ziel eintragen */
   if(utime(argv[2], &zeit) < 0) {
      printf("Fehler bei utime() ...\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

