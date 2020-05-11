/* ptr_func4.c */
#include <stdio.h>
#include <stdlib.h>
/* Bei Linux für math.h den Compilerflag -lm mitangeben:
 *     gcc -o programm programm.c -lm
 */
#include <math.h>    /* sqrt() */

int addition(int zahl) {
   int y;

   printf("%d+>", zahl);
   scanf("%d", &y);
   fflush(stdin);
   return zahl += y;
}

int subtraktion(int zahl) {
   int y;

   printf("%d->", zahl);
   scanf("%d", &y);
   fflush(stdin);
   return zahl -= y;
}

int division(int zahl) {
   int y;

   printf("%d/>",zahl);
   scanf("%d", &y);
   fflush(stdin);
   return zahl /= y;
}

int multiplikation(int zahl) {
   int y;

   printf("%d*>",zahl);
   scanf("%d", &y);
   fflush(stdin);
   return zahl *= y;
}

int sqrtw(int zahl) {
   double x=sqrt((double)zahl);

   printf("(sqrt)%f>", x);
   return (int)x;
}

int (*rechenfunk[]) (int) = {
   addition, subtraktion, division, multiplikation, sqrtw 
};

int main(void) {
   char op;
   static int zahl;  

   printf("no.>");
   scanf("%d",&zahl);
   do {
      printf(" op>");
      scanf("%c",&op);
      fflush(stdin);
      switch(op) {
         case '+': printf("%d", zahl = (*rechenfunk[0])(zahl));
                   break;
         case '-': printf("%d", zahl = (*rechenfunk[1])(zahl)); 
                   break;
         case '/': printf("%d", zahl = (*rechenfunk[2])(zahl)); 
                   break;
         case '*': printf("%d", zahl = (*rechenfunk[3])(zahl)); 
                   break;
         case 'q': printf("%d", zahl = (*rechenfunk[4])(zahl)); 
                   break;
         default : printf("op '=','+','-','/','*','q'\n");   
      }
   } while(op != '=');
   printf("Gesamtergebnis=%d\n",zahl);
   return EXIT_SUCCESS;
}

