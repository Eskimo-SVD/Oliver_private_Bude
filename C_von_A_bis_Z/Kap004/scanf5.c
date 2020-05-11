/* scanf5.c */
#include <stdio.h>

int main(void) {
   char ch;
   char buf[2];
    
   printf("Ein Zeichen bitte : ");
   fgets(buf, 2, stdin);
   sscanf(buf, "%c", &ch);
   printf("Das Zeichen : %c\n",ch);
   return 0;
}

