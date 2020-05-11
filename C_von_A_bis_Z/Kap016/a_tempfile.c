/* a_tempfile.c */
#include <stdio.h>
#include <stdlib.h>

char string[] = {
   "Dies ist der String f�r die Testdatei\n"
   "Diese Zeile ist ein L�ckenf�ller !!!!\n"
   "Aber diese Zeile soll ver�ndert werden\n"
   "Hier k�nnten noch viele Zeilen mehr stehen\n"
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
   /* Die Datei zum �ndern wird zum Lesen ge�ffnet */
   in  = fopen("test.txt", "r");
   if(NULL == in) {
      fprintf(stderr, "Konnte Datei nicht erzeugen!\n");
      return EXIT_FAILURE;
   }
   tmp = tmpnam(NULL);     /* Tempor�re Datei erzeugen */
   /* Tempor�re Datei zum Schreiben �ffnen */
   out = fopen(tmp, "w");  
   if(NULL == out) {
      fprintf(stderr, "Konnte Datei nicht �ffnen!\n");
      return EXIT_FAILURE;;
   }
   /* Aus der Datei zeilenweise lesen und in 
    *  tempor�re Datei schreiben */    
   while( NULL != fgets(line, 80, in)) {
      /* Es soll die dritte Zeile ge�ndert werden */
      if(line_nr == 3)
         fputs("Ein ver�nderte Zeile!\n", out);
      else
         fputs(line, out);
      line_nr++;
   }
   fclose(in);
   fclose(out);
   remove("test.txt");        /* Original l�schen           */
   rename(tmp, "test.txt");   /* Tempor�re Datei umbenennen */
   return EXIT_SUCCESS;
}

