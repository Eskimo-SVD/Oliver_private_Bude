/* check_rwx.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
   struct stat attribut;
   int i;
   char l_rwx[10];
   char rwx[] = "rwxrwxrwx";

   int bits[] = { 
      S_IRUSR,S_IWUSR,S_IXUSR,   /* Zugriffsrechte User    */
      S_IRGRP,S_IWGRP,S_IXGRP,   /* Zugriffsrechte Gruppe  */
      S_IROTH,S_IWOTH,S_IXOTH    /* Zugriffrechte der Rest */
   };
   while(*++argv) { /*Einzelne Argumente durchlaufen*/
      l_rwx[0]='\0';
      printf("%18s = ",*argv);
      if(stat(*argv, &attribut) == -1) {
         fprintf(stderr,"Fehler bei stat?!?...\n");
         return EXIT_FAILURE;
      }
      for(i = 0; i < 9; i++) {
         /* Wenn nicht 0, dann gesetzt */
         if(attribut.st_mode & bits[i]) 
            l_rwx[i]=rwx[i];  /*r,w oder x*/
         else
            l_rwx[i] = '-'; /*wenn nicht gesetzt dann '-'*/
      }
      l_rwx[9]='\0';
      printf("%s\n",l_rwx);
   }/*Ende while*/
   return EXIT_SUCCESS;
}

