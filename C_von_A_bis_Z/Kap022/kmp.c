/* kmp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096

void init_next(char *, int);
void kmpSearch(char *, char *);

int next[MAX];

/* i = Position im Text */
/* j = Position im Muster */
void kmpSearch(char *muster, char *text) {
   int i=0, j=0;
   int m=strlen(muster);  /* Länge Muster */
   int n=strlen(text);    /* Länge Text   */

   init_next(muster, m);  /* Tabelle für next berechnen */
   while (i<n) {  /*Solange wir nicht am Ende vom Text sind*/
      while (j>=0 && text[i]!=muster[j])j=next[j];
      i++; j++;
      if (j==m) {
         printf("Gefunden an Pos. %d\n", i-j);
         j = next[j];
      }
   }
}

void init_next(char *muster, int m) {
   int i, j;

   i = 0;
   j = next[0] = -1;
   /* Solange i kleiner als der Suchstring ist */
   while (i < m) {
      while (j > -1 && muster[i] != muster[j])
         j = next[j];
      i++;
      j++;
      (muster[i] == muster[j]) ? (next[i]=next[j]) : (next[i]=j);
   }
}

int main(void)  {
   kmpSearch("alalas", "lu lalalala lule lulalalas");
   return EXIT_SUCCESS;
}

