/* string2val1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> 
#include <limits.h>

int main(int argc, char *argv[]) {
   if(argc==1) {
      printf("Keine Zahlen zum Auswerten vorhanden!\n");
      return EXIT_FAILURE;
   }
   while(*++argv) {
      if(strchr(*argv,'.') || strchr(*argv,'e') ||
       strchr(*argv,'E')) {
         if(((atof(*argv)) <= FLT_MAX)&&
          ((atof(*argv)) >= FLT_MIN)) {
            printf("\n%s ist ein float-Wert\n", *argv);
            printf("Maximaler float-Wert:%f\n", FLT_MAX);
            printf("Kleinster pos. float-Wert : %f\n" , FLT_MIN);
         }
         else if(((atof(*argv)) <= DBL_MAX)&&
          ((atof(*argv)) >= DBL_MIN)) {
            printf("\n%s ist ein double-Wert\n", *argv);
            printf("Max. double-Wert:%f\n", DBL_MAX);
            printf("Kleinster pos. double-Wert : %f\n", DBL_MIN);
         }
      }
      else if(((atol(*argv)) < SHRT_MAX)&&
       ((atol(*argv))>SHRT_MIN) && (atol(*argv) != 0)) {
         printf("\n%s ist ein short int-Wert\n",*argv);
         printf("Maximaler short int-Wert: %d\n",SHRT_MAX);
         printf("Kleinster short int-Wert: %d\n",SHRT_MIN);
      }
      else if(((atol(*argv)) < LONG_MAX) &&
       ((atol(*argv)) > LONG_MIN) && (atol(*argv) != 0)) {
         printf("\n%s ist ein long-Wert\n",*argv);
         printf("Maximaler long-Wert : %ld\n",LONG_MAX);
         printf("Kleinster long-Wert : %ld\n",LONG_MIN);
      }
      else
         printf("\nUnbekannter Typ (%s)!\n",*argv);
      } 
    return EXIT_SUCCESS;
}

