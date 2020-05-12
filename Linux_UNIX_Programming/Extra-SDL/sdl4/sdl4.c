/* sdl4.c */
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void display_bmp( const char *datei, SDL_Surface *screen,
                         int x, int y) {
  SDL_Surface *bild;
  SDL_Rect ziel;
  /* lädt die BMP-Datei in ein Surface */
  bild = IMG_Load(datei);
  if ( bild == NULL ) {
    fprintf(stderr, "'%s' konnte nicht geladen werden: %s\n",
       datei, SDL_GetError());
    return;
  }
  /* auf den Bildschirm kopieren                     */
  /* die Surfaces sollten hier nicht gelockt sein.   */
  /* x,y = linke obere Ecke; w, h = Breite und Höhe  */
  ziel.x = x;
  ziel.y = y;
  ziel.w = bild->w;
  ziel.h = bild->h;
  /* Neue Größe des Surfaces entsprechend der Bildgröße */
  screen = SDL_SetVideoMode (bild->w, bild->h,
                             16, SDL_SWSURFACE | SDL_RESIZABLE);
  if (screen == NULL) {
    printf ("Videomodus konnte nicht verändert werden: %s\n",
       SDL_GetError ());
    exit(EXIT_FAILURE);
  }
  SDL_BlitSurface(bild, NULL, screen, &ziel);
  /* den veränderten Bildschirm-Bereich auffrischen */
  SDL_UpdateRect(screen, 0, 0, 0, 0);
  SDL_FreeSurface(bild);
}

int main (int argc, char **argv) {
  SDL_Surface *screen;
  int i;

  if( argc == 1 ) {
    printf("Bitte mindestens eine BMP-Datei angeben!\n");
    return EXIT_FAILURE;
  }
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
  screen = SDL_SetVideoMode (640, 480, 16,
                             SDL_SWSURFACE|SDL_RESIZABLE);
  if (screen == NULL) {
    printf ("Videomodus konnte nicht eingerichtet werden: "
            " %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  /* Slideshow starten ...                                   */
  /* Zeigt alle BMP-Bilddateien an, die in der Kommandozeile */
  /* mitangegeben wurden                                     */
  for( i = 1; argv[i] != NULL; i++) {
    display_bmp(argv[i], screen, 0, 0 );
    SDL_Delay (4000);  
  }
  printf ("Erfolgreich beendet!\n");
  return EXIT_SUCCESS;
}
