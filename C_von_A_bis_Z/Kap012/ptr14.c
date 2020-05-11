/* ptr14.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fehler: Funktion gibt die Adresse
 * einer lokalen Variablen zurück */
char *test1(void){
   char buffer[10];
   strcpy(buffer, "testwert");
   return buffer;
}

/* Möglichkeit1: Statische Variable */
char *test2(void){
   static char buffer[10];
   strcpy(buffer, "testwert");
   return buffer;
}

/* Möglichkeit2: Speicher vom Heap verwenden */
char *test3(void){
   char *buffer = (char *) malloc(10);
   strcpy(buffer, "testwert");
   return buffer;
}

/* Möglichkeit3: Einen Zeiger als Argument übergeben */
char *test4(char *ptr){
   char buffer[10];
   ptr = buffer;
   strcpy(buffer, "testwert");
   return ptr;
}

int main(void) {
   char *ptr;

   ptr = test1();
   printf("test1: %s\n", ptr); /* Datenmüll */
   ptr = test2();
   printf("test2: %s\n", ptr);   
   ptr = test3();
   printf("test3: %s\n", ptr);   
   test4(ptr);
   printf("test4: %s\n", ptr);
   return EXIT_SUCCESS;
}

