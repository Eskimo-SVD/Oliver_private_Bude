/* widechar.c */
#include <stdio.h>
#include <stddef.h>

int main(void) {
   wchar_t ch1=L'Z';
   wchar_t ch2;
   printf("Bitte ein Zeichen eingeben: ");
   scanf("%lc", &ch2);
   printf("%lc %lc\n", ch1, ch2);
   return 0;
}
