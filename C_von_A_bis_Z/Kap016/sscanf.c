/* sscanf.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   int count = 1, check, temp, summe = 0;

   if (argc < 2) {
      fprintf(stderr, "Verwendung: %s Integer"
                      " Integer [Integer_n]\n", *argv);
      return EXIT_FAILURE;
   }
   while(count < argc) {
      /* Einzelne Argumente in Integerwerte konvertieren */
      check = sscanf(argv[count], "%d", &temp);
      /* Ungültiges Argument wird ignoriert */
      if(check == EOF)
         count++;
      else {
         summe += temp;
         count++;
      }   
   }
   printf("Summe aller Ganzzahlen der Argumente: %d\n", summe);
   return EXIT_SUCCESS;
}

