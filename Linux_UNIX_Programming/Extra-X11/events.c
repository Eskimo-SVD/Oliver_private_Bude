/* events.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "my_delay.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300
#define MAUS_LINKS  1
#define MAUS_RECHTS 3
#define MAUS_MITTE  2
#define SCROLL_UP   4
#define SCROLL_DOWN 5

/* Funktionsprototypen */
static int create_window (void);
static void process_event (XEvent report);
static void eventloop (void);
static void close_window (void);
extern int delay (int i);
extern int time_diff (void);

/* Globale Variablen */
static unsigned int width, height;
static Display *display;
static int screen;
static int depth;
static Window win;

/* Funktion erzeugt ein Fenster */
static int create_window (void) {
  char *window_name = "Eventsbehandlung";
  char *icon_name   = "window";
  static XSizeHints size_hints;
  Window rootwin;

  width  = WINDOW_WIDTH;
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
  XSelectInput (display, win,
      ButtonPressMask | ButtonReleaseMask | KeyPressMask    |
      KeyReleaseMask  | EnterWindowMask   | LeaveWindowMask |
      ExposureMask );
  XMapWindow (display, win);
  return 1;
}

static void close_window (void) {
  XDestroyWindow (display, win);
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
  KeySym key;
  char buf[128] = { 0 };
  int bufsz = 128;
  char position[50];

  switch (report.type) {
  case KeyPress:
    key = XLookupKeysym (&report.xkey, 0);
    XLookupString (&report.xkey, buf, bufsz, &key, NULL);
    if (strlen (buf) != 0 && buf[0] != '\n' && buf[0] != '\r')
      printf ("Taste'%s' (Tasturcode: %d)  wurde gedrückt\n",
         buf, XKeysymToKeycode (display, key));
    else
      printf ("Taste '%s' (Tasturcode: %d) wurde gedrückt\n",
         XKeysymToString (key), XKeysymToKeycode (display, key));
    break;
  case KeyRelease:
    printf ("Taste wieder losgelassen\n");
    break;
  case ButtonPress:
    switch (report.xbutton.button) {
    case MAUS_LINKS:
      sprintf (position, "(X,Y)=(%d,%d).", report.xmotion.x,
         report.xmotion.y);
      printf ("Linke Maustaste wurde gedrückt an Pos.: %s\n",
         position);
      break;
    case MAUS_RECHTS:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Rechte Maustaste wurde gedrückt an Pos.: %s\n",
         position);
      break;
    case MAUS_MITTE:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Mittlere Maustaste gedrückt an Pos.: %s\n",
         position);
      break;
    case SCROLL_UP:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Mausrad nach oben gescrollt an Pos.: %s\n",
         position);
      break;
    case SCROLL_DOWN:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Mausrad nach unten gescrollt an Pos.: %s\n",
         position);
      break;
    }
    break;
  case ButtonRelease:
    switch (report.xbutton.button) {
    case MAUS_LINKS:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Linke Maustaste losgelassen an Pos.: %s\n",
         position);
      break;
    case MAUS_RECHTS:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Rechte Maustaste losgelassen an Pos.: %s\n",
         position);
      break;
    case MAUS_MITTE:
      sprintf (position, "(X,Y)=(%d,%d).",
         report.xmotion.x, report.xmotion.y);
      printf ("Mittlere Maustaste losgelassen an Pos.: %s\n",
         position);
      break;
    }
    break;
  case EnterNotify:
    XSetInputFocus (display, win, RevertToParent, CurrentTime);
    printf ("Cursor 'betritt' das Fenster\n");
    break;
  case LeaveNotify:
    XSetInputFocus (display, win, RevertToParent, CurrentTime);
    printf ("Cursor 'verlässt' das Fenster\n");
    break;
  case Expose:
    printf("ExposeEvent: Bild sollte neu gezeichnet werden\n");
    break;
  default:
    break;
  }
}

int main (int argc, char **argv) {
  int quit = 0;
  int pause = 0;
  int td;

  create_window ();
  gettimeofday (&st, NULL);
  while (!quit) {
    /* +++ Timer Anfang +++ */
    gettimeofday (&rt, NULL);
    td = time_diff ();
    pause = delay (FRAME_LEN - td + pause);
    st = rt;
    /* +++ Timer Ende */
    eventloop ();
  }
  close_window ();
  return EXIT_SUCCESS;
}
