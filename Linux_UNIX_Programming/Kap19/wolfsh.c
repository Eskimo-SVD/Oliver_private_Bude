/* wolfsh.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255
#define OK 0

int main(int argc, char *argv[]) {
   char *command;
   /* Umgebungsvariable für die neue SHELL setzen */
   setenv("SHELL", "wolfsh", 1);
   /* Hier wird davon ausgegangen, dass die Shell mit
      von einem Shellscript mit der She-Bang-Zeile
      aufgerufen wurde  */
   if( argc > 1 ) {
      char puffer[MAX];
      /* Das Shellscript ist dann das erste Argument,
         welches jetzt Zeile-für-Zeile abgearbeitet wird */
      FILE *f1 = fopen ( argv[1], "r" );
      if( f1 == NULL ) exit(EXIT_FAILURE);
         while( (fgets(puffer, MAX, f1)) != NULL  ) {
            command = strtok(puffer, "\n");
            if( command == NULL ) exit(EXIT_SUCCESS);
         /* Die Erweiterungsbefehle zur vorhandenen Shell */
            if( strcmp(command, "howdie") == OK )
               printf("Ihr Befehl lautete \"howdie\"\n");
            else if( strcmp(command, "trouble") == OK )
               printf("Brauchen Sie Hilfe?\n");
            else if( strcmp(command, "bye") == OK )
               exit (EXIT_SUCCESS);
         /* ... oder Befehle die blockiert werden sollen */
            else if( strcmp(command, "whoami") == OK )
               printf("Befehl nicht erlaubt\n");
         /* ... und natürlich die Befehle, für die
                vorhandene Shell ausführen */
            else {
               system(command);
            }
         }
      fclose(f1);
   }
   /* Das gleich jetzt auch noch für die Kommandozeile */
   for (;;) {
      char puffer[MAX];
      printf("><(((o> ");
      fgets(puffer, MAX, stdin);
      command = strtok(puffer, "\n");
      if( strcmp(command, "howdie") == OK )
         printf("Ihr Befehl lautete \"howdie\"\n");
      else if( strcmp(command, "trouble") == OK )
         printf("Brauchen Sie Hilfe?\n");
      else if( strcmp(command, "bye") == OK )
         exit (EXIT_SUCCESS);
      else if( strcmp(command, "whoami") == OK )
         printf("Befehl nicht erlaubt\n");
      else {
         system(command);
      }
   }
   return EXIT_SUCCESS;
}
