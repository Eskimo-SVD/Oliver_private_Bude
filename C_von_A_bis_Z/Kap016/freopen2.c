/* freopen2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   printf("Wir schreiben eine Datei \"log.txt\"\n");
   freopen("log.txt","a+",stdout);
   printf("Dieser Text steht in der Datei \"log.txt\"\n");
   return EXIT_SUCCESS;
}

