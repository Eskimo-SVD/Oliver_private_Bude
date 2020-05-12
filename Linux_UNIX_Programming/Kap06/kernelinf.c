/* kernelinf.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define BUF 4096

enum { EJECT, FILE_MAX, SHARED_MAX  };
enum { CDINFO, OS, RELEASE, VERSION };

static const char *sys[] = {
  /* Bei umount CD auswerfen */
  "/proc/sys/dev/cdrom/autoeject",
  /* max. Anzahl geöffneter Datei pro Prozess */
  "/proc/sys/fs/file-max",
  /*max. Größe geteilter Speicher (Shared Memory) */
  "/proc/sys/kernel/shmmax"
};

static const char *info[] = {
  "/proc/sys/dev/cdrom/info",     /* Info's zur CD-ROM      */
  "/proc/sys/kernel/ostype",      /* Welches Betriebsystem  */
  "/proc/sys/kernel/osrelease",   /* Kernelversion          */
  "/proc/sys/kernel/version"      /* Kernel von wann        */
};

static char *get_info (const char *inf) {
  FILE *fp;
  static char buffer[BUF];
  size_t bytes_read;

  fp = fopen (inf, "r");
  if (fp == NULL) {
    perror("fopen()");
    return NULL;   /* Fehler beim öffnen */
  }
  bytes_read = fread (buffer, 1, sizeof (buffer), fp);
  fclose (fp);
  if (bytes_read == 0 || bytes_read == sizeof (buffer))
    return NULL;
  buffer[bytes_read] = '\0';
  return buffer;
}

static void set_sys (const char *sys, unsigned long set) {
  FILE *fp;
  char buf[32];

  fp = fopen (sys, "w");
  if (fp == NULL) {
    perror ("fopen()");
    printf ("Weiter mit ENTER\n");
    getchar ();
    return;
  }
  sprintf(buf, "%ld", set);
  fprintf (fp, "%s", buf);
  fclose (fp);
  return;
}

int main (int argc, char **argv) {
  int auswahl;
  unsigned int file_max;
  unsigned long shared_max;

  do {
    printf ("Aktueller Zustand\n");
    printf ("Betriebssystem : %s", get_info (info[OS]));
    printf ("Kernelversion  : %s", get_info (info[RELEASE]));
    printf ("Datum          : %s", get_info (info[VERSION]));
    printf ("------------------------------------\n");
    printf ("Verändern können Sie folgendes ...\n");
    printf ("-0- Bei \"umount\"  CD auswerfen"
            " Aktuell:%s", get_info (sys[EJECT]));
    printf ("-1- Max. Anzahl geöffneter Datei pro"
            " Prozess    Aktuell:%s",get_info (sys[FILE_MAX]));
    printf ("-2- Max. Größe des geteiltem Speicher"
            " (KB)     Aktuell %s",get_info (sys[SHARED_MAX]));
    printf ("------------------------------------\n");
    printf ("Informationen bekommen Sie zu ...\n");
    printf ("-3- CD-ROM\n");
    printf ("------------------------------------\n");
    printf ("-4- ENDE\n");
    printf ("Ihre Auswahl bitte (0-4) : ");

    do { scanf ("%d", &auswahl); } while (getchar () != '\n');
    switch (auswahl) {
    case EJECT:
      if (strncmp ("0", get_info (sys[EJECT]),1) == 0)
        set_sys (sys[EJECT], 1); /* Setzen */
      else      /* Zurücksetzen */
        set_sys (sys[EJECT], 0);
      break;
    case FILE_MAX:
      printf ("Welcher Wert soll gesetzt werden : ");
      do { scanf("%d", &file_max); } while (getchar() != '\n');
      set_sys (sys[FILE_MAX], file_max);
      break;
    case SHARED_MAX:
      printf ("Welcher Wert soll gesetzt werden : ");
      do { scanf("%ld", &shared_max);} while (getchar() != '\n');
      set_sys (sys[SHARED_MAX], shared_max);
      break;
    case 3:
      printf ("%s", get_info (info[CDINFO]));
      printf ("Weiter mit ENTER\n");
      getchar ();
      break;
    case 4:
      printf("Programm wird beendet\n");
      break;
    default:
      printf ("Unbekannte Eingabe\n");
    }
  } while (auswahl != 4);
  return EXIT_SUCCESS;
}
