/* offsetof.c */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define MAX 15

struct data{
   char datei[MAX];
   unsigned int flag;
   char eigentuemer[MAX];
   char passwort[MAX];
};
           
int main(void) {
   struct data newfile = { "testfile", 0, "its_me", "believe" };

   printf("Vom Anfang zur Strukturvariable flag    : %d Bytes\n",
      offsetof(struct data, flag));
   printf("Vom Anfang  zur Strukturvariable owner  : %d Bytes\n",
      offsetof(struct data, eigentuemer));
   printf("Vom Anfang zur Strukturvariable passwort: %d Bytes\n",
      offsetof(struct data, passwort)); 
 return EXIT_SUCCESS;
}

