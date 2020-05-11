/* bin_search.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255

struct plzn{
   char ort[MAX];
   unsigned int plz;
};

struct plzn postleitzahlen[100];
static int N;

/* Initialisieren */
void init(void) {
   N = 0;
   postleitzahlen[N].plz = 0;
   strcpy(postleitzahlen[N].ort, "dummy");
}

void einfuegen(unsigned int p, char *o) {
   postleitzahlen[++N].plz = p;
   strcpy(postleitzahlen[N].ort, o);
}

int binaere_suche(unsigned int key) {
   int l=1;
   int r=N;
   int x;

   while(r >= l) {
      x=(l+r)/2;
      if(key < postleitzahlen[x].plz) /* kleiner? */
         r=x-1;  /* Rechte Seite ist nicht mehr so interessant */
       else      /* dann halt größer */
         l=x+1;  /* Linke Seite ist nicht mehr so interessant */
       if(key == postleitzahlen[x].plz)  
          return x;     /* Gefunden; x = Position*/
   }
   return -1; /* Nicht gefunden */
}

int main(void) {
   int wahl, ret;
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
         ret=binaere_suche(search);
         if(ret == -1)
            printf("Kein Ergebnis auf Ihre Anfrage!\n");
         else
            printf("Die Antwort auf %d : "
                   "%s\n",search,postleitzahlen[ret].ort);
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

