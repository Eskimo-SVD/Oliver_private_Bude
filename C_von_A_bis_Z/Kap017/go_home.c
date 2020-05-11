/* go_home.c */
#ifdef __unix__
    #include <unistd.h>
#elif __WIN32__ || _MS_DOS_
    #include <dir.h>
#else
    #include <direct.h> /* Visual C++ */
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int main(void) {
   char puffer[MAX];
   char home[MAX];
   if( getenv("HOME") == NULL ) {
	   printf("getenv(\"HOME\") findet nichts\n");
	   return EXIT_FAILURE;
   }
   /* Das Heimatverzeichnis nach home */
   strncpy(home, getenv("HOME"), MAX-1);
   home[MAX-1] = '\0';
   /* Working Directory lesen */
   if(getcwd(puffer,sizeof(puffer)) == NULL) {
      fprintf(stderr, "Fehler bei getcwd ...\n");
      return EXIT_FAILURE;
   }
   /* Sind wir schon im Heimatverzeichnis? */
   if(strcmp(home,puffer) == 0)
      printf("Wir sind daheim : %s\n",puffer);
   else { /* Nicht! Dann wechseln wir in Heimatverzeichnis */
      chdir(home);
      /* Der Beweis: */
      printf("back at home: %s \n",
         getcwd(puffer,sizeof(puffer)));
   }
   return EXIT_SUCCESS;
}