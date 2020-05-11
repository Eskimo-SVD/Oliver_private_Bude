/* time2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm *tmnow;

void today(void) {
   time_t tnow;

   time(&tnow);
   tmnow = localtime(&tnow);
   printf("Heute ist der ");
   printf("%d.%d.%d\n",
      tmnow->tm_mday, tmnow->tm_mon + 1, tmnow->tm_year + 1900);
}

int main(void) {
   int tag, monat, jahr;
   unsigned int i=0, tmp;

   printf("Bitte gib Deinen Geburtstag ein!\n");
   printf("Tag : ");
   scanf("%d", &tag);
   printf("Monat : ");
   scanf("%d", &monat);
   printf("Jahr (jjjj) : ");
   scanf("%d", &jahr);
   today();
   if(tmnow->tm_mon < monat) {
      i = 1;
      tmp=tmnow->tm_mon+1-monat;
      monat=tmp+12;
   }
   else {
      tmp=tmnow->tm_mon+1-monat;
      monat=tmp;
   }
   if(monat == 12) {
      monat = 0;
      i = 0;
   }
   printf("Sie sind %d Jahre %d Monate %d Tage alt\n",
      tmnow->tm_year+1900-jahr-i,monat, tmnow->tm_mday-tag);
   return EXIT_SUCCESS;
}

