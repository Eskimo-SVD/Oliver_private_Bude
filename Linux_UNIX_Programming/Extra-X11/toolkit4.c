/* toolkit4.c */
#include <stdio.h>
#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Command.h>

static Display *dsp;
static Window win;
static GC gc;

static void
paint_proc (Widget canvas, caddr_t client_data, XEvent * event) {
  static int x0, y0, x1, y1;
  switch (event->type) {
  case ButtonPress:
    switch (event->xbutton.button) {
    case 1:
      x0 = event->xbutton.x;
      y0 = event->xbutton.y;
      break;
    default:
      XClearWindow (dsp, win);
      XFlush (dsp);
      break;
    }
    break;
  case MotionNotify:
    x1 = event->xbutton.x;
    y1 = event->xbutton.y;
    XDrawLine (dsp, win, gc, x0, y0, x1, y1);
    x0 = x1;
    y0 = y1;
    XFlush (dsp);
    break;
  default:
    break;
  }
}

static void
quitCB (Widget button, XtPointer client_data, XtPointer call_data) {
  exit (EXIT_SUCCESS);
}

int main (int argc, char **argv) {
  XtAppContext ac;
  Widget toplevel, form, panel, canvas;
  Widget  quit;
  toplevel = XtVaAppInitialize (
           &ac, "Paint", NULL, 0,
           &argc, argv, NULL, NULL);
  form = XtVaCreateManagedWidget (
           "form",
           formWidgetClass,
           toplevel,
           XtNvertDistance, (XtArgVal) 5,
           XtNwidth, (XtArgVal) 80,
           XtNheight, (XtArgVal) 40,
           NULL);
  panel = XtVaCreateManagedWidget (
           "panel",
           formWidgetClass,
           form,
           XtNvertDistance, (XtArgVal) 420,
           NULL);
  canvas = XtVaCreateManagedWidget (
           "canvas",
           formWidgetClass,
           form,
           XtNbackground, (XtArgVal) 0xffffff,
           XtNwidth, (XtArgVal) 600,
           XtNheight, (XtArgVal) 400,
           NULL);
  XtAddEventHandler(canvas, ButtonPressMask | Button1MotionMask,
                    False, (XtEventHandler) paint_proc, NULL);
  quit = XtVaCreateManagedWidget (
           "quit",
           commandWidgetClass,
           panel,
           XtNbackground, (XtArgVal) "white",
           XtNbackground, (XtArgVal) "black",
           XtNlabel, (XtArgVal) "Ende",
           XtNhorizDistance, (XtArgVal) 5,
           NULL);

  XtAddCallback (quit, XtNcallback, quitCB, NULL);
  XtRealizeWidget (toplevel);

  /* Wird von der Xlib zum zeichnen benötigt */
  dsp = XtDisplay (canvas);
  win = XtWindow (canvas);
  gc = XtGetGC (canvas, 0, NULL);

  XSetForeground (dsp, gc, BlackPixel (dsp, 0));
  XSetBackground (dsp, gc, WhitePixel (dsp, 255));

  XtAppMainLoop (ac);
  return EXIT_SUCCESS;
}
