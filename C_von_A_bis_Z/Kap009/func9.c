/* func9.c */
#include <stdio.h>

void verdoppeln(int);
void halbieren(int);

void halbieren(int zahl) {
   zahl /= 2;
   printf("Halbiert : %d\n", zahl);
}

void verdoppeln(int zahl) {
   zahl *= 2;
   printf("Verdoppelt : %d\n", zahl);
}

int main(void) {
   int wahl, z;

   printf("Bitte geben Sie eine Zahl ein : ");
   scanf("%d",&z);
   printf("Wollen Sie diese Zahl\n");
   printf("\t1.)verdoppeln\n\t2.)halbieren\n\nIhre Wahl : ");
   scanf("%d",&wahl);

   switch(wahl) {
      case 1  : verdoppeln(z);
                break;
      case 2  : halbieren(z);
                break;
      default : printf("Unbekannte Eingabe\n");
    }
   return 0;
}

