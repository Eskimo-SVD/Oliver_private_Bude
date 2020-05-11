/* if6.c */
#include <stdio.h>

int main(void) {
   unsigned int alter;
   printf("Wie alt sind Sie: ");
   scanf("%u", &alter);

   if(alter <= 18){
   if(alter == 18){
   printf("Den Führerschein schon bestanden?\n");}
   else{
        printf("Sie sind noch nicht volljährig\n");
       }}
   else{printf("Sie sind volljährig\n");}
   printf("Bye\n");
   return 0;
}

