/* variadic1.c */
#include <stdio.h>
#include <stdlib.h>
#define errprintf(...) fprintf(stderr, __VA_ARGS__)

int main(void) {
  const char str[] = "ein Argument";
  int val = 10;

  errprintf("Hallo Welt %d %s\n", val, str);
  errprintf("Fehler!! Zeile: %d (%s)\n", __LINE__, __DATE__);
  return EXIT_SUCCESS;
}
