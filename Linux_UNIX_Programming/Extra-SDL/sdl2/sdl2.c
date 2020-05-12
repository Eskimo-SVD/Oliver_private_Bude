/* sdl2.c */
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Surface sperren */
static void Lock( SDL_Surface *screen ) {
  /* Muss gesperrt werden ? */

  if (SDL_MUSTLOCK (screen)) {
    if (SDL_LockSurface (screen) < 0) {
      printf ("Konnte Surface nicht sperren: %s\n",
         SDL_GetError ());
      return;
    }
  }
}

/* Surface freigeben */
static void Unlock( SDL_Surface *screen ) {
  if (SDL_MUSTLOCK (screen)) {
    SDL_UnlockSurface (screen);
  }
}

/* Einen 32-Bit RGB-Wert zurückgeben */
static Uint32 GetColor( SDL_Surface *screen,
                        Uint8 R, Uint8 G, Uint8 B ) {
  return SDL_MapRGB( screen->format, R, G, B );
}

/* Einen Pixel zeichnen */
static void DrawPixel (SDL_Surface * screen, int x, int y,
                       Uint8 R, Uint8 G, Uint8 B) {
  /* Surface sperren falls nötig */
  Lock( screen );
  /* Farbtiefe des Surface ermitteln (in Byte) */
  switch (screen->format->BytesPerPixel) {
  case 1:     /* 1 Byte */
    {         /* Auflösung: 8 Bit */
      Uint8 *bufp;
      /* Position x, y des Pixels an bufp */
      bufp = (Uint8 *) screen->pixels + y * screen->pitch + x;
      /* Farbe des Pixels verändern */
      *bufp = GetColor( screen, R, G, B );
    }
    break;
  case 2:     /* 2 Bytes */
    {         /* Auflösung: 15 Bit oder 16 Bit */
      Uint16 *bufp;
      /* Position x, y des Pixels an bufp */
      bufp=(Uint16 *)screen->pixels + y * screen->pitch / 2 + x;
      /* Farbe des Pixels verändern */
      *bufp = GetColor( screen, R, G, B );
    }
    break;
  case 3:  /* 3 Bytes */
    {      /* 24-Bit-Modus, wird hier nicht verwendet */
      printf ( "Der 24-Bit-Modus wird in diesem Beispiel"
               " nicht unterstützt\n");
      exit (EXIT_FAILURE);
    }
    break;
  case 4:     /* 4 Byte */
    {         /* Auflösung: 32 Bit */
      Uint32 *bufp;
      /* Position x, y des Pixels an bufp */
      bufp=(Uint32 *)screen->pixels + y * screen->pitch / 4 + x;
      /* Farbe des Pixels verändern */
      *bufp = GetColor( screen, R, G, B );
    }
  default:
    printf ("Konnte die Farbtiefe nicht ermitteln!?!?\n");
    break;
  }
  /* Sperre wieder aufheben falls nötig */
  Unlock( screen );
  /* Den Bereich der Verändert wurde neu zeichnen */
  SDL_UpdateRect (screen, x, y, 1, 1);
}

int main (void) {
  SDL_Surface *screen;
  int i, points = 50000;

  /* SDLs Video-System initialisieren und auf Fehler prüfen */
  if (SDL_Init (SDL_INIT_VIDEO) != 0) {
    printf ("Konnte SDL nicht initialisieren: %s\n",
       SDL_GetError ());
    return EXIT_FAILURE;
  }
  /* Wenn die Anwendung beendet wird,          */
  /* wird die Funktion SDL_Quit() ausgeführt   */
  atexit (SDL_Quit);
  /* Videomodus mit 640x480 Pixeln, Hi-Color (16 Bit) */
  /* einrichten Oberfläche (Surface) Standardmäßig    */
  /* in den Hauptspeicher (SDL_SWSURFACE) legen       */
  screen = SDL_SetVideoMode (320, 200, 16, SDL_SWSURFACE);
  if (screen == NULL) {
    printf ("Videomodus konnte nicht eingerichtet werden: "
            " %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  for (i = 0; i < points; i++) {
    DrawPixel(screen, rand () % 320, rand () % 200, 0, 0, 255);
    DrawPixel(screen, rand () % 320, rand () % 200, 0, 255, 0);
    DrawPixel(screen, rand () % 320, rand () % 200, 255, 0, 0);
    DrawPixel(screen, rand () % 320, rand () % 200, 255,255,0);
  }
  /* 1000 ms warten ... */
  SDL_Delay (1000);  
  printf ("Erfolgreich beendet!\n");
  return EXIT_SUCCESS;
}

