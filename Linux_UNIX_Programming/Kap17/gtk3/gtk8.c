/* gkt8.c */
/* Mehrzeiliger Text                   */
/* mit Dateiauswahl - GtkFileSelection */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

/* Funktionsprototypen */
static GtkWindow *create_window (void);
static void create_tags (GtkTextBuffer * buffer);
static void on_button_clear_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_cut_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_copy_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_paste_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_bold_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_underline_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_strike_clicked (
                     GtkButton * button, gpointer user_data );
static void on_button_color_clicked (
                     GtkButton * button, gpointer user_data );
static void open_the_file (void);
static void file_open (
                     GtkButton * clicked, GtkWidget * selection);
static void on_button_save_clicked (
                     GtkButton * button, gpointer user_data );

static GtkToolItem *
insert_stock_button (GtkToolbar         *toolbar,
                     const gchar        *stock_id,
                     const gchar        *text,
                     GCallback           callback,
                     gpointer            user_data)
{
  GtkToolItem *button;

  button = gtk_tool_button_new_from_stock (stock_id);
  gtk_tool_item_set_tooltip_text (button, text);
  if(callback)
    g_signal_connect (G_OBJECT (button),
                      "clicked",
                      callback,
                      user_data);
  gtk_toolbar_insert (GTK_TOOLBAR (toolbar),
                      button,
                      -1); /*-1 bedeutet: ans Ende der Toolbar */
  return button;
}

/* Dateiname zum Öffnen */
static gchar *filename = NULL;
static GtkTextView *textview;
/* Dialog */
static GtkWidget *fileselect;

static GtkWindow * create_window (void) {
  GtkWindow *window;
  GdkPixbuf  *pic;
  GtkWidget *vbox_main;
  GtkToolbar *toolbar;
  GtkToolItem *button_clear, *button_cut, *button_copy,
  *button_paste, *button_bold, *button_underline,
  *button_strike, *button_color, *button_open,
  *button_save;
  GtkScrolledWindow *scrolledwindow;
  GtkTextBuffer *buffer;

  /* Eine Grafik in einen Pixbuf laden */
  pic = gdk_pixbuf_new_from_file("icon/at-work.gif", NULL );
  /* Fenster mit folgenden Eigenschaften anlegen */
  window = g_object_new( GTK_TYPE_WINDOW,
                         "title", "Textansicht- und Textpuffer",
                         "default-width",  300,
                         "default-height", 200,
                         "resizable", TRUE,
                         "window-position", GTK_WIN_POS_CENTER,
                         "border-width", 0,
                         "icon", pic,
                         NULL );
  /* eine vertikale Box erzeugen */
  vbox_main = gtk_box_new( GTK_ORIENTATION_VERTICAL , 0 );
  /* Eine neue Toolbar erzeugen */
  toolbar = g_object_new (GTK_TYPE_TOOLBAR,
                         /* "toolbar-style", GTK_TOOLBAR_ICONS,*/
                          NULL);
  /* Eine Textansicht erzeugen */
  textview = g_object_new( GTK_TYPE_TEXT_VIEW, NULL);
  /* Buttons mit Stock-icons für die Toolbar erzeugen */
  button_open = insert_stock_button (GTK_TOOLBAR (toolbar),
                                     GTK_STOCK_OPEN,
                                     "Datei oeffnen",
                                     G_CALLBACK (file_open),
                                     (gpointer) textview);
  button_save = insert_stock_button (GTK_TOOLBAR (toolbar),
                                     GTK_STOCK_SAVE,
                                     "Datei speichern",
                                     G_CALLBACK (on_button_save_clicked),
                                     (gpointer) textview);
  button_clear=insert_stock_button (GTK_TOOLBAR (toolbar),
                                    GTK_STOCK_CLEAR,
                                    "Text loeschen",
                                    G_CALLBACK (on_button_clear_clicked),
                                    (gpointer) textview);
  button_cut=insert_stock_button (GTK_TOOLBAR (toolbar),
                                  GTK_STOCK_CUT,
                                  "Text ausschneiden",
                                  G_CALLBACK (on_button_cut_clicked),
                                  (gpointer) textview);
  button_copy = insert_stock_button (GTK_TOOLBAR (toolbar),
                                     GTK_STOCK_COPY,
                                     "Text kopieren",
                                     G_CALLBACK (on_button_copy_clicked),
                                     (gpointer) textview);
  button_paste=insert_stock_button (GTK_TOOLBAR (toolbar),
                                    GTK_STOCK_PASTE,
                                    "Text einfuegen",
                                    G_CALLBACK (on_button_paste_clicked),
                                    (gpointer) textview);

  button_bold=insert_stock_button( toolbar, GTK_STOCK_BOLD,
                                   "Fette Schriftart",
                                   G_CALLBACK (on_button_bold_clicked),
                                   (gpointer) textview);
  button_underline=insert_stock_button( toolbar,
                                        GTK_STOCK_UNDERLINE,
                                        "Schrift unterstreichen",
                                        G_CALLBACK (on_button_underline_clicked),
                                        (gpointer) textview);
  button_strike=insert_stock_button( toolbar,
                                     GTK_STOCK_STRIKETHROUGH,
                                     "Schrift durchstreichen",
                                     G_CALLBACK (on_button_strike_clicked),
                                     (gpointer) textview);
  button_color=insert_stock_button( toolbar, GTK_STOCK_SELECT_COLOR,
                                    "farbig Schrift (blau)",
                                    G_CALLBACK (on_button_color_clicked),
                                    (gpointer) textview);
  /* Rollbalken erzeugen */
  scrolledwindow = g_object_new( GTK_TYPE_SCROLLED_WINDOW,
                      "hscrollbar_policy" , GTK_POLICY_AUTOMATIC,
                      "vscrollbar_policy" , GTK_POLICY_AUTOMATIC,
                      "window_placement"  , GTK_CORNER_TOP_LEFT,
                      NULL);
  /* Aktuellen Puffer für die Textansicht ermitteln */
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview));
  /* Einige einfache Tags zur Formatierung anlegen */
  create_tags (buffer);
  /* Dateiauswahlsbox erzeugen */
  fileselect = gtk_file_chooser_dialog_new(
                         "Bitte Datei auwaehlen ...",
                         NULL,
                         GTK_FILE_CHOOSER_ACTION_OPEN,
                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                         NULL);
  /* Signalhandler einrichten */
  g_signal_connect ( (gpointer) window, "delete_event",
                     G_CALLBACK (gtk_main_quit), NULL);
  /* Alles packen */
  gtk_container_add( GTK_CONTAINER (window),
                     GTK_WIDGET(vbox_main) );
  gtk_box_pack_start ( GTK_BOX (vbox_main),
                       GTK_WIDGET(toolbar),
                       FALSE, FALSE,0);
  gtk_box_pack_start ( GTK_BOX (vbox_main),
                       GTK_WIDGET(scrolledwindow),
                       TRUE,TRUE, 0);
  gtk_container_add ( GTK_CONTAINER (scrolledwindow),
                      GTK_WIDGET(textview));
  /* Erzeugtes Fenster zurückgegeben */
  return window;
}

/* "Markierten" Text im Puffer löschen */
static void
on_button_clear_clicked(GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Markierten Text löschen */
  gtk_text_buffer_delete_selection (textbuffer, TRUE, TRUE);
}

/* Text ausschneiden und in Zwischenablage legen */
static void
on_button_cut_clicked (GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Text im Puffer löschen und in Zwischenablage legen */
  gtk_text_buffer_cut_clipboard (textbuffer,
                             gtk_clipboard_get (GDK_NONE), TRUE);
}

/* Text vom Puffer kopieren und in Zwischenablage legen */
static void
on_button_copy_clicked (GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Text im Puffer in die Zwischenablage kopieren */
  gtk_text_buffer_copy_clipboard (textbuffer,
                                  gtk_clipboard_get (GDK_NONE));
}

/* Text aus der Zwischenablage in den Puffer legen */
static void
on_button_paste_clicked(GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Text aus der Zwischenablage  (falls vorhanden) */
  /*  in den Puffer kopieren                        */
  gtk_text_buffer_paste_clipboard (textbuffer,
                                   gtk_clipboard_get (GDK_NONE),
                                   NULL, TRUE);
}

/* Markierten Text im Puffer in Fett-Schrift darstellen */
static void
on_button_bold_clicked (GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  GtkTextIter start, end;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Markierte Auswahl im Puffer ermitteln */
  gtk_text_buffer_get_selection_bounds(textbuffer,&start, &end);
  /* Markierte Auswahl im Puffer mit neuer Formatierung */
  /* belegen                                            */
  gtk_text_buffer_apply_tag_by_name ( textbuffer, "bold",
                                      &start, &end);
}

/* Markieren Text im Puffer mit Unterstrich darstellen */
static void
on_button_underline_clicked ( GtkButton * button,
                              gpointer user_data ) {
  GtkTextBuffer *textbuffer = NULL;
  GtkTextIter start, end;

  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Markierte Auswahl im Puffer ermitteln */
  gtk_text_buffer_get_selection_bounds (textbuffer,&start,&end);
  /* Markierte Auswahl im Puffer mit neuer Formatierung */
  /*  belegen                                           */
  gtk_text_buffer_apply_tag_by_name ( textbuffer, "underline",
                                      &start, &end);
}

/* Markierten Text im Puffer Durchstreichen */
static void
on_button_strike_clicked(GtkButton *button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  GtkTextIter start, end;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Markierte Auswahl im Puffer ermitteln */
  gtk_text_buffer_get_selection_bounds(textbuffer,&start,&end);
  /* Markierte Auswahl im Puffer mit neuer Formatierung */
  /* belegen                                            */
  gtk_text_buffer_apply_tag_by_name ( textbuffer, "strike",
                                      &start, &end);
}

/* Markierten Text im Puffer mit neuer Farbe */
/* (hier blau) versehen                      */
static void
on_button_color_clicked(GtkButton * button, gpointer user_data) {
  GtkTextBuffer *textbuffer = NULL;
  GtkTextIter start, end;
  g_assert (GTK_IS_TEXT_VIEW (user_data));
  /* Aktuellen Puffer für die Textansicht ermitteln */
  textbuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));
  /* Markierte Auswahl im Puffer ermitteln */
  gtk_text_buffer_get_selection_bounds (textbuffer,&start,&end);
  /* Markierte Auswahl im Puffer mit neuer Formatierung */
  /* belegen                                            */
  gtk_text_buffer_apply_tag_by_name ( textbuffer, "color",
                                      &start, &end);
}

/* Einge Textformatierungen (Tags) erstellen */
static void create_tags (GtkTextBuffer * buffer) {
  g_assert (GTK_IS_TEXT_BUFFER (buffer));
  /* Fette Schrift */
  gtk_text_buffer_create_tag (buffer, "bold",
                              "weight", PANGO_WEIGHT_BOLD, NULL);
  /* Unterstrichene Schrift */
  gtk_text_buffer_create_tag (buffer, "underline",
                             "underline", PANGO_UNDERLINE_SINGLE,
                             NULL);
  /* Durchgestrichene Schrift */
  gtk_text_buffer_create_tag (buffer, "strike",
                              "strikethrough", TRUE,
                              NULL);
  /* Schrift in blauer Farbe */
  gtk_text_buffer_create_tag (buffer, "color",
                              "foreground", "blue",
                              NULL);
}

/* Datei zum lesen Öffnen */
static void
open_the_file(void) {
  FILE *f;
  gchar buf[255];
  GtkTextBuffer *buffer = NULL;
  GtkTextIter end;

  if (filename == NULL)
    return; /* Datei existiert nicht */
  f = fopen (filename, "r");
  if (NULL == f) {
    printf("Keine solche Datei vorhanden!!\n");
    return;
  }
  else {
    buffer = gtk_text_view_get_buffer (
               GTK_TEXT_VIEW (textview) );
    while(fgets(buf,255,f)) {
      gtk_text_buffer_get_end_iter(buffer, &end);
      gtk_text_buffer_insert(buffer, &end, buf, -1);
    }
  }
  fclose (f);
}

static void
file_open (GtkButton * clicked, GtkWidget * selection) {
  GtkTextBuffer *buffer = NULL;
  /* Neue Datei öffnen, daher:
     + Dateinamen auf NULL setzen
     + Inhalt bereits von bereits vorhandenen Text löschen */
  filename = NULL;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview));
  gtk_text_buffer_set_text(buffer,"", -1);
  gint returnvalue = gtk_dialog_run (GTK_DIALOG (fileselect));
  if(returnvalue==GTK_RESPONSE_ACCEPT) {
    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (fileselect));
    open_the_file();
  }
  gtk_widget_hide(fileselect);
}

/* Datei abspeichern - ohne wenn und aber !*/
static void
on_button_save_clicked (GtkButton * button, gpointer user_data) {
  GtkTextBuffer *buffer = NULL;
  GtkTextIter start, end;
  gchar *buf;
  gchar *dyn;
  FILE *f;

  if(filename != NULL) {
    /* Aktuellen Puffer für die Textansicht ermitteln */
    buffer = gtk_text_view_get_buffer (
               GTK_TEXT_VIEW (user_data) );
    /* Markierte Auswahl im Puffer ermitteln */
    gtk_text_buffer_get_bounds (buffer, &start, &end);
    /* Zeiger auf den kompletten Text zurück */
    buf=gtk_text_buffer_get_text(buffer, &start, &end, TRUE);
    dyn = g_malloc( strlen(buf)+1 );
    g_stpcpy( dyn, buf );
    /* Zur Kontrolle Ausgabe auf die Konsole */
    g_print("%s\n... gespeichert!\n",dyn);
    f = fopen(filename, "w");
    if(f != NULL)
      fwrite(dyn, strlen(dyn)+1, 1, f);
    fclose(f);
  }
}

int main (int argc, char **argv) {
  GtkWindow *window;
  gtk_init (&argc, &argv);
  window = create_window ();
  gtk_widget_show_all (GTK_WIDGET(window));
  gtk_main ();
  return 0;
}
