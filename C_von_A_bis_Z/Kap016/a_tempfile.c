/* a_tempfile.c */
#include <stdio.h>
#include <stdlib.h>

char string[] = {
   "Dies ist der String für die Testdatei\n"
   "Diese Zeile ist ein Lückenfüller !!!!\n"
   "Aber diese Zeile soll verändert werden\n"
   "Hier könnten noch viele Zeilen mehr stehen\n"
};

void create_text_file(void) {
   FILE *out = fopen("test.txt", "w");
   if(NULL == out) exit(EXIT_FAILURE);
   fputs(string, out);
   fclose(out);
}

int main(void) {
   FILE *in, *out;
   char line[80], *tmp;
   int line_nr = 1;

   /* Es wird eine Datei mit dem Inhalt string erzeugt */
   create_text_file();
   /* Die Datei zum Ändern wird zum Lesen geöffnet */
   in  = fopen("test.txt", "r");
   if(NULL == in) {
      fprintf(stderr, "Konnte Datei nicht erzeugen!\n");
      return EXIT_FAILURE;
   }
   tmp = tmpnam(NULL);     /* Temporäre Datei erzeugen */
   /* Temporäre Datei zum Schreiben öffnen */
   out = fopen(tmp, "w");  
   if(NULL == out) {
      fprintf(stderr, "Konnte Datei nicht öffnen!\n");
      return EXIT_FAILURE;;
   }
   /* Aus der Datei zeilenweise lesen und in 
    *  temporäre Datei schreiben */    
   while( NULL != fgets(line, 80, in)) {
      /* Es soll die dritte Zeile geändert werden */
      if(line_nr == 3)
         fputs("Ein veränderte Zeile!\n", out);
      else
         fputs(line, out);
      line_nr++;
   }
   fclose(in);
   fclose(out);
   remove("test.txt");        /* Original löschen           */
   rename(tmp, "test.txt");   /* Temporäre Datei umbenennen */
   return EXIT_SUCCESS;
}

