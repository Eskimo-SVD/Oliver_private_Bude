/* bruteforce.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 255
#define MAX_DAT 10
#define MAX_LINE 4096
#define LINE "---------------------------------------\n"

struct datei{
   char name[LEN];  /* Name der Datei  */
   int gefunden;    /* Anzahl gefunden */
}; 
             
typedef struct datei DATEI;

/* int i = der Textzählerstand  
 * int j = der Musterzählerstand */
int BruteForce(char *muster, char *text) {
   int i = 0, j, cnt = 0;
   int m=strlen(muster); /* Länge Muster */
   int n=strlen(text);   /* Länge Text   */
   while (i<=n-m) {      /* Solange i kleiner als n-m zum Ende */
      /* Solang Muster und Text gleich j++ */
      for(j=0; j<m && muster[j]==text[i+j]; j++);
      if(j==m) { /* Ist die Länge von j gleich der vom Muster? */
         printf("Pos. %3d, ",i);
         cnt++;
      }
      i++; /* Im Text eine Position weiter */
   }
   return cnt;
}

int main(int argc, char **argv) {
   DATEI suche[MAX_DAT];
   char suchstring[LEN];
   char read_line[MAX_LINE];
   FILE *f;
   int i, j , ret, zeile;

   if(argc < 3) {
      fprintf(stderr, "Verwendung: %s suchstring datei1"
         " <datei2>  - <datei%d>\n",argv[0],MAX_DAT);
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
         ret = BruteForce(suchstring, read_line);
         if(ret != 0) {
            suche[i].gefunden+=ret;
            printf(" in Zeile %d\n",zeile);
            ret = 0;
         }
      }
      printf("Suchergebnisse in \"%s\": %d\n",
         suche[i].name, suche[i].gefunden);
      printf(LINE);
      fclose(f);  
   }
   return EXIT_SUCCESS;
}

