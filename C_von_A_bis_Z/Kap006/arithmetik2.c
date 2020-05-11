/* arithmetik2.c */
#include <stdio.h>

int main(void) {
   int x=2, y=4, z=6;

   printf("x=%d\n",x);
   printf("y=%d\n",y);
   printf("z=%d\n",z);  

   printf("%d\n",x+=y);
   printf("%d\n",z+=y);
   printf("%d\n",z+=x);

   printf("x=%d\n",x);     // x wurde verändert
   printf("y=%d\n",y);     // y bleibt gleich
   printf("z=%d\n",z);     // z wurde verändert
   return 0;
}

