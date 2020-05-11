/* func3.c */
#include <stdio.h>

void func1(void);
void func2(void);
void func3(void);

void func1(void) {
   printf("Ich bin func1 \n");
   func3();
}

void func2(void) {
   printf("Ich bin func2 \n");
}

void func3(void) {
   printf("Ich bin func3 \n");
   func2();
}

int main(void) {
   func1();
   return 0;
}

