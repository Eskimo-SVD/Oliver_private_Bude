/* array10.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void function(int feld[], int n_anzahl) {
   int i;
   
   for(i = 0; i < n_anzahl; i++)
      printf("%d; ", feld[i]);
   printf("\n");
}

int main(void) {
   int val[MAX];
   int i;
   
   for(i = 0; i < MAX; i++)
      val[i] = i+1;
      
   function(val, MAX);   
   return EXIT_SUCCESS;
}

