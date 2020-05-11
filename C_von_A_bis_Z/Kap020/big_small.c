/* big_small.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Prototypen */
void grosschrift(char *, char *);
void kleinschrift(char *, char *);
void international(char *,char *);
void oeffne_dateien(char *, char *, FILE **, FILE **);

void grosschrift(char *arg2, char *arg3) {
   FILE *in,*out;
   int c;

   oeffne_dateien(arg2,arg3,&in,&out);
   while((c=getc(in)) != EOF) {
      if(islower(c))
         putc(toupper(c),out);
      else
         putc(c,out);
   }
}

void kleinschrift(char *arg2, char *arg3) {
   FILE *in,*out;
   int c;

   oeffne_dateien(arg2,arg3,&in,&out);
   while((c=getc(in)) != EOF) {
      if(isupper(c))
         putc(tolower(c),out);
      else
         putc(c,out);
   }
}

void international(char *arg2, char *arg3) {
   FILE *in,*out;
   int c;

   oeffne_dateien(arg2,arg3,&in,&out);
   while((c=getc(in)) != EOF) {
      if(isascii(c)==0)
         putc(toascii(c),out);
      else
         putc(c,out);
   }
}

void oeffne_dateien(char *quelle, char *ziel, 
                    FILE **input, FILE **output) {
   if((*input=fopen(quelle,"r+")) == NULL) {
      printf("Fehler beim Öffnen (lesen) von %s\n", quelle);
      exit(EXIT_FAILURE);
   }
   if((*output=fopen(ziel,"w+")) == NULL) {
      printf("Fehler beim Öffnen (schreiben) von %s\n", ziel);
      exit(EXIT_FAILURE);
   }
}

int main(int argc, char *argv[]) {
   if(argc<4) {
      printf("Verwendung: "
      "Programmname -[Schalter] datei.txt Zieldatei.txt\n"
      "für -[Schalter] : -b (kompl. Textdatei in Grossschrift)\n"
      "                  -s (kompl. Textdatei in Kleinschrift)\n"
      "                  -i (nat. Zeichen zu ASCII-Zeichen\n");
         return EXIT_FAILURE;
   }
   if(strcmp(argv[1],"-b")==0)
      grosschrift(argv[2],argv[3]);
   else if(strcmp(argv[1],"-s")==0)
      kleinschrift(argv[2],argv[3]);
   else if(strcmp(argv[1],"-i")==0)
      international(argv[2],argv[3]);
   else {
      printf("Verwendung: "
      "Programmname -[Schalter] datei.txtZieldatei.txt\n"
      "für -[Schalter] : -b (kompl. Textdatei in Grossschrift)\n"
      "                  -s (kompl. Textdatei in Kleinschrift)\n"
      "                  -i (nat. Zeichen zu ASCII-Zeichen\n");
         return EXIT_SUCCESS;
   }
   return EXIT_SUCCESS;
}

