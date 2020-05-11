/* ptrptr4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

int main(void) {
   char *sort[] = {
      "Zeppelin", "Auto", "Amerika", "Programmieren"
    };
   int i,j;
   char *temp;

   for(i = 0; i < 4; i++) {
      for(j = i + 1; j < 4; j++) {
        if( (strcmp(sort[i],sort[j]) > 0) ) {
           temp=sort[i];
           sort[i]=sort[j];
           sort[j]=temp;
        }
      }
   }
   for(i = 0; i < 4; i++)
      printf("%s\n", sort[i]);
   return EXIT_SUCCESS;
}

