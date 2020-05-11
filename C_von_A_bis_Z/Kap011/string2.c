/* string2.c */
#include <stdio.h>
#include <stdlib.h>

char hello1[] = { "Hallo Welt" };
char output[] = { "Ich bin lesbar \0 Ich nicht mehr" };
char deznu[]  = { "Mich siehst du 0 Mich und die Null auch" };

int main(void) {
   int i;

   printf("%c", output[0]);      /* I */
   printf("%c'", hello1[9]);     /* t */
   printf("%c ", deznu[5]);      /* s */
   printf("%c", hello1[7]);      /* Gibt das Zeichen 'e' aus */
   printf("%c", output[12]);     /* a */
   printf("%c", deznu[5]);       /* s */
   deznu[1] = 'y';               /* aus 'i' wird 'y' */
   printf("%c\n", deznu[1]);     /* y */

   for(i=0; hello1[i] != '\0'; i++);
   printf("Länge von '%s' = %d Zeichen\n", hello1, i);

   for(i=0; output[i] != '\0'; i++);
   printf("Länge von '%s' = %d Zeichen\n", output, i);

   for(i=0; deznu[i] != '\0'; i++);
   printf("Länge von '%s' = %d Zeichen\n", deznu, i);
   return EXIT_SUCCESS;
}

