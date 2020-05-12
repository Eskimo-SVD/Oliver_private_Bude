/* cur12.c */
#include <curses.h>
#define schwarz  0
#define rot      1
#define gruen    2
#define gelb     3
#define blau     4
#define lila     5
#define hblau    6
#define weiss    7

// zeigt uns alle m�glichen Farbpaare an
static void show_all_pairs(void) {
  int farbe1, farbe2, i=1, c;
  mvprintw(1,1,"Darstellung aller Farbenpaare : \n");
  if(has_colors() == TRUE) {
    start_color();
    for(farbe1=weiss; farbe1 >= schwarz; farbe1--)
      for(farbe2=schwarz; farbe2 <= weiss; farbe2++) {
        init_pair(i, farbe1, farbe2);
        attrset(COLOR_PAIR(i));
        printw(" %d ",i++);
      }
  }
  noecho();
  c=getch();
}

// Erzeugen ein neues Fenster mit s�mtlichen Attributen
static WINDOW *create_new_window(
     WINDOW *neues_fenster, int zeilen,int spalten, int hinterg,
     int vorderg,int begin_y, int begin_x, char *text,
     int text_y, int text_x ) {
  neues_fenster = newwin(zeilen, spalten, begin_y, begin_x);
  init_pair(1, hinterg, vorderg);
  wattrset(neues_fenster, COLOR_PAIR(1));
  box(neues_fenster, ACS_VLINE, ACS_HLINE);
  mvwprintw(neues_fenster, text_y, text_x, text);
  return neues_fenster;
}

int main(void) {
  WINDOW *fenster1,*fenster2;
  int y,x;

  initscr();
  raw();
  keypad(stdscr,TRUE);
  if(has_colors() == TRUE)
    start_color();
  show_all_pairs();
  clear();
  refresh();
  fenster1=create_new_window( fenster1,11,50,blau,weiss,0,0,
                              "Hallo Welt",5,20 );
  keypad(fenster1,TRUE);
  wrefresh(fenster1);
  wgetch(fenster1);
  fenster2=create_new_window( fenster2,10,50,rot,gruen,11,30,
                              "Fenster 2",1,1);
  keypad(fenster2,TRUE);
  wrefresh(fenster2);
  wgetch(fenster2);
  mvwprintw(fenster1,5,5,"Wir verschieben Fenster 2"
            " mit mvwin()");
  wrefresh(fenster1);
  wgetch(fenster1);
  // Wo ist das Fenster 2 genau
  getbegyx(fenster2,y,x);
  // stdscr neuzeichnen
  touchwin(stdscr);
  refresh();
  // Fenster 3 Zeilen tiefer und 20 Spalten nach links
  mvwin(fenster2,y+3,x-20);
  // Fenster 1 wurde nicht ver�ndert ...
  // ... aber wir wollen trotzdem neu zeichnen ...
  touchwin(fenster1);
  wrefresh(fenster1);
  wrefresh(fenster2);
  wgetch(fenster2);
  mvwprintw(fenster1,5,5," Wir l�schen Fenster 2 mit delwin() ");
  wrefresh(fenster1);
  wgetch(fenster1);
  // Fenster 2 l�schen
  delwin(fenster2);
  touchwin(stdscr);
  refresh();
  mvwin(fenster1,0,0);
  wrefresh(fenster1);
  wgetch(fenster1);
  mvwprintw(fenster1,5,5,"Wir kopieren dieses Fenster "
            "mit dupwin()");
  wrefresh(fenster1);
  wgetch(fenster1);
  fenster2=dupwin(fenster1);
  mvwin(fenster2,12,0);
  wrefresh(fenster2);
  wgetch(fenster2);
  mvwprintw(fenster1,5,1," Fenster 1 wird nun geloescht ");
  wrefresh(fenster1);
  wgetch(fenster1);
  delwin(fenster1);
  touchwin(stdscr);
  refresh();
  touchwin(fenster2);
  wrefresh(fenster2);
  wgetch(fenster2);
  attrset(COLOR_PAIR(0));
  mvprintw(1,1,"Nun wird das letzte Fenster auch noch beendet");
  refresh();
  wgetch(fenster2);
  delwin(fenster2);
  touchwin(stdscr);
  refresh();
  mvprintw(1,1,"Jetzt ist nur noch das Fenster stdscr"
           " in Betrieb!");
  getch();
  endwin();
  return 0;
}
