/* strcmp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void String_Vergleich(char s1[], char s2[]) {
   int ret = strcmp (s1, s2);
   if(ret == 0)
      printf("%s == %s\n", s1, s2);
   else
      printf("%s %c %s\n",s1,( (ret < 0) ?'<' :'>'), s2);
}

int main(void) {
   char str1[] = "aaa";
   char str2[] = "aab";
   char str3[] = "abb";

   String_Vergleich(str1, str2);
   String_Vergleich(str1, str3);
   String_Vergleich(str3, str2);
   String_Vergleich(str1, str1);
   return EXIT_SUCCESS;
}

