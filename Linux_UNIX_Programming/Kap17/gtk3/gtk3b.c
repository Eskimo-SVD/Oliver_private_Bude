/* gtk3b.c */
/* Behälter:        */
/*    Tabellen-Demo */
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#define BUTTONS 3

static gint
delete_Event(GtkWidget *widget, GdkEvent event, gpointer daten) {
  g_print("Das Fenster wird zerstoert!\n");
  /* Nur mit FALSE wird die Anwendung wirklich Beendet */
  return FALSE;
}

static void end ( GtkWidget *widget, gpointer daten ) {
  g_print("Und Tschues!\n");
  gtk_main_quit();
}

int main(int argc, char **argv) {
  GtkWindow  *win;
  GdkPixbuf  *pic;
  GtkGrid    *table;
  GtkButton  *button1, *button2, *button3;

  gtk_init( &argc, &argv );
  /* Eine Grafik in einen Pixbuf laden */
  pic = gdk_pixbuf_new_from_file("icon/at-work.gif", NULL );
  /* Fenster mit folgenden Eigenschaften anlegen */
  win = g_object_new( GTK_TYPE_WINDOW,
                      "title", "Eine einfache Tabelle",
                      "default-width",  300,
                      "default-height", 200,
                      "resizable", TRUE,
                      "window-position", GTK_WIN_POS_CENTER,
                      "border-width", 10,
                      "icon", pic,
                      NULL );
  button1 = g_object_new( GTK_TYPE_BUTTON,
                     "label","Kein schrumpfen\nkein expandieren",
                     NULL);
  button2 = g_object_new( GTK_TYPE_BUTTON,
                    "label","Expandiert und schrumpft\nvertikal",
                    NULL);
  gtk_widget_set_vexpand(GTK_WIDGET(button2), TRUE);
  button3 = g_object_new( GTK_TYPE_BUTTON,
           "label","Expandiert und schrumpft\n  in beide Seiten",
           NULL);
  gtk_widget_set_hexpand(GTK_WIDGET(button3), TRUE);
  gtk_widget_set_vexpand(GTK_WIDGET(button3), TRUE);
  table = GTK_GRID(gtk_grid_new());
  /* Signalhandler einrichten */
  g_signal_connect( win, "delete-event",
                    G_CALLBACK(delete_Event), NULL );
  g_signal_connect( win, "destroy",
                    G_CALLBACK(end), NULL );

  /* Inhalt der Tabelle mit verschiedenen Optionen erstellen */
  gtk_grid_attach ( table, GTK_WIDGET(button1),
                     0, 0, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(button2),
                     0, 1, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(button3),
                     1, 1, 1, 1);
  gtk_container_add(GTK_CONTAINER( win ), GTK_WIDGET( table ) );
  /* Fenster anzeigen */
  gtk_widget_show_all( GTK_WIDGET(win) );
  /* Hauptschleife von gtk */
  gtk_main();
  g_print("Die GTK-Hauptschleife wurde beendet\n");
  return 0;
}



