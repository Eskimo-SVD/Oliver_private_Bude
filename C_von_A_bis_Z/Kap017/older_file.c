/* older_file.c */
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

time_t st_mTime(char *name) {
   struct stat s;

   if (stat(name, &s)) {
      perror(name);
      exit(EXIT_FAILURE);
   }
   return s.st_mtime;
}

int main(int argc, char *argv[]) {
   time_t t1, t2;

   if (argc == 3) {
      t1 = st_mTime(argv[1]),
      t2 = st_mTime(argv[2]);
      if(t1 != t2)
         printf("%s ist %s wie %s\n"
          ,argv[1],(t1>t2?"neuer":"älter"),argv[2]);
      else
         printf("Beide Dateien sind gleich alt\n");
   }
   else {
      fprintf(stderr, "Verwendung %s datei1 datei2\n",argv[0]);
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

