/* func10.c */
#include <stdio.h>

void mixed(int x, char y, float z) {
   printf("Stückzahl : %d ",x);
   printf("Klasse    : %c ",y);
   printf("Preis     : %.2f Euro\n",z);
}

int main(void) {
   mixed(6, 'A', 5.5f);
   mixed(9, 'B', 4.3f);
   return 0;
}

