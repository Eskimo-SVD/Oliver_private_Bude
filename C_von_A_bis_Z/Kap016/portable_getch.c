/* portable_getch.c */
#include <stdio.h>
#include <stdlib.h>
/* ... übersetzt unter Linux/UNIX? */
#ifdef __unix__
#include <termios.h>
#include <unistd.h>

static struct termios new_io;
static struct termios old_io;

/* Funktion schaltet das Terminal in den cbreak-Modus:        */
/* Kontrollflag ECHO und ICANON auf 0 setzen                  */
/* Steuerzeichen: Leseoperation liefert 1 Byte VMIN=1 VTIME=1 */
int cbreak(int fd) {
   /*Sichern unseres Terminals*/
   if((tcgetattr(fd, &old_io)) == -1)
      return -1;
   new_io = old_io;
   /*Wir verändern jetzt die Flags für den cbreak-Modus*/
   new_io.c_lflag = new_io.c_lflag & ~(ECHO|ICANON);
   new_io.c_cc[VMIN] = 1;
   new_io.c_cc[VTIME]= 0;

   /*Jetzt setzen wir den cbreak-Modus*/
   if((tcsetattr(fd, TCSAFLUSH, &new_io)) == -1)
      return -1;
   return 1;
}

int getch(void) {
   int c;

   if(cbreak(STDIN_FILENO) == -1) {
      printf("Fehler bei der Funktion cbreak ... \n");
      exit(EXIT_FAILURE);
   }
   c = getchar();
   /*Alten Terminal-Modus wiederherstellen*/
   tcsetattr(STDIN_FILENO, TCSANOW, &old_io);
   return c;
}

/* ... oder wird das Programm unter MS-Windows übersetzt? */
#elif __WIN32__ || _MSC_VER || __MS_DOS__
  #include <conio.h>
#endif

int main(void) {
  int zeichen;

  printf("Bitte 'q' drücken, um das Programm zu beenden!\n");
   /* Wartet auf das Zeichen q */
  while(( zeichen=getch() ) != 'q');
  return EXIT_SUCCESS;
}

