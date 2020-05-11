/* regular_expression.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 4096

int pmatch(char *, char *);
int match(char *, char *);
int wildcard(int, char *, char *);
int my_grep(char *, FILE *, char *);

int pmatch(char *ausdruck, char *text) {
   if(ausdruck[0] == '^')
      return match(ausdruck+1, text);
   for( ; *text != '\0'; *text++)
      if(match(ausdruck, text))
         return 1;
   return 0;
}

int match(char *ausdruck, char *text) {
   if(ausdruck[0] == '\0')
      return 1;
#ifdef __unix__
   if(ausdruck[1] == '*')
#elif __WIN32__
   if(ausdruck[1] == '~')
#endif
      return wildcard(ausdruck[0], ausdruck+2, text);
   if(ausdruck[0] == '$' && ausdruck[1] == '\0')
      return *text == '\0';
   if(*text != '\0' && ( ausdruck[0] == '.' ||
     ausdruck[0] == *text))
      return match(ausdruck+1, text+1);
   return 0;
}

int wildcard(int c, char *ausdruck, char *text) {
   for( ;*text != '\0' && (*text == c || c == '.'); *text++)
      if(match(ausdruck, text))
         return 1;
   return 0;
}

int my_grep(char *ausdruck, FILE *f, char *name) {
   int n, nmatch=0;
   int line=0;
   char buffer[BUF];

   while(fgets(buffer, sizeof(buffer), f) != NULL) {
      line++;
      n = strlen(buffer);
      if(n > 0 && buffer[n-1] == '\n')
         buffer[n-1] = '\0';
      if(pmatch(ausdruck, buffer)) {
         nmatch++;
         if(name != NULL)
            printf("%d. ",line);
      }
   }
   if(nmatch!=0)
      printf("Zeile in der Datei %s (insg.%d)\n\n",name,nmatch);
   return nmatch;
}

int main(int argc, char **argv) {
   int i, nmatch=0;
   FILE *f;

   if(argc <= 2) {
      fprintf(stderr, "Verwendung des Programms : "
         "%s pattern quelle\n\n",*argv);
      return EXIT_FAILURE;
   }
   else {
      for(i = 2; i < argc; i++) {
         f = fopen(argv[i], "r");
         if(NULL == f) {
            fprintf(stderr, "Konnte %s nicht "
               "öffnen\n",argv[i]);
            continue;
         }
         if(my_grep(argv[1],f, argv[i]) > 0)
            nmatch++;
         fclose(f);
      }
   }
   printf("%d Dateien mit passenden Pattern %s gefunden\n",
      nmatch, argv[1] );
   return EXIT_SUCCESS;
}

