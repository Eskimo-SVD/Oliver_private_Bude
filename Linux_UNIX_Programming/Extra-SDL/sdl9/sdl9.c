/* sdl9.c */
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

static SDL_Joystick *js;

static void Joystick_Info (void) {
  int num_js, i;
  num_js = SDL_NumJoysticks ();
  printf ("Es wurde(n) %d Joystick(s) auf dem System gefunden\n",
     num_js);
  if (num_js == 0) {
    printf ("Es wurde kein Joystick gefunden\n");
    return;
  }
  /* Informationen zum Joystick */
  for (i = 0; i < num_js; i++) {
    js = SDL_JoystickOpen (i);
    if (js == NULL) {
      printf ("Kann Joystick %d nicht öffnen\n", i);
    } 
    else {
      printf ("Joystick %d\n", i);
      printf ("\tName:       %s\n", SDL_JoystickName(i));
      printf ("\tAxen:       %i\n", SDL_JoystickNumAxes(js));
      printf ("\tTrackballs: %i\n", SDL_JoystickNumBalls(js));
      printf ("\tButtons:   %i\n",SDL_JoystickNumButtons(js));
      SDL_JoystickClose (js);
    }
  }
}

static int eventloop_joystick (void) {
  SDL_Event event;
  while (SDL_PollEvent (&event)) {
    switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        printf ("ESCAPE für Ende betätigt\n");
        return 0;
      }
      break;
    case SDL_JOYAXISMOTION:
      printf ("Joystick %d, Achse %d bewegt nach %d\n",
         event.jaxis.which, event.jaxis.axis, event.jaxis.value);
      break;
    case SDL_JOYBUTTONUP:
    case SDL_JOYBUTTONDOWN:
      printf ("Joystick %i Button %i: %i\n",
         event.jbutton.which, event.jbutton.button,
         event.jbutton.state);
      break;
    case SDL_QUIT:
      return 0;
    }
  }
  return 1;
}

int main (void) {
  int done = 1;
  if (SDL_Init (SDL_INIT_JOYSTICK | SDL_INIT_VIDEO) != 0) {
    printf ("Fehler: %s\n", SDL_GetError ());
    return 1;
  }
  atexit (SDL_Quit);
  if (SDL_SetVideoMode (256, 256, 16, 0) == NULL) {
    printf ("Fehler: %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  Joystick_Info ();
  js = SDL_JoystickOpen (0);
  if (js == NULL) {
    printf("Konnte Joystick nicht öffnen:%s\n",SDL_GetError());
  }
  while( done ) {
    done = eventloop_joystick ();
    SDL_Delay(10);
  }
  SDL_JoystickClose (js);
  return EXIT_SUCCESS;
}
