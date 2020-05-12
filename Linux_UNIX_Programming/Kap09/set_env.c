/* set_env.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255
/* Vorhandene Variable nicht �berschreiben */
#define PROTECT_ON  0
/* �berschreiben ... */
#define PROTECT_OFF 1

int main (void) {
  char name[MAX], neu_wert[MAX];

  printf("Umgebungsvariable: ");
  scanf("%254s",name);
  printf("Wert       : %s\n", getenv(name));

  printf("Wert �ndern/setzen durch : ");
  scanf("%254s",neu_wert);
  if( setenv( name, neu_wert, PROTECT_OFF ) != 0 )
     printf("Konnte neuen Wert nicht setzen\n");

  printf("Neuer Wert (%s) : %s\n", name, getenv(name));
  return EXIT_SUCCESS;
}
