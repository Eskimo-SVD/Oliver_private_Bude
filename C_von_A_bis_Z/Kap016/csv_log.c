/* csv_log.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   FILE *CSV;
   int login_hour, login_min;
   int date_day, date_mon, date_year;
   char name[40];
   int logout_hour, logout_min;
   int date_dayx, date_monx, date_yearx;

   if(argc < 2) {
      fprintf(stderr, "Verwendung : %s datei.csv\n", *argv);
      return EXIT_FAILURE;
   }
   CSV = fopen(argv[1], "r");
   if(NULL == CSV) {
      fprintf(stderr, "Fehler beim Oeffnen ...\n");
      return EXIT_FAILURE;
   }

   /* Nun lesen Sie formatiert von der Datei ein ... */
   while((fscanf(CSV,"%d:%d,%d.%d.%d,%d:%d,%d.%d.%d,%s\n",
      &login_hour,&login_min,&date_day,&date_mon,&date_year,
      &logout_hour,&logout_min,&date_dayx,&date_monx,
      &date_yearx,name)) != EOF )
       fprintf(stdout,"User:%s\nLogin um:%d:%d Uhr am %d.%d.%d\n"
                      "Logout um : %d:%d Uhr am %d.%d.%d\n\n",
         name,login_hour,login_min,date_day,date_mon,date_year,
         logout_hour,logout_min,date_dayx,date_monx, date_yearx);
   return EXIT_SUCCESS;
}

