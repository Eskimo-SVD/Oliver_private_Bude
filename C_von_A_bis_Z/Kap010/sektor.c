/* sektor.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__ || linux
   #define SEKTORSIZE 4096
#elif __MSDOS__ || __WIN32__ || _MSC_VER
   #define SEKTORSIZE 512
#else
#define SEKTORSIZE 0
#endif

void sect(long size) {
   long kb,s=SEKTORSIZE;

   if(s == 0)
      printf("Unbekanntes System\n");
   else if(s==4096)
      printf("Unixsystem : ");
   else
     printf("DOS/Win32 : ");
   kb = size * s;
   printf("%ld Sektoren = %ld B\n", size, kb);
}

int main(void) {
   long sector;

   printf("Wie viele Sektoren: ");
   scanf("%ld",&sector);
   sect(sector);
   return EXIT_SUCCESS;
}


