/* c_v_cpp.c */
#include <stdio.h>

int main(void) {
   printf("Hallo Welt\n");
   int i;                      // Fehler in C, ok in C++

   scanf("%d",&i);
   for(int x=0; x < i; x++) {  // Fehler in C, ok in C++
      // Ok in C und C++, da am Anfang von Anweisungsblock
      int x=2;
      printf("%d*%d=%d\n",x,i,x*i);
   }
   return 0;
}

