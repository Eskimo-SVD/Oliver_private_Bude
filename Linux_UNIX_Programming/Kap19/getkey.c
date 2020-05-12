/* getkey.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
enum { ERROR=-1, SUCCESS, ONEBYTE };
/*Altes Terminal wiederherstellen*/
static struct termios BACKUP_TTY; /*Altes Terminal wiederherstellen*/
/* Eingabekanal wird so umge�ndert, damit die Tasten einzeln */
/* abgefragt werden k�nnen */
int new_tty(int fd) {
   struct termios buffer;
/* Wir fragen nach den Attributen des Terminals und �bergeben  */
/* diese dann an buffer. BACKUP_TTY dient bei Programmende zur */
/* Wiederherstellung der alten Attribute und bleibt unber�hrt. */
   if((tcgetattr(fd, &BACKUP_TTY)) == ERROR)
      return ERROR;
   buffer = BACKUP_TTY;
/* Lokale Flags werden gel�scht :               */
/*     ECHO = Zeichenausgabe auf Bildschirm     */
/*     ICANON = Zeilenorientierter Eingabemodus */
/*     ISIG = Terminal Steuerzeichen            */
   buffer.c_lflag = buffer.c_lflag & ~(ECHO|ICANON|ISIG);
/* VMIN=Anzahl der Bytes, die gelesen werden m�ssen, bevor    */
/* read() zur�ckkehrt In unserem Beispiel 1Byte f�r 1 Zeichen */
   buffer.c_cc[VMIN] = 1;
/* Wir setzen jetzt die von uns gew�nschten Attribute */
   if((tcsetattr(fd, TCSAFLUSH, &buffer)) == ERROR)
      return ERROR;
   return SUCCESS;
}
/* Urspr�ngliches Terminal wiederherstellen */
int restore_tty(int fd) {
   if((tcsetattr(fd, TCSAFLUSH, &BACKUP_TTY)) == ERROR)
      return ERROR;
   return SUCCESS;
}
int main(int argc, char **argv) {
   int rd;
   char c, buffer[10];
/* Setzen des neuen Modus */
   if(new_tty(STDIN_FILENO) == ERROR) {
      printf("Fehler bei der Funktion new_tty()\n");
      exit(EXIT_FAILURE);
   }
/* Erste Zeichen lesen */
   if(read(STDIN_FILENO, &c, 1) < ONEBYTE) {
      printf("Fehler bei read()\n");
      restore_tty(STDIN_FILENO);
      exit(EXIT_FAILURE);
   }
/* Haben wir ein ESC ('\E') gelesen? */
   if(c == 27) {
/* Jep eine Escape-Sequenz, wir wollen den Rest */
/* der Zeichen auslesen                         */
      rd=read(STDIN_FILENO, buffer, 4);
      /*String terminieren*/
      buffer[rd]='\0';
/* Hier erfolgt die �berpr�fung des Tastendrucks*/
/* Wars der Pfeil-nach-oben \E[A   */
      if(strcmp(buffer,"[A") == SUCCESS)
         printf("Pfeil-nach-oben bet�tigt\n");
/* Nein, keine Escape-Sequenz */
   }
   else {
      if((c < 32) || (c == 127))
         printf("--> %d\n",c); /* Numerischen Wert ausgeben */
      else
         printf("--> %c\n",c); /* Zeichen ausgeben */
   }
   restore_tty(STDIN_FILENO);
   return EXIT_SUCCESS;
}
