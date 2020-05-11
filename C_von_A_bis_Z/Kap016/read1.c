/* read1.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#ifdef __unix__
      #include <unistd.h>
      #include <sys/stat.h>
      #include <sys/types.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
      #include <sys\stat.h>
#endif

#define MAXBYTES 1024

int main(int argc, char *argv[]) {
   int in,out,count;
   char buffer[MAXBYTES];

   if(argc < 3) {
      printf("Aufruf: programmname quelldatei zieldatei\n");
      return EXIT_FAILURE;
   }
   if( (in=open(*++argv ,O_RDONLY)) == -1)
      printf("Fehler open %s\n", (char *)argv);
   if( (out=open(*++argv, O_WRONLY | O_TRUNC | O_CREAT)) == -1)
      printf("Fehler open %s\n", (char *)argv);
   while( (count = read(in, buffer, MAXBYTES)) )
      write(out,buffer,count);
   close(in);
   close(out);
   return EXIT_SUCCESS;
}


