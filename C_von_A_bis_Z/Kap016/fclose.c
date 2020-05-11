/* fclose.c */
#include <stdio.h>
#include <stdlib.h> 

int main(void) {
   FILE *quell,*ziel;
   char quellname[20],zielname[20];
   int c, wahl;

   printf("Bitte geben sie den Namen der Zieldatei an : ");
   scanf("%19s",zielname);
   if( (ziel=fopen(zielname,"a+")) == NULL) {
      printf("Konnte \"%s\" nicht erstellen bzw finden!\n",
         zielname);
      printf("...oder Sie haben unzureichende Rechte \n");
      return EXIT_SUCCESS;
   }

   do {
      printf("Welche Datei wollen sie in "
             "die Zieldatei schreiben,\n");
      printf("bzw. anhängen (name.xxx) : ");
      scanf("%19s",quellname);
      quell= fopen(quellname,"r");
      if(NULL == quell) {
         printf("Konnte %s nicht öffnen!\n",quellname);
         return EXIT_FAILURE;
      }
      else {
         while((c=getc(quell)) != EOF)
            putc(c,ziel);
         fclose(quell);
      }
      printf("Weitere Datei an %s anhängen (1=ja/2=nein): ",
         zielname);
      scanf("%1d",&wahl);
   } while(wahl == 1);
   return EXIT_SUCCESS;
}

