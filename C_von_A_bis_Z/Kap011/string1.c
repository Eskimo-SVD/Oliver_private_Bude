/* string1.c */
#include <stdio.h>
#include <stdlib.h>

char hello1[] = { "Hallo Welt\n" };
char output[] = { "Ich bin lesbar \0 Ich nicht mehr" };
char deznu[]  = { "Mich siehst du 0 Mich und die Null auch" };

int main(void) {
   printf("%s",hello1);
   printf("%s\n",output);
   printf("%s\n",deznu);
   return EXIT_SUCCESS;
}

