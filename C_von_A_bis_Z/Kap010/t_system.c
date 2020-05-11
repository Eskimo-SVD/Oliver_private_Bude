/* t_system.c */
#include <stdio.h>
#include <stdlib.h>

#ifdef __MSDOS__
int main(void) {
   printf("Programm läuft unter MSDOS \n");
   return EXIT_SUCCESS;
}

#elif __WIN32__ || _MSC_VER
int main(void) {
   printf("Programm läuft unter Win32\n");
   return EXIT_SUCCESS;
} 

#elif __unix__ || __linux__
int main(void) {
   printf("Programm läuft unter UNIX/LINUX\n");
   return EXIT_SUCCESS;
} 

#else
int main(void) {
   printf("Unbekanntes Betriebssystem!!\n");
   return EXIT_SUCCESS;
}
#endif

