/* bufferoverflow4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funktion(int tmp,char *array) {
   char puffer[5];
   int *pointer;

   strcpy(puffer, array);
   printf("%s\n",puffer);
   /* pointer auf dem Stack 4 Bytes zur�ck 
      Sollte jetzt auf die R�cksprungadresse zeigen */
   pointer=&tmp-1; 
   /*R�cksprungadresse, auf die Pointer zeigt, 10 Bytes weiter*/
   *pointer=*pointer+10;
}

int main(void) {
   int a;

   a=0;
   funktion(7,"hallo");
   a=1;
   printf("wert = %d\n",a);
   return EXIT_SUCCESS;
}

