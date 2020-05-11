/* qsort.c */
#include <stdio.h>
#include <stdlib.h>

/* Vergleichsfunktion */
int cmp(const void *ptr1, const void *ptr2) {
   if( *(int *)ptr1 < *(int *)ptr2 )
      return -1;
   else if( *(int *)ptr1 > *(int *)ptr2 )
      return 1;
   else 
      return 0;  /* Beide Elemente sind gleich */
}

int main(void) {
   int wert[] = { 2, 5, 2, 7, 6, 4, 2 };
   int i;

   printf("Daten vor dem Sortieren\n");
   for(i = 0; i < sizeof(wert)/sizeof(int); i++)
      printf("%d\t", wert[i]);
   printf("\n");

   /* Jetzt sortieren mit qsort() */
   qsort(wert, sizeof(wert)/sizeof(int), sizeof(int), cmp);

   printf("Daten nach dem Sortieren mit qsort()\n");
   for(i = 0; i < sizeof(wert)/sizeof(int); i++)
      printf("%d\t", wert[i]);
   printf("\n");
   return EXIT_SUCCESS;
}

