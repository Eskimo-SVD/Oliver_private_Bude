/* remove_dir_unix.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
   char pfadname[200];
   char deletefiles[200];

   printf("Welchen Ordner wollen Sie löschen : ");
   scanf("%189s",pfadname);
   strcpy(deletefiles,"rm -rf ");
   strcat(deletefiles,pfadname);
   strcat(deletefiles,"/*");
   printf("%s\n",deletefiles);
   system(deletefiles);
   if(rmdir(pfadname) == -1) {
      printf("Konnte Verzeichnis %s nicht löschen!!\n",pfadname);
      printf(" --> (%s)\n", strerror(errno));  
   }
   return EXIT_SUCCESS;
}


