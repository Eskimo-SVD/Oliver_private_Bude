/* danger.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255

char *danger[] = { 
   "scanf", "sscanf", "fscanf",
   "gets", "strcat", "strcpy", 
   "printf", "fprintf", "sprintf",
   "vsprintf", "system", NULL 
   /* u.s.w. */
};
                   
int main(int argc, char **argv) {
   FILE *fp;
   char puffer[MAX];
   int i, line=1;

   if(argc < 2) {
      printf("Anwendung: %s <datei.c>\n\n", argv[0]);
      return EXIT_FAILURE;
   }
   if ( (fp=fopen(argv[1], "r+")) == NULL) {
      printf("Konnte Datei nicht zum Lesen öffnen\n");
      return EXIT_FAILURE;
   }    
   while( (fgets(puffer, MAX, fp)) != NULL) {
      i=0;
      while(danger[i] != NULL) {
         if( (strstr(puffer,danger[i])) !=0 )
            printf("%s gefunden in Zeile %d\n",
               danger[i],line);
         i++;
      }
      line++; 
   }
   fclose(fp);
   return EXIT_SUCCESS;
}

