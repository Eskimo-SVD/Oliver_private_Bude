/* variadic2.c */
#include <stdio.h>
#include <stdlib.h>

#define fprintf_log(...) fprintf(fp, __VA_ARGS__)
#define errprintf(...) fprintf(stderr, __VA_ARGS__)
#define checkerror(x, ...) if(!(x)) { fprintf(stderr, __VA_ARGS__); }
#define LOGFILE "logfile.txt"

static FILE *fp;

void openLog(void) {
   fp = fopen(LOGFILE, "w+");
   if( NULL == fp ) {
      errprintf("%s:%d: Konnte Logdatei nicht öffnen\n", __func__, __LINE__);
      exit(EXIT_FAILURE);
   }
}

int main(void) {
  char name[80];
  int val, check;

  openLog();
  fprintf_log("(%s/%s): Programmstart\n", __DATE__, __TIME__);

  printf("Bitte Namen eingeben: ");
  fgets( name, 80, stdin);
  fprintf_log("Eingabe \"name\": %s", name);

  printf("Bitte eine Ganzzahl eingeben: ");
  check = scanf("%d", &val);
  // wird nur ausgeführt, wenn die
  // Eingabe bei scanf() falsch war
  checkerror(check, "Die Eingabe war falsch\n");

  return EXIT_SUCCESS;
}