/* wrap_gets.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX  10
/*Damit es keine Kollision mit gets aus stdio.h gibt */
#define gets(c) Gets(c)

void Gets(char *z) {
   int ch;
   int counter=0;

   while((ch=getchar()) != '\n') {
      z[counter++]=ch;
      if(counter >= MAX)
         break;
   }
   z[counter] = '\0';     /* Terminieren */
}

int main(int argc, char **argv) {
   char puffer[MAX];

   printf("Eingabe : ");
   gets(puffer);
   printf("puffer = %s\n",puffer); 
   return EXIT_SUCCESS;
}

