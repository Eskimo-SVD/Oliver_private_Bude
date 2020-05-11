/* func8.c */
#include <stdio.h>

static int zahl;
void verdoppeln(void);
void halbieren(void);

void verdoppeln(void) {
   zahl *= 2;
   printf("Verdoppelt: %d\n", zahl);
}

void halbieren(void) {
   zahl /= 2;
   printf("Halbiert: %d\n", zahl);
}

int main(void) {
   int wahl;

   printf("Bitte geben Sie eine Zahl ein: ");
   scanf("%d",&zahl);
   printf("Wollen Sie diese Zahl\n");
   printf("\t1.)verdoppeln\n\t2.)halbieren\n\nIhre Wahl: ");
   scanf("%d",&wahl);

   switch(wahl) {
      case 1  : verdoppeln();
                break;
      case 2  : halbieren();
                break;
      default : printf("Unbekannte Eingabe\n");
   }
   return 0;
}

