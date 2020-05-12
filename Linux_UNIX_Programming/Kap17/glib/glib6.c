/* glib6.c */
#include <gtk/gtk.h>
#include <string.h>
#define MMAX 255

int main(void) {
   GString *gstr;
   guint size;
   gint val = 1;

   gstr = g_string_new("GString initialisiert");
   g_print("%s mit %d Bytes\n\n",gstr->str, gstr->len);

   g_string_assign(gstr,
           "g_string_assign() ueberschreibt den Orginal-String");
   g_print("%s\n\n", gstr->str);

   g_string_append(gstr,
            "\n-> hinzugefuegt mit g_string_append()");
   g_print("%s\n\n", gstr->str);
   /* Einzelnes Zeichen hinzufügen am Ende */
   g_string_append_c(gstr, '!');
   g_print("%s\n\n", gstr->str);

   g_string_prepend(gstr,
            "Vorne angefuegt mit g_string_prepend()\n");
   g_print("%s\n\n", gstr->str);
   /* Einzelnes Zeichen hinzufügen am Anfang */
   g_string_prepend_c(gstr, '!');
   g_print("%s\n\n", gstr->str);

   g_string_insert(gstr, 10, " xxxEINGEFUEGTxxx " );
   g_print("%s\n\n", gstr->str);

   size = strlen(gstr->str);
   /* String löschen */
   g_string_erase(gstr, 0, size);

   g_string_sprintf(gstr,
            "Puffer wird mit g_string_sprintf() automatisch"
            " verwaltet (%d)\n",val);
   g_print("%s\n\n", gstr->str);
   return 0;
}
