/* simple_search.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255

struct plz{
   char ort[MAX];
   unsigned int postleit;
};

struct plz postleitzahlen[100];
static int N;

/* Initialisieren */
void init(void) {
   N = 0;
   postleitzahlen[N].postleit = 0;
   strcpy(postleitzahlen[N].ort, "init");
}

void einfuegen(unsigned int p, char *o) {
   postleitzahlen[++N].postleit = p;
   strcpy(postleitzahlen[N].ort, o);
}

void suche(unsigned int key) {
   int i;
   for(i=0; i<=N; i++)
   if(postleitzahlen[i].postleit == key) {
      printf("Der Ort zur Postleitzahl %d : %s\n",
         key,postleitzahlen[i].ort);
      return;
   }
   printf("Für den Wert %d konnte keine Postleitzahl "
          "gefunden werden!\n",key);
}

int main(void) {
   int wahl;
   unsigned int search, post;
   char new_ort[MAX];
   init();

   do {
      printf("-1- Postleitzahl suchen\n");
      printf("-2- Postleitzahl hinzufügen\n");
      printf("-3- Ende\n\n");
      printf("Ihre Wahl : ");
      scanf("%d",&wahl);
      getchar();
      if(wahl == 1) {
         printf("Welche Postleitzahl suchen Sie : ");
         scanf("%5u",&search);
         suche(search);
      }
      else if(wahl == 2) {
         printf("Neue Postleitzahl : ");
         scanf("%5u",&post);
         getchar();
         printf("Ort für PLZ %d : ",post);
         fgets(new_ort, MAX, stdin);
         einfuegen(post, strtok(new_ort, "\n") );
      }
   } while(wahl!=3);
   return EXIT_SUCCESS;
}

