/* kmpsearch.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 255
#define MAX_DAT 10
#define MAX_LINE 4096
#define MAX 255
#define LINE "_______________________________________\n"

struct datei{
   char name[LEN];  /* Name der Datei  */
   int gefunden;    /* Anzahl gefunden */
}; 
             
typedef struct datei DATEI;

int next[MAX];

int kmp_Search(char *, char *);
void init_next(char *, int);

int kmp_Search(char *muster, char *text) {
   int i=0, j=0, cnt=0;
   int m=strlen(muster);  /* Länge Muster */
   int n=strlen(text);    /* Länge Text   */

   init_next(muster, m);  /* Tabelle für next berechnen */
   while (i<n) {   /* Solange wir nicht am Ende vom Text sind */ 
      while (j>=0 && text[i]!=muster[j])j=next[j];
      i++; j++;
      if (j==m) {
         printf("Gefunden an Pos. %d\n", i-j);
         cnt++;
         j=next[j];
      }
   }
   return cnt;
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
      (muster[i]==muster[j]) ? (next[i]=next[j]) : (next[i]=j);
   }
}

int main(int argc, char **argv) {
   DATEI suche[MAX_DAT];
   char suchstring[LEN];
   char read_line[MAX_LINE];
   FILE *f;
   int i, j , ret, zeile;
   
   if(argc < 3) {
      fprintf(stderr, "Verwendung: %s suchstring datei1 "
         "<datei2> ... <datei%d>\n",argv[0],MAX_DAT);
      return EXIT_FAILURE;
   }

   strncpy(suchstring, argv[1], LEN);
   /* Kommandozeilen-Argumente auswerten */  
   for(i=2,j=0; j < MAX_DAT && i < argc; i++,j++) {
      strncpy(suche[j].name, argv[i], LEN);
      suche[j].gefunden = 0;
   }
   for(i = 0; i < argc-2; i++) {
      f = fopen(suche[i].name, "r");
      if(f == NULL) {
         perror(NULL);
         continue;
      }
      zeile = 0;
      printf("\nDatei \"%s\": \n",suche[i].name);
      while( fgets(read_line, MAX_LINE, f) != NULL) {
         zeile++;
         ret = kmp_Search(suchstring, read_line);
         if(ret != 0) {
            suche[i].gefunden+=ret;
            printf(" in Zeile %d\n",zeile);
            ret=0;
         }
      }
      printf("Suchergebnisse in \"%s\": %d\n",
         suche[i].name, suche[i].gefunden);
      printf(LINE);
      fclose(f);  
   }
   return EXIT_SUCCESS;
}

