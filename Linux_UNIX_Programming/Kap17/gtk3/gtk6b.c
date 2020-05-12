/* gkt6b.c */
/*        Optionsmenü    */
/*        Comboboxen     */
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static GtkComboBox *combo;

static gchar *linux_t[] = {
   "OpenSUSE", "Fedora", "Mageia Linux",
   "Debian (Stretch) GNU/Linux", "Gentoo Linux",
   "Ubuntu", "Linux Mint", "Yggdrasil Linux/GNU/X"
 };

#define SIZE(x) (sizeof x / sizeof x[0])

static gint
delete_Event(GtkWidget *widget, GdkEvent event, gpointer daten) {
  g_print ("Das Fenster wird zerstoert!\n");
  /* Nur mit FALSE wird die Anwendung wirklich Beendet */
  return FALSE;
}

static void end (GtkWidget * widget, gpointer daten) {
  g_print ("Und Tschues!\n");
  gtk_main_quit ();
}

/* Auswerten des Optionsmenüs und der Combobox */
static void auswerten (GtkWidget * widget, gpointer daten) {
  gint i = gtk_combo_box_get_active(combo);
  
  if (i == -1)
    g_print ("Fehler beim Auswerten der Combo-Box\n");
  else
    g_print ("Auswertung Combo-Box: %s\n", linux_t[i]);
  gtk_widget_get_name(GTK_WIDGET(combo));
}

int main (int argc, char **argv) {
  GtkWindow *win;
  GdkPixbuf *pic;
  GtkGrid *table;
  GtkButton *button;
  GtkLabel *combo_label;
  GtkListStore *elements;
  GtkCellRenderer *cell;
  GtkTreeIter iter;
  gint i;

  gtk_init (&argc, &argv);
  /* Eine Grafik in einen Pixbuf laden */
  pic = gdk_pixbuf_new_from_file ("icon/at-work.gif", NULL);
  /* Fenster mit folgenden Eigenschaften anlegen */
  win = g_object_new (GTK_TYPE_WINDOW,
                      "title", "Optionsmenues und Comboboxen",
                      "default-width", 300,
                      "default-height", 150,
                      "resizable", TRUE,
                      "window-position", GTK_WIN_POS_CENTER,
                      "border-width", 10, "icon", pic, NULL);
  /* Eine Tabelle 3x2 erzeugen */
  table = GTK_GRID(gtk_grid_new());
  /* Create data elements ... */
  elements = gtk_list_store_new( 1, G_TYPE_STRING );
  for (i = 0; i < SIZE(linux_t); i++) {
    gtk_list_store_append(elements, &iter);
    gtk_list_store_set(elements, &iter, 0, linux_t[i], -1);
  }
  /* Eine neuen Combobox erzeugen aus dem DataStore */
  combo = GTK_COMBO_BOX(gtk_combo_box_new_with_model(GTK_TREE_MODEL(elements)));
  /* Einen Cell-Renderer erzeugen */
  cell = gtk_cell_renderer_text_new();
  /* Diesen in die Combo-Box packen */
  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo), cell, TRUE );
  /* Den Cell-Renderer mit der Datenquelle (elements) verbinden */
  gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(combo), cell, "text", 0 );
  /* Ein Optionsmenü erzeugen und mit dem Menü bestücken */
  /* Ein Textfeld erzeugen */
  option_label = g_object_new ( GTK_TYPE_LABEL,
                                "label", "Optionsmenue ",
                                NULL );
  /* Remove our reference from elements to avoid memory leak. */
  g_object_unref(G_OBJECT(elements));
  /* Ein neues Label erzeugen */
  combo_label = g_object_new ( GTK_TYPE_LABEL,
                               "label", "Combobox ",
                               NULL);
  /* Einen neuen Button erzeugen */
  button = g_object_new ( GTK_TYPE_BUTTON,
                          "label", "Auswerten",
                          "relief", GTK_RELIEF_HALF,
                          NULL);
  /* Signalhandler einrichten */
  g_signal_connect ( win, "delete-event",
                     G_CALLBACK (delete_Event), NULL);
  g_signal_connect ( win, "destroy",
                     G_CALLBACK (end), NULL );
  g_signal_connect ( button, "clicked",
                     G_CALLBACK (auswerten), NULL );
  /* Alles Packen */
  gtk_container_add (GTK_CONTAINER (win), GTK_WIDGET (table));
  gtk_grid_attach (GTK_GRID(table), GTK_WIDGET(combo_label),
                    0, 1, 1, 1);
  gtk_grid_attach (GTK_GRID(table), GTK_WIDGET(combo),
                    1, 1, 1, 1);
  gtk_grid_attach (GTK_GRID(table), GTK_WIDGET(button),
                    1, 2, 1, 1);
  /* Fenster anzeigen */
  gtk_widget_show_all (GTK_WIDGET(win));
  /* Hauptschleife von gtk */
  gtk_main ();
  g_print ("Die GTK-Hauptschleife wurde beendet\n");
  return 0;
}







