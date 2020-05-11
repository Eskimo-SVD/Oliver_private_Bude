/* direktiven.c */
#include <stdio.h>
#include <stdlib.h>

#if defined __STDC__
   #define isstd_c() printf("ANSI C Compiler\n")
#else
   #define isstd_c() printf("Kein ANSI C Compiler\n")
#endif

int main(void) {
   printf("Zeile %d in Datei %s\n",__LINE__,__FILE__);
   printf("Übersetzt am %s um %s\n",__DATE__,__TIME__);

   #line 999 "asdf.c"
   printf("Zeile %d in Datei %s\n",__LINE__,__FILE__);
   
   isstd_c();  /* Ist es ein ANSI C Compiler ? */
   return EXIT_SUCCESS;
}

