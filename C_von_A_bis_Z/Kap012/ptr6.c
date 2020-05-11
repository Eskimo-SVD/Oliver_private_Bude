/* ptr6.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *ptr;
   int var=10, tmp;

   /* ptr zeigt auf Adresse von var */
   ptr =& var;
   /* Variable tmp bekommt den Wert, den ptr dereferenziert */
   tmp = *ptr;       /* tmp=10 */
   *ptr = 100;       /* Inhalt von var wird verändert var=100 */  
   if(var > 50)      /* Ist var größer als 50 ... ? */
      var = tmp;       /* ... wieder den alten Wert   */
   printf("var=%d\t*ptr=%d\n",var, *ptr); /* var=10   *ptr=10 */
   return EXIT_SUCCESS;
}

