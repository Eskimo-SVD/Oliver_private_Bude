/* time4.c */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   FILE *datei;
   time_t time1;
   struct tm *time2;
   char zeit[25];
   int c;

   if(argc<2) {
      printf("Bitte Eingeben : %s textdatei.txt\n",*argv);
      return EXIT_FAILURE;
   }
   if((datei = fopen(*++argv,"w+")) == NULL) {
      printf("Konnte Datei : %s nicht öffnen!!!!\n",*argv);
      return EXIT_FAILURE;
   }
   printf("Eingabe machen (mit '#' beenden)\n>");
   /* Wir schreiben in unsere Datei und beenden diese
    * mit dem Zeichen '#'  */
   while((c=getchar()) != '#')
      putc(c, datei);
   putc('\n', datei);

   /* Zuerst time_t-Format */
   time(&time1);
   printf("Heute ist %s und Sie haben eben die "
          "Datei %s geschlossen\n",ctime(&time1), *argv);

   /* Jetzt struct tm-Format mit asctime() */
   time1=time(NULL);
   time2=localtime(&time1);
   strcpy(zeit,asctime(time2));

   /* Das Datum schreiben wir in die Datei... */
   fprintf(datei,"%s\n",zeit);
   fclose(datei);
   return EXIT_SUCCESS;
}

