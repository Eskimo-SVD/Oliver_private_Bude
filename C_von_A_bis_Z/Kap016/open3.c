/* open3.c */
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

int main(int argc,char **argv) {
   int fh;
   if(*++argv == NULL)
      return EXIT_FAILURE;  /* Keine Argumente vorhanden */
   if( (fh = open(*argv, O_RDONLY)) == -1)
      if( (fh = open(*argv,O_RDWR|O_CREAT)) == -1)
         perror(*argv);
   close(fh);
   return EXIT_SUCCESS;
}

