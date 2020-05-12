/* gkt5.c */
/* Dateneingabe: */
/*    Textfelder - GtkEntry          */
/*    Schieberegler -  GtkScale      */
/*    Zahlenfelder  -  GtkSpinButton */
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#define VBOX   3
#define ENTRYS 3
#define SCALES 3
#define SPIN   2
#define BUF 50

static  GtkEntry   *entry[ENTRYS];
static  GtkWidget  *vscale[SCALES];
static  GtkAdjustment *vadj[SCALES];
static  GtkSpinButton  *spin[SPIN];
static  GtkAdjustment *spinadj[SPIN];

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

/* Auswertung Eingabefelder */
static void entry_auswerten(gpointer auswert) {
  gchar *e1, *e2, *e3;
  g_object_get(entry[0], "text", &e1, NULL);
  g_object_get(entry[1], "text", &e2, NULL);
  g_object_get(entry[2], "text", &e3, NULL);
  g_print("Entry-Feld Auswertung:\n");
  g_print("Name, Vorname    : %s\n", e1);
  g_print("Strasse, Hausnr. : %s\n", e2);
  g_print("Ort, PLZ         : %s\n", e3);
  g_print("---------------------------\n");
}

/* Auswertung Schiebregler */
static void scale_auswerten(GtkAdjustment *adj, gpointer scale) {
  g_print("Schieberegler Auswertung:\n");
  g_print("Regler 1 : %.1f\n",
          gtk_adjustment_get_value(vadj[0]));
  g_print("Regler 2 : %.1f\n",
          gtk_adjustment_get_value(vadj[1]));
  g_print("Regler 3 : %.1f\n",
          gtk_adjustment_get_value(vadj[2]));
}

/* Auswertung Zahlenfelder */
static void spin_auswerten(GtkAdjustment *adj, gpointer scale) {
  g_print("Zahlenfelder Auswertung:\n");
  g_print("Regler 1 : %.1f\n",
          gtk_adjustment_get_value(spinadj[0]));
  g_print("Regler 2 : %.1f\n",
          gtk_adjustment_get_value(spinadj[1]));
}

/* Eingabefelder zurücksetzen - löschen */
static void entry_loeschen(gpointer auswert) {
  gint i;
  for(i=0; i<ENTRYS; i++)
    gtk_entry_set_text(entry[i], "");
}

int main(int argc, char **argv) {
  GtkWindow  *win;
  GdkPixbuf  *pic;
  GtkGrid    *table;
  GtkLabel   *label[ENTRYS];
  GtkButton  *entry_button[2];
  GtkWidget  *hbox, *hbox_2, *hbox_vscale;
  GtkWidget  *vbox, *vbox_spin;
  GtkWidget  *hsep;
  guint i;

  gtk_init( &argc, &argv );
  /* Eine Grafik in einen Pixbuf laden */
  pic = gdk_pixbuf_new_from_file("icon/at-work.gif", NULL );
  /* Fenster mit folgenden Eigenschaften anlegen */
  win = g_object_new( GTK_TYPE_WINDOW,
                      "title", "Dateieingabe",
                      "default-width",  380,
                      "default-height", 200,
                      "resizable", TRUE,
                      "window-position", GTK_WIN_POS_CENTER,
                      "border-width", 10,
                      "icon", pic,
                      NULL );
  /* Eine Tabelle 8x3 erzeugen */
  table = GTK_GRID(gtk_grid_new());
  gtk_grid_set_row_spacing(table, 3);
  gtk_grid_set_column_spacing(table, 3);
  /* horizontale Box erzeugen */
  hbox = gtk_box_new( GTK_ORIENTATION_HORIZONTAL , 10 );
  /* horizontale Box erzeugen */
  hbox_2 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL , 10 );
  /* horizontale Box für Schieberegler erzeugen */
  hbox_vscale = gtk_box_new( GTK_ORIENTATION_HORIZONTAL , 20 );
  /* vertikale Box erzeugen */
  vbox = gtk_box_new( GTK_ORIENTATION_VERTICAL , 10 );
  /* vertiakle Box für Zahlenfelder erzeugen */
  vbox_spin = gtk_box_new( GTK_ORIENTATION_VERTICAL , 7 );
  /* ENTRYS Textfelder erzeugen */

  for(i=0; i < ENTRYS; i++) {
    entry[i] = GTK_ENTRY(gtk_entry_new());
    gtk_entry_set_text(entry[i], "Ihre Eingabe hier ...");
    gtk_entry_set_max_length(entry[i], BUF);
  }
  /* Labels für die Textfelder erzeugen */
  label[0] = g_object_new( GTK_TYPE_LABEL,
                           "justify", GTK_JUSTIFY_LEFT,
                           "label", "Name, Vorname",
                           NULL );
  label[1] = g_object_new( GTK_TYPE_LABEL,
                           "label", "Strasse/Hausnr.",
                           NULL );
  label[2] = g_object_new( GTK_TYPE_LABEL,
                           "label", "Ort, Postleitz.",
                           NULL );
  /* Buttons zum Auswerten der Textfelder erzeugen */
  entry_button[0] = g_object_new( GTK_TYPE_BUTTON,
                                  "label", "Auslesen",
                                  NULL );
  entry_button[1] = g_object_new( GTK_TYPE_BUTTON,
                                  "label", "Reset",
                                  NULL );
  /* SCALES Stellgrößen für die Schieberegeler erzeugen */
  for(i=0; i<SCALES; i++)
    vadj[i] = GTK_ADJUSTMENT(
                gtk_adjustment_new(     1.0,
                                     -100.0,
                                      100.0,
                                        0.1,
                                       10.0,
                                        0.0) );
  /* SCALES vertikale Schieberegler erzeugen */
  for(i=0; i<SCALES; i++)
    vscale[i] = gtk_scale_new( GTK_ORIENTATION_VERTICAL,
                               vadj[i]);
  /* SPIN Stellgrößen für die Zahlenfelder erzeugen */
  for(i=0; i<SPIN; i++)
    spinadj[i] = GTK_ADJUSTMENT(
                   gtk_adjustment_new(    1.0,
                                       -100.0,
                                        100.0,
                                          0.1,
                                         10.0,
                                          0.0) );
  /* SPIN Zahlenfelder erzeugen */
  for(i=0; i<SPIN; i++)
    spin[i] = g_object_new( GTK_TYPE_SPIN_BUTTON,
                            "adjustment", spinadj[i],
                            "digits", 1,
                            "value", 20.0,
                            NULL );
  /* horizontale Linie erzeugen */
  hsep = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  /* Signalhandler einrichten */
  g_signal_connect( win, "delete-event",
                    G_CALLBACK(delete_Event), NULL );
  g_signal_connect( win, "destroy",
                    G_CALLBACK(end), NULL );
  /* Signalhandler für die Buttons */
  g_signal_connect( entry_button[0], "clicked",
                    G_CALLBACK(entry_auswerten), NULL);
  g_signal_connect( entry_button[1], "clicked",
                    G_CALLBACK(entry_loeschen), NULL);
  /* Signalhandler, wenn sich einer der */
  /* Schieberegler verändert            */
  g_signal_connect( vscale[0], "value-changed",
                    G_CALLBACK(scale_auswerten), NULL);
  g_signal_connect( vscale[1], "value-changed",
                    G_CALLBACK(scale_auswerten), NULL);
  g_signal_connect( vscale[2], "value-changed",
                    G_CALLBACK(scale_auswerten), NULL);
  /* Signalhandler, wenn sich eines der Zahlenfelder */
  /* verändert                                       */
  g_signal_connect( spin[0], "value-changed",
                    G_CALLBACK(spin_auswerten), NULL);
  g_signal_connect( spin[1], "value-changed",
                    G_CALLBACK(spin_auswerten), NULL);
  /* Großes Packen der Widget beginnt */
  gtk_grid_attach ( table, GTK_WIDGET(label[0]),
                     0, 0, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(entry[0]),
                     1, 0, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(label[1]),
                     0, 2, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(entry[1]),
                     1, 2, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(label[2]),
                     0, 4, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(entry[2]),
                     1, 4, 1, 1);
  gtk_grid_attach ( table, GTK_WIDGET(hbox),
                     1, 6, 1, 1);
  gtk_box_pack_start( GTK_BOX(hbox),
                      GTK_WIDGET(entry_button[0]),
                      FALSE, FALSE, 0);
  gtk_box_pack_start( GTK_BOX(hbox),
                      GTK_WIDGET(entry_button[1]),
                      FALSE, FALSE, 0);
  gtk_box_pack_start( GTK_BOX(vbox_spin),
                      GTK_WIDGET(hsep),
                      FALSE, FALSE, 0);
  gtk_box_pack_start( GTK_BOX(vbox_spin),
                      GTK_WIDGET(spin[0]),
                      FALSE, FALSE, 0);
  gtk_box_pack_start( GTK_BOX(vbox_spin),
                      GTK_WIDGET(spin[1]),
                      FALSE, FALSE, 0);
  gtk_grid_attach ( table, GTK_WIDGET(vbox_spin),
                    1, 7, 1, 1);
  for(i=0; i<SCALES; i++)
    gtk_box_pack_start( GTK_BOX(hbox_vscale),
                        GTK_WIDGET(vscale[i]),
                        FALSE, FALSE, 0);
  gtk_container_add( GTK_CONTAINER( vbox ),
                     GTK_WIDGET( hbox_2) );
  gtk_container_add( GTK_CONTAINER( hbox_2 ),
                     GTK_WIDGET( table ) );
  gtk_container_add( GTK_CONTAINER( hbox_2 ),
                     GTK_WIDGET( hbox_vscale ) );
  gtk_container_add( GTK_CONTAINER( win ), GTK_WIDGET( vbox ) );
  /* Fenster anzeigen */
  gtk_widget_show_all( GTK_WIDGET(win) );
  /* Hauptschleife von gtk */
  gtk_main();
  g_print("Die GTK-Hauptschleife wurde beendet\n");
  return 0;
}





