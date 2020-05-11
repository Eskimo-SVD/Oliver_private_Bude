/* dyn_array3.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
   int *value,*temp;
   int i=0, more;
   int size, merker = 0;

   printf("Wie viele Werte benötigen Sie : ");
   scanf("%d", &size);
   value = malloc(size*sizeof(int));
   if(NULL == value) {
      printf("Fehler bei malloc...!! n");
      return EXIT_FAILURE;
   }
   do {
      while(merker < size) {
         printf("Wert für value[%d] eingeben : ",merker);
         scanf("%d",&value[merker]);
         merker++;
      }
      printf("Neuen Platz reservieren (0=Ende) : ");
      scanf("%d",&more);
      temp = malloc(size*sizeof(int));
      if(NULL == temp) {
         printf("Kann keinen Speicher mehr reservieren!\n");
         return EXIT_FAILURE;
      }
      for(i=0; i<size; i++)
         temp[i]=value[i];
      size+=more;
      value = malloc(size * sizeof(int));
      if(NULL == value) {
         printf("Kann keinen Speicher mehr reservieren!\n");
         return EXIT_SUCCESS;
      }
      for(i=0; i<size; i++)
         value[i]=temp[i];
   }while(more!=0);
   printf("Hier Ihre Werte\n");
   for(i=0; i<size; i++)
      printf("value[%d] = %d\n" ,i ,value[i]);
   return EXIT_SUCCESS;
}

