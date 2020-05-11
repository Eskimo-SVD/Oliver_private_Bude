/* setjmp.c */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void func1(int);
void func2(int);
void func3(int);
void func4(void);
jmp_buf env;

static int zahl;

void func1(int zahl) {
   printf("Funktion 1 ist aufgerufen!\n");
   if(zahl == 1)
      longjmp(env, 1);
   func2(zahl);
}

void func2(int zahl) {
   printf("Funktion 2 ist aufgerufen!\n");
   if(zahl == 2)
      longjmp(env, 2);
   func3(zahl);
}

void func3(int zahl) {
   printf("Funktion 3 ist aufgerufen!\n");
   if(zahl == 3)
      longjmp(env, 3);
   func4();
}

void func4(void) {
   printf("Funktion 4 ist augerufen!\n");
}

int main(void) {
   printf("Wie viele Funktionen sollen ausgeführt werden : ");
   scanf("%d",&zahl);
   if(setjmp(env) == 0)
      func1(zahl);
   else
      printf("Rücksprung durch longjmp von Funktion %d!\n",zahl);
   return EXIT_SUCCESS;
}

