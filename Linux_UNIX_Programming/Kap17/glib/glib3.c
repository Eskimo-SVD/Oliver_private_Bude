/* glib3.c */
#include <gtk/gtk.h>
#define MMAX 100

int main(void) {
   gpointer *mem, *dup;
   gchar *text = "Text zum Kopieren";

   /* Speicher reservieren */
   mem = g_malloc(MMAX);
   /* Etwas in Speicher schreiben */
   g_snprintf((gchar *)mem, MMAX, "%s\n",text);
   /* Inhalt des Speichers ausgeben */
   g_print("mem: %s",(gchar *)mem);
   /* Speicherplatz duplizieren */
   dup = g_memdup(mem, MMAX);
   /* Inhalt des kopierten Speichers ausgeben */
   g_print("dup: %s",(gchar *)dup);
   /* Kopierten Speicherplatz freigeben */
   g_free(dup);
   /* Ein Fehler mit Absicht - Programmabbruch */
   mem = g_malloc( -1 );
   return 0;
}
