/* toolkit2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Xaw/Command.h>   /* Command-Widget */
#include <X11/Xaw/Box.h>       /* Box-Widget     */
#include <X11/Xaw/Form.h>      /* Form-Widget    */
#include <X11/Xaw/Label.h>     /* Label Widget   */

static Widget w_label, w_pressme;

/* Callback für den Button 'Ende' */
static void
Quit (Widget w, XtPointer client_data, XtPointer call_data) {
  exit (EXIT_SUCCESS);
}

/* Callbackfunktione für den 'Start' bzw. 'Stop' Button */
static void
Pressme (Widget w, XtPointer client_data, XtPointer call_data) {
  char string1[50], string2[50];   /* Hilfs-Strings */
  char *ptr;
  static time_t start, stop;
  static int gedrueckt = 0;

  if (!gedrueckt) {
    start = time (NULL);
    gedrueckt = 1;
    sprintf (string1, "Gestartet ...");
    strcpy (string2, "Stop");
  }
  else {
    gedrueckt = 0;
    stop = time (NULL);
    sprintf (string1, "Gestoppt nach %.0f Sek.",
       difftime (stop, start));
    strcpy (string2, "Start");
  }
  /* Beschriftung des Buttons w_pressme verändern */
  XtVaSetValues (w_pressme, XtNlabel, string2, NULL);
  /* Beschriftung des Labels w_label verändern */
  XtVaSetValues (
             w_label,
             XtNwidth, 250,
             XtNlabel, string1,
             NULL );

  /* Zur Demonstration => wird auf der Konsole ausgegeben ... */
  /* Hole Ressource Label von w_label                         */
  XtVaGetValues (w_label,
             XtNlabel,
             &ptr,
             NULL );
  printf("Der Inhalt des Labels: %s\n", ptr);
}

int main (int argc, char **argv) {
  XtAppContext app_context;
  Widget w_parent, w_box,
  w_form, w_quit;

  w_parent = XtVaAppInitialize (
             &app_context, NULL,
             NULL, 0, &argc, argv,
             NULL, NULL);
  /* Box-Widget um alle 3 Elemente herum */
  w_box = XtVaCreateManagedWidget (
             "box",
             boxWidgetClass,  /* widget-Klasse von Box.h   */
             w_parent,        /* Eltern-Widget = w_parent! */
             NULL );
  /* das eigentliche Label-Widget */
  w_label = XtVaCreateManagedWidget (
             "label",
             labelWidgetClass,   /* widget class von Label.h  */
             w_box,              /* Eltern-Widget = box!      */
             XtNlabel, (XtArgVal) "Warte auf 'Start'",
             XtNwidth, (XtArgVal) 200,
             NULL);
  /* Form-Widget fuer die beiden Buttons */
  w_form = XtVaCreateManagedWidget (
             "form",
             formWidgetClass,   /* widget class von Form.h  */
             w_box,             /* Eltern-Widget = box!     */
             NULL);
  /* Command-Widget Quit */
  w_quit = XtVaCreateManagedWidget (
             "quit",
             commandWidgetClass, /* widget class von Command.h */
             w_form,             /* Eltern-Widget = form!      */
             XtNlabel, (XtArgVal) "Ende",
             NULL);
  /* Command-Widget Pressme */
  w_pressme = XtVaCreateManagedWidget (
             "pressme",
             commandWidgetClass, /* widget class von Command.h */
             w_form,             /* Eltern-Widget = form!      */
             XtNlabel, (XtArgVal) "Start",
             XtNhorizDistance, (XtArgVal) 50,
             NULL );

  /* Callback- Funktionen */
  XtAddCallback (w_quit, XtNcallback, Quit, 0);
  XtAddCallback (w_pressme, XtNcallback, Pressme, 0);

  /*  Stellt Fenster und Widgets dar   */
  XtRealizeWidget (w_parent);
  /*  Schleife fuer Events             */
  XtAppMainLoop (app_context);
  return EXIT_SUCCESS;
}
