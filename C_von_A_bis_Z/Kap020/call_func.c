/* call_func.c */
#include <stdio.h>
#include <stdlib.h>

void func1(void);
void func2(void);
void func3(void);
void func4(void);

void func1(void) {
   printf("Funktion 1 ist aufgerufen!\n");
   func2();
}

void func2(void) {
   printf("Funktion 2 ist aufgerufen!\n");
   func3();
}

void func3(void) {
   printf("Funktion 3 ist aufgerufen!\n");
   func4();
}

void func4(void) {
   printf("Funktion 4 ist augerufen!\n");
}

int main(void) {
   func1();
   return EXIT_SUCCESS;
}

