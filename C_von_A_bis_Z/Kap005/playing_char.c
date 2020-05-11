/* playing_char.c */
#include <stdio.h>

int main(void) {
   char a = 'A';
   char b = 65;
   int c  = 65;
   int d;

   printf("a = %c\n",a);
   printf("b = %c\n",b);    // Überrascht?
   printf("c = %c\n",c);    // Nochmals :)

   d = a + b + c;           // Rechenbeispiel
   printf("d = %d\n",d);

   d = 'a' + 'A';
   printf("d = %d\n",d);

   printf("char a = %c und %d\n",a,a);
   printf("char b = %c und %d\n",b,b);
   printf("int c = %c und %d\n",c,c);
   return 0;
}

