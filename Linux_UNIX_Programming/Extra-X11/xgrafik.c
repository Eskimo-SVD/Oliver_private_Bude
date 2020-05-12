/* xgrafik.c */
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "my_delay.h"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 320

/* Funktionsprototypen */
static int create_window (void);
static void process_event (XEvent report);
static void eventloop (void);
static void close_window (void);
extern int delay (int i);
extern int time_diff (void);
static void draw_graphics (void);

/* Globale Variablen */
static unsigned int width, height;
static Display *display;
static int screen;
static int depth;
static Window win;

/* Funktion erzeugt ein Fenster */
static int create_window (void) {
  char *window_name = "Einfachen Grafik-Primitiven";
  char *icon_name   = "window";
  static XSizeHints size_hints;
  Window rootwin;

  width = WINDOW_WIDTH;
  height = WINDOW_HEIGHT;

  /* X-Sitzung öffnen */
  display = XOpenDisplay (NULL);
  /* Fehlerüberprüfung */
  if (display == NULL) {
    printf ("Verbindung zum X-Server fehlgeschlagen?!?\n");
    exit(EXIT_FAILURE);
  }
  /* Standardbildschirm eines Displays */
  screen = XDefaultScreen (display);
  /* Standardtiefe des screen - Anzahl der Ebenen */
  depth = XDefaultDepth (display, screen);
  rootwin = RootWindow (display, screen);
  win = XCreateSimpleWindow ( display, rootwin, 10, 10,
                              width, height, 5,
                              BlackPixel (display, screen),
                              WhitePixel (display, screen));
  size_hints.flags = PSize | PMinSize | PMaxSize;
  size_hints.min_width =  width;
  size_hints.max_width =  width;
  size_hints.min_height = height;
  size_hints.max_height = height;
  XSetStandardProperties ( display, win, window_name, icon_name,
                           None, 0, 0, &size_hints );
  XSelectInput ( display, win,
                 ButtonPressMask | KeyPressMask | ExposureMask );
  XMapWindow (display, win);
  return 1;
}

static void close_window (void) {
  XCloseDisplay (display);
}

static void eventloop (void) {
  XEvent xev;
  int num_events;

  XFlush (display);
  num_events = XPending (display);
  while ((num_events != 0)) {
     num_events--;
     XNextEvent (display, &xev);
     process_event (xev);
  }
}

static void process_event (XEvent report) {
  switch (report.type) {

  case Expose:      /* Expose-Event => Bild zeichnen */
    if (report.xexpose.count == 0) {
      draw_graphics ();
    }
    break;
  case KeyPress:
    printf ("Tastaturaktion\n");
    break;
  case ButtonPressMask:
    printf ("Mausaktion\n");
    break;
  default:
    break;
  }
}

static void draw_graphics () {
  GC mygc;                      /* neu: Graphik-Kontext  */
  unsigned long black, white;   /* Nummern der Farben    */
  int i;                        /* gut fuer alles        */
  XPoint punkte[50];            /* Punkte-Schar          */
  XPoint poly[4];               /* 4 Punkte fuer Polygon */

  /* Ein paar Felder belegen                   */
  /* Ein Schräge mithilfe von Punkten Zeichnen */
  for (i = 0; i < 50; i++) {
    punkte[i].x = 470 + i;
    punkte[i].y = 200 + i;
  }
  /* geschlossenes Dreieck */
  poly[0].x = 200;
  poly[0].y = 200;
  poly[1].x = 300;
  poly[1].y = 300;
  poly[2].x = 400;
  poly[2].y = 200;
  poly[3].x = 200;
  poly[3].y = 200;
  /* Fenster oben drauf anzeigen */
  XMapRaised (display, win);
  /* Farbnummern besorgen */
  black = BlackPixel (display, screen);
  white = WhitePixel (display, screen);

  /* Graphical Context erzeugen, Farben eintragen */
  mygc = XCreateGC (display, win, 0, 0);
  XSetForeground (display, mygc, black);
  XSetBackground (display, mygc, white);
  /* sicherheitshalber alles löschen */
  XClearWindow(display, win);

  /* Ein Rechteck zeichnen */
  XDrawRectangle (display, win, mygc, 10, 50, 50, 50);
  /* Ein Rechteckigen Bereich mit Farbe füllen */
  XFillRectangle (display, win, mygc, 110, 50, 50, 50);
  /* Einen Kreis zeichnen */
  XDrawArc (display, win, mygc, 210, 50, 50, 50, 0, 360 * 64);
  /* Eine Kreisbereich füllen */
  XFillArc (display, win, mygc, 310, 50, 50, 50, 0, 360 * 64);
  /* Eine Ellipse zeichnen */
  XDrawArc (display, win, mygc, 410, 50, 60, 40, 0, 360 * 64);
  /* Einen Ellipsenbereich füllen */
  XFillArc (display, win, mygc, 510, 50, 60, 40, 0, 360 * 64);
  /* Einen Halbkreis zeichnen */
  XDrawArc (display, win, mygc, 10, 200, 60, 40, 90*64, 180*64);
  /* Einen Halbkreis füllen */
  XFillArc (display, win,mygc, 110, 200, 60, 40, 90*64, 180*64);
  /* Einen bestimmten bereich im Polygon (in diesem Fall ein */
  /* Dreieck füllen ausgefuelltes Polygon bzw. Dreieck       */
  XFillPolygon(display, win, mygc, poly, 4, 0, CoordModeOrigin);
  /* Eine Schräge Linie mit Punkten */
  XDrawPoints (display, win, mygc, punkte, 50, CoordModeOrigin);
  /* Puffer leeren */
  XFlush (display);
  /* GC wieder freigeben   */
  XFreeGC (display, mygc);
}

int main (int argc, char **argv) {
  int quit = 0;
  int pause = 0;
  int td;

  create_window ();
  gettimeofday (&st, NULL);
  while (!quit) {
    gettimeofday (&rt, NULL);
    td = time_diff ();
    pause = delay (FRAME_LEN - td + pause);
    st = rt;
    eventloop ();
  }
  close_window ();
  return EXIT_SUCCESS;
}
