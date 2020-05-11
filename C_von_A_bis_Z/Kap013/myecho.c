/* myecho.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h> /* tolower(), toupper(), isalpha() */
#include <stdlib.h>
#define FALSE 0
#define TRUE  1
#define BUF 4096

void show_help(void) {
   printf("\nProgrammaufruf: myecho [OPTION] STRING\n"\
          "Programm gibt den Text in gewünschter Form auf"\
          "dem Bildschirm aus\n\nFolgende Optionen stehen"\
          "Ihnen zur Verfügung:\n\n"\
          "\t-r  Text wird spiegelverkehrt ausgegeben\n"\
          "\t-g  Text wird in Grossbuchstaben ausgegeben\n"\
          "\t-s  Text wird in Kleinbuchstaben ausgegeben\n "\
          "\t-h  Dieser Text\n"
          "\t-v  Versionsnummer\n\n");
}

int getopt(char *argument, char *option) {
   if( argument[0]=='-' && argument[1]==option[0] )
      return TRUE;
   return FALSE;
}

void spiegeln(char *string) {
   char *reverse=string;

   while(*reverse++);
   while(*reverse-- != *string)
      printf("%c",*reverse);
   printf("\n");
}

void larger(char *string) {
   char *large=string;

   while(*large)
      printf("%c",(isalpha(*large))?toupper(*large++):*large++);
   printf("\n");
}

void smaller(char *string) {
   char *small=string;

   while(*small)
      printf("%c",(isalpha(*small))?tolower(*small++):*small++);
   printf("\n");
}

int main(int argc, char *argv[]) {
   int counter=3;
   char buffer[BUF];
   size_t len=0;

   if(argc == 1 || getopt(argv[1],"h") == TRUE ) {
      show_help();
      return EXIT_FAILURE;   
   }
   else if(getopt(argv[1],"v") == TRUE) {
      printf("Version 1.0\n");
      return EXIT_SUCCESS;   
   }
   else if(argc < 3) {
      show_help();
      return EXIT_FAILURE;
   }    
   len=strlen(argv[2])+1;
   /* Ab argv[2] bis argv[n] alle Elemente in buffer */
   if(len > BUF) {
      printf("Der String enthält zu viele Zeichen\n");
      return EXIT_FAILURE;  
   }
   strcpy(buffer,argv[2]);
   while(argv[counter] != NULL) {
      len += strlen(argv[counter])+2;
      if(len > BUF) {
         printf("Der Puffer ist bereits voll\n");
         break;
      }
      strcat(buffer, " ");
      strcat(buffer, argv[counter++]);
   }
   if(getopt(argv[1],"r") == TRUE)
      spiegeln(buffer);
   else if(getopt(argv[1],"g") == TRUE)
      larger(buffer);
   else if(getopt(argv[1],"s") == TRUE)
      smaller(buffer);
   else
      show_help();
   return EXIT_SUCCESS;
}

