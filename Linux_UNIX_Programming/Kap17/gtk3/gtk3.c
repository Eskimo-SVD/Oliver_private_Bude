/* gkt3.c */
/* Behälter:       */
/*    horizontale und vertikale Aufteilung (GtkPaned) */
/*    Register (GtkNootebook)                         */
/*    horizontale und vertikale Boxen                 */
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#define NBOOK 6
#define BUF 35
#define BUTTONS 4

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
  GtkWidget  *vpan;
  GtkWidget  *hpan;
  GtkNotebook *nbook;
  GtkLabel    *nbook_content[NBOOK],
  *nbook_titel[NBOOK];
  GtkWidget     *vbutbox;
  GtkButton     *vbuttons[BUTTONS];
  GtkWidget     *hbutbox;
  GtkButton     *hbuttons[BUTTONS];
  guint i;
  gchar buf[BUF];

  gtk_init( &argc, &argv );
  /* Eine Grafik in einen Pixbuf laden */
  pic = gdk_pixbuf_new_from_file("icon/at-work.gif", NULL );
  /* Fenster mit folgenden Eigenschaften anlegen */
  win = g_object_new( GTK_TYPE_WINDOW,
                      "title", "Behaelter-Widgets",
                      "default-width",  300,
                      "default-height", 200,
                      "resizable", TRUE,
                      "window-position", GTK_WIN_POS_CENTER,
                      "border-width", 10,
                      "icon", pic,
                      NULL );
  /* vertikale Aufteilung erzeugen */
  vpan = gtk_paned_new( GTK_ORIENTATION_HORIZONTAL );
  /* horizontale Aufteilung erzeugen */
  hpan = gtk_paned_new( GTK_ORIENTATION_VERTICAL );
  /* vpan oben-links von hpan mit den */
  /* Standardparametern hinzufügen    */
  gtk_paned_add1( GTK_PANED(hpan), GTK_WIDGET(vpan) );

  /* ein neues Notizbuch erzeugen */
  nbook = g_object_new( GTK_TYPE_NOTEBOOK,
                        "enable-popup", TRUE,
                        NULL );
  /* nbook rechts-unten von vpan mit den */
  /* Standardparametern hinzufügen */
  gtk_paned_add2(GTK_PANED(vpan), GTK_WIDGET(nbook));
  /* Titel der Reiter mit entsprechenden Inhalt erzeugen  */
  /* und im Notizbuch hinzufügen */
  for(i=0; i < NBOOK; i++) {
    g_snprintf(buf,BUF,"Inhalt von GtkNotebook Seite %d",i+1);
    nbook_content[i] = g_object_new( GTK_TYPE_LABEL,
                                     "label", buf,
                                     NULL);
    g_snprintf(buf,BUF,"Seite %d",i+1);
    nbook_titel[i]   = g_object_new( GTK_TYPE_LABEL,
                                     "label", buf,
                                     NULL );
    gtk_notebook_append_page_menu(nbook,
                                  GTK_WIDGET(nbook_content[i]),
                                  GTK_WIDGET(nbook_titel[i]),
                                  NULL);
  }
  /* vertikale Button-Box erzeugen */
  vbutbox = gtk_button_box_new( GTK_ORIENTATION_VERTICAL );
  /* horizontale Button-Box erzeugen */
  hbutbox = gtk_button_box_new( GTK_ORIENTATION_HORIZONTAL );
  /* Buttons erzeugen und in die Button-Box packen */
  for(i=0; i < BUTTONS; i++ ) {
    g_snprintf(buf,BUF,"(v)Button %d",i+1);
    vbuttons[i] = g_object_new( GTK_TYPE_BUTTON,
                                "label", buf,
                                NULL);
    gtk_box_pack_start( GTK_BOX(vbutbox), GTK_WIDGET(vbuttons[i]), FALSE, FALSE, 0);

    g_snprintf(buf,BUF,"(h)Button %d",i+1);
    hbuttons[i] = g_object_new( GTK_TYPE_BUTTON,
                                "label", buf,
                                NULL );
    gtk_box_pack_start( GTK_BOX(hbutbox), GTK_WIDGET(hbuttons[i]), FALSE, FALSE, 0);
  }

  /* vbutbox oben-links von vpan mit den */
  /* Standardparametern hinzufügen       */
  gtk_paned_add1(GTK_PANED(vpan), GTK_WIDGET(vbutbox));
  /* hbutbox rechts-unten von hpan mit den */
  /* Standardparametern hinzufügen         */
  gtk_paned_add2(GTK_PANED(hpan), GTK_WIDGET(hbutbox));

  /* Signalhandler einrichten */
  g_signal_connect( win, "delete-event",
                    G_CALLBACK(delete_Event), NULL );
  g_signal_connect( win, "destroy",
                    G_CALLBACK(end), NULL );
  gtk_container_add(GTK_CONTAINER( win ), GTK_WIDGET( hpan ) );
  /* Fenster anzeigen */
  gtk_widget_show_all( GTK_WIDGET(win) );
  /* Hauptschleife von gtk */
  gtk_main();
  g_print("Die GTK-Hauptschleife wurde beendet\n");
  return 0;
}



