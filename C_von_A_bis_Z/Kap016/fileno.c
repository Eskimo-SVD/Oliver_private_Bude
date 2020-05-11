/* fileno.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
    #include <unistd.h>
#else
    #include <io.h>
#endif

int main(void) {
   FILE *fz;
   int fd,fd2;
   char datei[255];

   printf("File-Deskriptoren zu stdin, stdout und stderr : ");
   printf("%d, %d und %d\n", 
      fileno(stdin),fileno(stdout),fileno(stderr));
   printf("Welche Datei wollen Sie öffnen : ");
   scanf("%s",datei);

   fz=fopen(datei, "r");
   if(!fz) {
      perror(NULL);
      return EXIT_FAILURE;
   }
   fd = fileno(fz);
   printf("File-Deskriptor zur Datei %s lautet %d\n",datei,fd);
   fd2=dup(fd);
   printf("File-Deskriptor, der kopiert wurde lautet %d\n",fd2);
   return EXIT_SUCCESS;
}

