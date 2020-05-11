/* count_push_pop.c */
#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

#ifdef DEBUG
   int push_cnt=0, pop_cnt=0;
#endif

void push(void) {
   #ifdef DEBUG
      push_cnt++;
      printf("Anzahl push : %d\n", push_cnt);
   #endif
   /* Ausführung von push */
}

void pop(void) {
   #ifdef DEBUG
      pop_cnt++;
      printf("\t\tAnzahl pop : %d\n", pop_cnt);
      if(pop_cnt > push_cnt)
         printf("Schwerer Fehler: pop_cnt darf nie größer"
                " als push_cnt sein\n");
   #endif
 /* Ausführung von pop */
}

int main(void) {
   push();
   push();
   pop();
   push();
   pop();
   pop();
   pop();    /* Fehler */
   return EXIT_SUCCESS;
}

