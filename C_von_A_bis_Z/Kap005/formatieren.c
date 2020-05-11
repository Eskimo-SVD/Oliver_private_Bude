/* formatieren .c */
#include <stdio.h>

int main (void) {
   char text[]="Tiefstand";
   printf("|01234567890123456789|\n");
   printf("|%s|\n",text);
   printf("|%20s|\n",text);
   printf("|%-20s|\n",text);
   printf("|%20s|\n",text+4);
   printf("|%20.4s|\n",text);
   printf("|%-20.4s|\n",text);
   printf("|%-20s|\n",text+4);
   return 0;
}

