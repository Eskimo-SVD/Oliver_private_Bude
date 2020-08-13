/* Datei main.c */

#include <stdio.h>
#include "func1.h"
#include "func2.h"
int main(void) {
  int x, y;
  x = func1();
  y = func2(x, 7);
  printf("Ergebnis %d\n", y);
}