/* cur6.c */
#include <curses.h>

int main (void) {
   initscr ();
   mvprintw (5, 5, "Diese Zeile enth�lt einen Fehhler");
   mvprintw (6, 5, "Bitte Taste dr�cken f�r Fehlerkorrektur");
   getch ();
   mvdelch (5, 33);
   mvprintw (7, 5, "Fehler wurde koregiert! "
                   " Bitte Taste dr�cken!");
   getch ();
   endwin ();
   return 0;
}
