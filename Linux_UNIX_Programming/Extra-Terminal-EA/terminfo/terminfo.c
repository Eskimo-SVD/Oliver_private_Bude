/* terminfo.c */
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#define CAPS 4

int main (void) {
  int i, ret = 0;
  char *buf;
  const char *boolcaps[CAPS] = {"am", "bm", "bce", "km"};
  const char *numcaps[CAPS]={"cols", "lines", "colors", "pairs"};
  const char *strcaps[CAPS] = {"cup", "kf2", "flash", "hpa"};

  /* terminfor initialisieren */
  ret = setupterm (NULL, fileno (stdin), NULL);
  if (ret != 0) {
    perror ("setupterm()");
    exit (EXIT_FAILURE);
  }

  /* Eigenschaften abfragen, ob vorhanden */
  for (i = 0; i < CAPS; i++) {
    ret = tigetflag (boolcaps[i]);
    if (ret == -1)
      printf ("%s wird nicht unterst�tzt\n", boolcaps[i]);
    else
      printf ("%s wird unterst�tzt\n", boolcaps[i]);
  }
  printf ("\n");

  /* Eigenschaften abfragen, die einen nummerischen */
  /* Wert zur�ckliefern                             */
  for (i = 0; i < CAPS; i++) {
    ret = tigetnum (numcaps[i]);
    if (ret == -1)
      printf ("%s wird nicht unterst�tzt\n", numcaps[i]);
    else
      printf ("%s ist %d\n", numcaps[i], ret);
  }
  printf ("\n");

  /* Eigenschaften abfragen, die vom Tastaturtreiber */
  /* generiert werden                                */
  for (i = 0; i < CAPS; i++) {
    buf = tigetstr (strcaps[i]);
    if (buf == NULL)
      printf ("%s wird nicht unterst�tzt\n", strcaps[i]);
    else
      printf ("%s ist \\E%s\n", strcaps[i], &buf[1]);
  }
  return EXIT_SUCCESS;
}
