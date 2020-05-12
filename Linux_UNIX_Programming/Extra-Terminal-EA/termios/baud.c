/* baud.c */
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
 
typedef unsigned long Ulong;
typedef struct termios TTY;

static speed_t baud_konstante[] = {
       B0, B50, B75, B110, B134, B150, B200, B300, B600, B1200,
       B1800, B2400, B4800, B9600, B19200, B38400, B57600,
       B115200, B230400/*, B460800 */
     };

static Ulong baud_werte[] = {
       0, 50, 75, 110, 134, 150, 200, 300, 600, 1200,
       1800, 2400, 4800, 9600, 19200, 38400, 57600,
       115200, 230400/*, 460800 */
     };

static Ulong baudrate_wert (speed_t baud) {
  int i;
  for (i = 0; i <= 19; i++) {
    if (baud == baud_konstante[i])
      return (baud_werte[i]);
  }
  return -1;
}

int main (int argc, char **argv) {
  int fd;
  speed_t baud_input, baud_output;
  TTY terminal;

  if (argc != 2) {
    printf ("Usage: %s Ger�tepfad\n", *argv);
    exit (EXIT_FAILURE);
  }
  if ((fd = open (argv[1], O_RDWR | O_NONBLOCK)) == -1) {
    perror ("fopen()");
    exit (EXIT_FAILURE);
  }
  if (isatty (fd) == 0) {
    printf ("%s ist keine tty\n", argv[1]);
    exit (EXIT_FAILURE);
  }
  if (tcgetattr (fd, &terminal) == -1) {
    printf ("Fehler bei tcgetattr()\n");
    exit (EXIT_FAILURE);
  }
  if((baud_input=baudrate_wert(cfgetispeed(&terminal))) == -1) {
    printf ("Fehler bei baud_input ...\n");
    exit (EXIT_FAILURE);
  }
  if((baud_output=baudrate_wert(cfgetospeed(&terminal))) == -1) {
    printf ("Fehler bei baud_output ...\n");
    exit (EXIT_FAILURE);
  }
  printf ("Eingabe-Baudrate : %d\n", baud_input);
  printf ("Ausgabe_Baudrate : %d\n", baud_output);
  return EXIT_SUCCESS;
}
