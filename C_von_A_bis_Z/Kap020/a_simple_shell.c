/* a_simple_shell.c */
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#define MAX 255
#define OK 0

jmp_buf restart;

void ctrlc(int sig) {
   signal(sig, ctrlc);
   /* Zurück zur Kommandozeile */
   longjmp(restart, 1);
   return;
}

int main(void) {
   char *command;
   /* Installiere den Signalhandler */
   signal(SIGINT, ctrlc);

   if(setjmp(restart) != 0)
      printf("\n\nShell neu gestartet ...\n\n");
   else 
      printf("\n\nShell gestartet ...\n\n");

   for (;;) {   /* Hier können Sie machen was Sie wollen */
      char puffer[MAX];
      printf("$~> ");
      fgets(puffer, MAX, stdin);
      command = strtok(puffer, "\n");

      if( strcmp(command, "test") == OK )
         printf("Ihr Befehl lautete \"test\"\n");
      else if( strcmp(command, "help") == OK )
         printf("Brauchen Sie Hilfe?\n");
      /* usw. eine Menge mehr Shellbefehle …*/
      else if( strcmp(command, "exit") == OK )
         exit (EXIT_SUCCESS);
      else {
         printf("\nUnbekannter Shellbefehl\n");
         printf("Bekannte Befehle: test, help, exit\n\n");
      }
   } 
   return EXIT_SUCCESS;
}

