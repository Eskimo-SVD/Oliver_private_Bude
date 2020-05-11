/* read_dir.c */
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   DIR *dir;
   struct dirent *dirzeiger;

   if(argc != 2) {
      fprintf(stderr,"Benutzung : %s Directory\n", argv[0]);
      return EXIT_FAILURE;
   }
   /* Das Verzeichnis öffnen */
   if((dir=opendir(argv[1])) == NULL) {
      fprintf(stderr,"Fehler bei opendir ...\n");
      return EXIT_FAILURE;
   }
   /* Das komplette Verzeichnis auslesen */
   while((dirzeiger=readdir(dir)) != NULL)
      printf("%s\n",(*dirzeiger).d_name);
   /* Lesezeiger wieder schliessen */
   if(closedir(dir) == -1)
      printf("Fehler beim Schliessen von %s\n", argv[1]);
   return EXIT_SUCCESS;
}

