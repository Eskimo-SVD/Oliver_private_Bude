/* cur15.c */
#include <curses.h>
#include <stdlib.h>
#define MAXSIZE 1
#define MINSIZE 0

static int y_click, x_click;
static int y_click2, x_click2;
static int size = MINSIZE;

static void
where_clicked (WINDOW * win, WINDOW * win2, MEVENT pos) {
  // linke obere Ecke von win2
  getbegyx (win2, y_click2, x_click2);
  mouseinterval (1);
  // wo in win wurde geklickt
  wenclose (win, pos.y, pos.x);
  y_click = pos.y;
  x_click = pos.x;
  // wurde auf die linke obere Ecke von win2
  if (y_click == y_click2 && x_click == x_click2) {
    endwin ();
    exit (EXIT_FAILURE);
  }
  // ... oder wurde auf der rechten oberen Ecke geklickt
  else if (y_click == y_click2 && x_click == x_click2 + 39 ||
           x_click == x_click2 + 78) {
    touchwin (stdscr);
    refresh ();
    if (size == MINSIZE) {
      delwin (win2);
      size = MAXSIZE;

    }
    else if (size == MAXSIZE) {
      delwin (win2);
      size = MINSIZE;
    }
  }
}

/* Verschieben des Fensters an Position der globalen Variablen */
/* x_click und y_click die zuvor mit where_clicked() ermittelt */
/* wurden                                                      */
static void move_win_to (WINDOW * win) {
  touchwin (stdscr);
  wrefresh (stdscr);
  mvwin (win, y_click + 1, x_click + 1);
  touchwin (win);
  wrefresh (win);
}

static WINDOW *create_new_window (
      WINDOW * neues_fenster, int zeilen, int spalten,
      int hinterg, int vordergr, int begin_y, int begin_x ) {
  neues_fenster = newwin (zeilen, spalten, begin_y, begin_x);
  init_pair (1, hinterg, vordergr);
  wattrset (neues_fenster, COLOR_PAIR (1));
  box (neues_fenster, ACS_VLINE, ACS_HLINE);
  return neues_fenster;
}

int main (void) {
  MEVENT pos;
  int l_maus;
  chtype button;
  WINDOW *fenster;

  initscr ();
  if (has_colors () == TRUE)
    start_color ();
  noecho ();
  keypad (stdscr, TRUE);
  fenster = create_new_window (
    fenster, 10, 40, COLOR_RED, COLOR_BLUE, 5, 15);
  init_pair (2, COLOR_BLACK, COLOR_YELLOW);
  wattrset (fenster, COLOR_PAIR (2));
  mvwaddch (fenster, 0, 0, 'S');
  mvwaddch (fenster, 0, 39, 'M');
  wattrset (fenster, COLOR_PAIR (0));
  mvwprintw (fenster, 2, 10, "S=Fenster schliessen");
  mvwprintw (fenster, 6, 10, "M=Fenster maximieren");
  wrefresh (fenster);
  l_maus = mousemask (BUTTON1_RELEASED | BUTTON1_PRESSED, NULL);

  while (1) {
    button = wgetch (stdscr);
    if (button == KEY_MOUSE) {
      if (getmouse (&pos) == OK) {
        where_clicked (stdscr, fenster, pos);
        // move_win_to(fenster);
        if (size == MAXSIZE) {
          fenster =
            create_new_window (fenster,
                               24, 79,
                               COLOR_RED,
                               COLOR_BLUE,
                               0, 0);
          wattrset (fenster, COLOR_PAIR (2));
          mvwaddch (fenster, 0, 0, 'S');
          mvwaddch (fenster, 0, 78, 'M');
          wattrset (fenster, COLOR_PAIR (0));
          mvwprintw (fenster, 10, 30,
                     "S=Fenster schliessen");
          mvwprintw (fenster, 14, 30,
                     "M=Fenster minimieren");
          wrefresh (fenster);
        } else if (size == MINSIZE) {
          fenster =
            create_new_window (fenster,
                               10, 40,
                               COLOR_RED,
                               COLOR_BLUE,
                               5, 15);
          init_pair (2, COLOR_BLACK,
                     COLOR_YELLOW);
          wattrset (fenster, COLOR_PAIR (2));
          mvwaddch (fenster, 0, 0, 'S');
          mvwaddch (fenster, 0, 39, 'M');
          wattrset (fenster, COLOR_PAIR (0));
          mvwprintw (fenster, 2, 10,
                     "S=Fenster schliessen");
          mvwprintw (fenster, 6, 10,
                     "M=Fenster maximieren");
          wrefresh (fenster);
          move_win_to (fenster);
        }
      }
    }
  }
  endwin ();
  return 0;
}

