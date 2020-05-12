/* cur4.c */
#include <curses.h>
#define MAX 100

int main (void) {
  char string[MAX];
  char string2[MAX];
  const char string3[] = "Dies ist der neue String3\n";
  int c;

  initscr ();
  printw ("Bitte Eingabe f�r String machen : ");
  getnstr (string, MAX);
  mvprintw (3, 0, "Bitte Eingabe f�r 2. String machen : ");
  getnstr (string2, MAX);
  mvprintw (7, 20, "String ist gleich : %s\n", string);
  mvprintw (8, 20, "Diese Zeile wird mit deleteln() gel�scht\n");
  mvprintw (9, 20, "String 2 ist gleich : %s\n", string2);
  mvprintw (14, 20, "Weiter mit TASTE");
  noecho ();
  c = getch ();
  move (8, 20);
  // Zeile l�schen
  deleteln ();
  noecho ();
  c = getch ();
  move (8, 20);
  // (Leer)Zeile einf�gen
  insertln ();
  mvprintw (8, 20, string3);
  noecho ();
  c = getch ();
  // Bildschirm l�schen
  clear ();
  refresh ();
  mvprintw (12, 38, "ENDE");
  // Wartet 20 Zehntelsec. auf getch()
  halfdelay (20);
  // ... ansonsten beendet sich das Progr. selbst
  c = getch ();
  endwin ();
  return 0;
}
