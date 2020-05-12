/* toolkit1.c */
#include <stdio.h>
#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Command.h>
#define MAUS_LINKS  1
#define MAUS_RECHTS 3
#define MAUS_MITTE  2

static void quitCB (Widget, XtPointer, XtPointer);
static void halloCB (Widget, XtPointer, XtPointer);
static void quit_proc (Widget, caddr_t, XEvent *);

/* Callback-Funktion für den Button 'quit' */
static void
quitCB(Widget button,XtPointer client_data,XtPointer call_data) {
  printf ("Button 'quit' gerückt\n");
  exit (EXIT_SUCCESS);
}

/* Callback-Funktion für den Button 'hallo' */
static void
halloCB(Widget button,XtPointer client_data,XtPointer call_data){
  printf ("Button 'hallo' gerückt mit der Nachricht '%s'\n",
     (char *)client_data);
}

/* Eventhandler für die Anwendung */
static void
quit_proc (Widget form, caddr_t client_data, XEvent * event) {
  switch (event->type) {
  case ButtonPress:
    switch (event->xbutton.button) {
    case MAUS_RECHTS:
      printf ("Rechte Maustaste\n");
      break;
    case MAUS_LINKS:
      printf ("Linke Maustaste\n");
      break;
    case MAUS_MITTE:
      printf ("Mittlere Maustaste\n");
      break;
    default:
      break;
    }
    break;
  default:
    break;
  }
}

int main (int argc, char **argv) {
  XtAppContext ac;
  Widget toplevel, form, quit, hallo;
  /* Fenster erzeugen*/
  toplevel = XtVaAppInitialize (
     &ac, NULL, NULL, 0, &argc, argv, NULL, NULL);
  /* Form-Widget erzeugen */
  form = XtVaCreateManagedWidget (
           "form", formWidgetClass,
           toplevel,
           XtNbackground, (XtArgVal) "red",
           NULL  );
  XtAddEventHandler ( form, ButtonPressMask, False,
                      (XtEventHandler) quit_proc, NULL);
  /* quit-Button erzeugen */
  quit = XtVaCreateManagedWidget (
           "quit", commandWidgetClass,
           form,
           /* Eigenschaften des Buttons ... */
           XtNheight, (XtArgVal) 20,
           XtNwidth, (XtArgVal) 50, NULL);
  /* Callback-Funktion für quit-Button */
  XtAddCallback (
     quit, XtNcallback, (XtCallbackProc)quitCB, NULL);
  /* hallo-Button erzeugen */
  hallo = XtVaCreateManagedWidget (
            "hallo", commandWidgetClass,
            form,
            /* Eigenschaften des Buttons ... */
            XtNhorizDistance, (XtArgVal) 50,
            XtNfromHoriz, (XtArgVal) quit,
            XtNheight, (XtArgVal) 20,
            XtNwidth, (XtArgVal) 50, NULL);
  /* Callback-Funktion für hallo-Button */
  XtAddCallback ( hallo, XtNcallback,
                  (XtCallbackProc)halloCB, "Eine Nachricht");
  /* Widget toplevel mitsamt Unter-Widgets anzeigen */
  XtRealizeWidget (toplevel);
  /* Eventbearbeitungsschleife einrichten */
  XtAppMainLoop (ac);
  return EXIT_SUCCESS;
}