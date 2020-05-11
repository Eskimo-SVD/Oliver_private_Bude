/* fdopen.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
   #include <unistd.h>
#else
   #include <io.h>
#endif

int main(void) {
   FILE *fz, *fz2;
   int fd,fd2;
   char datei[255];

   printf("Welche Datei wollen Sie erzeugen: ");
   scanf("%s",datei);

   fz=fopen(datei, "w+");
   if(!fz)
      perror(NULL);
   fd = fileno(fz);
   printf("File-Deskriptor zur Datei %s lautet %d\n",datei,fd);

   fd2=dup(fd);

   printf("Der File-Deskriptor, der kopiert wurde %d\n\n",fd2);

   printf("Wir wollen einen STREAM  oeffnen....\n");
   fz2 = fdopen(fd2, "w");
     if(!fz2)
        perror(NULL);

   fprintf(fz,"Dieser Text steht in %s\n",datei);
   fprintf(fz2,"Dieser Text steht auch in %s\n",datei);
   fprintf(stdout,"Es wurde etwas in die "
                  "Datei %s geschrieben",datei);
   return EXIT_SUCCESS;
}

