/* if6.c */
#include <stdio.h>

int main(void) {
   unsigned int alter;
   printf("Wie alt sind Sie: ");
   scanf("%u", &alter);

   if(alter <= 18){
   if(alter == 18){
   printf("Den F�hrerschein schon bestanden?\n");}
   else{
        printf("Sie sind noch nicht vollj�hrig\n");
       }}
   else{printf("Sie sind vollj�hrig\n");}
   printf("Bye\n");
   return 0;
}

