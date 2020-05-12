/* sdl1.c */
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void) {
   SDL_Surface *screen;
   /* SDLs Video-System initialisieren und auf */ 
   /* Fehler überprüfen                        */
   if (SDL_Init ( SDL_INIT_VIDEO ) != 0) {
      printf ("Konnte SDL nicht initialisieren: %s\n",
         SDL_GetError ());
      return EXIT_FAILURE;
   }
   /* Wenn die Anwendung beendet wird,          */
   /* wird die Funktion SDL_Quit() ausgeführt   */
   atexit (SDL_Quit);
   /* Videomodus mit 640x480 Pixeln, Hi-Color (16Bit)    */
   /* einrichten. Oberfläche (Surface) Standardmäßig in  */
   /* den Hauptspeicher (SDL_SWSURFACE) legen            */
   screen = SDL_SetVideoMode (640, 480, 16, SDL_SWSURFACE);
   if (screen == NULL) {
      printf ("Videomodus konnte nicht eingerichtet werden: "
              " %s\n", SDL_GetError ());
      return EXIT_FAILURE;
   }
   /* 4000 ms warten ... */
   SDL_Delay (4000);  
   printf ("Erfolgreich beendet!\n");
   return EXIT_SUCCESS;
}

