/* time6.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   struct tm *zeit;
   time_t sekunde;
   char string[80];

   time(&sekunde);
   zeit = localtime(&sekunde);
   strftime(string, 80,
   "Es ist %H Uhr und %M Minuten (%Z) %A, %B %Y",zeit);
   printf("%s\n",string);
   return EXIT_SUCCESS;
}

