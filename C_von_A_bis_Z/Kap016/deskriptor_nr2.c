/* deskriptor_nr2.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
     #include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
     #include <io.h>
#endif

int main(void) {
   char puffer[] = "Ich werde im Low-Level-I/O ausgegeben";
   write(1, &puffer, sizeof(puffer));
   return EXIT_SUCCESS;
}

