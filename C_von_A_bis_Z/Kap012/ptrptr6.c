/* ptrptr6.c */
#include <stdio.h>
#include <stdlib.h>
#define ASK    0
#define WORDS  1
#define START  2

#define ENGLISH 1

#ifdef GERMAN
const char *language[] = {
   "Du sprichst Deutsch?", "Einige Worte: ", 
   "Feuer", "Erde", "Wasser", "Luft", "Leben", NULL
 };
#elif ENGLISH
const char *language[] = {
   "Do you speak english?", "Some words: ", 
   "Fire", "earth", "water", "air", "life", NULL
 };
#else /* FRENCH */
const char *language[] = {
   "Tu parle francais?", "quelques mots: ", 
   "Le feu", "La terre", "de l'eau", "de l'air", "La vie", NULL
 };
#endif

int main(void) {
   int i;

   printf("%s\n", language[ASK]);
   printf("%s\n",language[WORDS]);

   for(i = START; language[i] != NULL; i++)
      printf("\t%s,\n", language[i]);
   return EXIT_SUCCESS;
}

