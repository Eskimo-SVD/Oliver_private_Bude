/* keystroke.c */
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

/*Altes Terminal wiederherstellen */
static struct termios BACKUP_TTY;

/* Eingabekanal wird so umge�ndert damit die Tasten einzeln */
/* abgefragt werden k�nnen                                  */
static int new_tty (int fd) {
  struct termios buffer;

  /* Wir erfragen nach den Attributen des Terminals und */
  /* �bergeben diese dann an buffer. BACKUP_TTY dient   */
  /* bei Programmende zur Wiederherstellung der alten   */
  /* Attribute und bleibt somit unber�hrt.              */
  if ((tcgetattr (fd, &BACKUP_TTY)) == -1)
    return -1;
  buffer = BACKUP_TTY;

  /* Lokale Flags werden gel�scht :                           */
  /* ECHO - Zeichenausgabe auf Bildschirm                     */
  /* ICANON - Zeilenorientierter Eingabemodus                 */
  /* ISIG - Terminal Steuerzeichen (kein STRG+C mehr m�glich) */
  buffer.c_lflag = buffer.c_lflag & ~(ECHO | ICANON | ISIG);

  /* VMIN=Anzahl der Bytes die gelesen werden m�ssen, */
  /* bevor read() zur�ckkehrt                         */
  /* In unserem Beispiel 1Byte f�r 1 Zeichen          */
  buffer.c_cc[VMIN] = 1;

  /*Wir setzen jetzt die von uns gew�nschten Attribute*/
  if ((tcsetattr (fd, TCSAFLUSH, &buffer)) == -1)
    return -1;
  return 0;
}

/*Urspr�ngliches Terminal wiederherstellen*/
static int restore_tty (int fd) {
  if ((tcsetattr (fd, TCSAFLUSH, &BACKUP_TTY)) == -1)
    return -1;
  return 0;
}

int main (int argc, char **argv) {
  int rd;
  char c, buffer[10];

  /*Setzen des neuen Modus*/
  if (new_tty (STDIN_FILENO) == -1) {
    printf ("Fehler bei der Funktion new_tty()\n");
    exit (EXIT_FAILURE);
  }
  do {
    /*Erste Zeichen lesen*/
    if (read (STDIN_FILENO, &c, 1) < 1) {
      printf ("Fehler bei read\n");
      restore_tty (STDIN_FILENO);
      exit (EXIT_FAILURE);
    }

    /*Haben wir ein ESC ('\E') gelesen? */
    if (c == 27) {
      /* Ja eine Escape-Sequenz, wir wollen den Rest */
      /* der Zeichen auslesen                        */
      rd = read (STDIN_FILENO, buffer, 4);
      buffer[rd] = '\0';   /*String terminieren */
      /*Folgende Werte haben die Funktionstasten in der Term */
      /*   F1 = \E[[A            */
      /*   F2 = \E[[B            */
      /*   PFEIL RECHTS= \E[C    */
      /*   PFEIL LINKS = \E[D    */
      /*   PFEIL RUNTER= \E[B    */
      /*   PFEIL HOCH = \E[A     */
      /*   POS 1 = \E[1~         */
      /*   BILD RUNTER = \E[6~   */
      /*   BILD HOCH = \E[5~     */

      if (strcmp (buffer, "[[A") == 0)
        printf ("F1\n");
      if (strcmp (buffer, "[[B") == 0)
        printf ("F2\n");
      if (strcmp (buffer, "[C") == 0)
        printf ("->\n");
      if (strcmp (buffer, "[D") == 0)
        printf ("<-\n");
      if (strcmp (buffer, "[B") == 0)
        printf ("V\n");
      if (strcmp (buffer, "[A") == 0)
        printf ("^\n");
      if (strcmp (buffer, "[1~") == 0)
        printf ("POS 1\n");
      if (strcmp (buffer, "[6~") == 0)
        printf ("BILD RUNTER\n");
      if (strcmp (buffer, "[5~") == 0)
        printf ("BILD HOCH\n");
      /* Nein kein ESC ... */
    }
    else {
      if ((c < 32) || (c == 127))
        /*Numerischen Wert Ausgeben */
        printf ("%d\n", c);
      else
        /*Zeichen ausgeben */
        printf ("%c\n", c);
    }
  } while (c != 'q');
  restore_tty (STDIN_FILENO);
  return EXIT_SUCCESS;
}
