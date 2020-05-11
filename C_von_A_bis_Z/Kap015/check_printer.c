/* check_printer.c */
#include <stdio.h>
#include <stdlib.h>
#ifndef __MSDOS__
   #error "!!!Beispiel läuft nur unter MS-DOS!!!"
#else
   #include <dos.h>
#endif
/* 0x378 ist die Adresse der Schnittstelle von LPT1 */
#define LPT1_PORT 0x378

struct status {
   unsigned        :3;     /* Bit 0-2 nicht verwendet */
   unsigned fehler :1;     /* 0=Druckerfehler         */
   unsigned online :1;     /* 1=Drucker online        */
   unsigned papier :1;     /* 1=kein Papier           */
   unsigned empfang:1;     /* Emfangsbestätigung      */
   unsigned busy   :1;     /* Drucker bereit          */
} LPT1_status;

/*Status am LPT1-Port auslesen*/
void druckerstatus(char *statuszeiger) {
   *statuszeiger = inp( LPT1_PORT+1 ) & 0xF8;
}

int main(void) {
   druckerstatus( (char *) &LPT1_status);
   if(LPT1_status.busy && LPT1_status.online) {
      printf("Drucker ist bereit!\n");
      return EXIT_SUCCESS;
   }
   else if(!LPT1_status.online)
      printf("Drucker nicht online!\n");
   else if(LPT1_status.papier)
      printf("Kein Papier vorhanden!\n");
   else
      printf("Drucker ist nicht bereit!\n");
   return EXIT_SUCCESS;
}


