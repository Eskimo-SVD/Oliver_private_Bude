/* md_array4.c */
#include <stdio.h>
#include <stdlib.h>
#define WOCHEN  4
#define TAGE    7

float stand[WOCHEN][TAGE] = {
   { 12.3f,13.8f,14.1f,12.2f,15.4f,16.5f,14.3f },
   { 15.4f,13.6f,13.6f,14.6f,15.6f,16.3f,19.5f },
   { 20.5f,20.4f,21.5f,23.4f,21.4f,23.5f,25.7f },
   { 25.5f,26.6f,24.3f,26.5f,26.9f,23.6f,25.4f }
};

int main(void) {
   int i, j;

   printf("Tag;Montag;Dienstag;Mittwoch;Donnerstag; "
          "Freitag;Samstag;Sonntag");
   for(i=0; i < WOCHEN; i++) {
      printf("\nWoche%d;",i);
      for(j=0;j < TAGE; j++) {
         printf("%.2f;",stand[i][j]);
      }
   }
   return EXIT_SUCCESS;
}


