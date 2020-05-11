/* clrscr.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__ 
   #define clrscr() printf("\x1B[2J")
#elif __BORLANDC__ && __MSDOS__
   #include <conio.h>
#elif __WIN32__ || _MSC_VER
   #define clrscr() system("cls")
#else
   #define clrscr() printf("clrscr() - Fehler!!\n")
#endif

int main(void) {
   /* Universale Routine zum Löschen des Bildschirms */
   clrscr();
   return EXIT_SUCCESS;
}

