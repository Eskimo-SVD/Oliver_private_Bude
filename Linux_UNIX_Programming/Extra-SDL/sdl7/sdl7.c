/* sdl7.c */
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Wie viele Universen sind auf dem Bildschirm? */
#define UNIVERSES 50

struct universum {
  int x, y; /* Koordinaten des Universiums */
  int type; /* Welches Bild wird für die Universen verwendet? */
};

struct universum univ[UNIVERSES];
/* Verschieden Surface's */
static SDL_Surface *screen;
static SDL_Surface *left, *up, *right, *down, *background;
/* Farbwert schwarz */
static Uint32 black;
static int y_scrolling = 0, x_scrolling = 0;

static void RandBackground () {
  int i;
  int num_types;
  num_types = background->w / 16;
  for (i = 0; i < UNIVERSES; i++) {
    univ[i].x = rand () & 1023;
    univ[i].y = rand () & 511;
    univ[i].type = rand () % num_types;
  }
}

static void DrawBackground (int xn, int yn) {
  int i;
  for (i = 0; i < UNIVERSES; i++) {
    SDL_Rect src;
    SDL_Rect dest;
    src.x = univ[i].type * 16;
    src.y = 0;
    src.w = 16;
    src.h = 16;
    dest.x = (univ[i].x - xn) & 1023 - 16;
    dest.y = (univ[i].y - yn) & 511 - 16;
    SDL_BlitSurface (background, &src, screen, &dest);
  }
}

static void RS_Blit (SDL_Surface * bitmap, Sint16 x, Sint16 y) {
  SDL_Rect dest, src;
  dest.x = x;
  dest.y = y;
  dest.w = bitmap->w;
  dest.h = bitmap->h;
  src.x = 0;
  src.y = 0;
  src.w = bitmap->w;
  src.h = bitmap->h;
  SDL_BlitSurface (bitmap, &src, screen, &dest);
  SDL_UpdateRects (screen, 1, &dest);
}

static SDL_Surface *load_image (char *file) {
  static SDL_Surface *image, *temp;
  temp = IMG_Load (file);
  image = SDL_DisplayFormat (temp);
  if (image == NULL) {
    printf ("Konnte Grafik nicht laden: %s\n",SDL_GetError ());
    return NULL;
  }
  SDL_FreeSurface (temp);
  return (image);
}

static int eventloop (void) {
  SDL_Event event;
  while (SDL_PollEvent (&event) != 0) {
    switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
      if ((event.button.x > up->w)
            && (event.button.x < up->w * 2)
            && (event.button.y > 0)
            && (event.button.y < up->w)) {
        y_scrolling -= 12;
        printf ("Pfeil nach oben angeklickt ");
        printf ("[Button (%d) an Position (x:%d,y:%d)]\n",
           event.button.button, event.button.x, event.button.y);
      } 
      else if ((event.button.x > 0)
            && (event.button.x < left->w)
            && (event.button.y > left->h)
            && (event.button.y < left->h * 2)) {
        x_scrolling -= 12;
        printf ("Pfeil nach links angeklickt\n");
        printf ("[Button (%d) an Position (x:%d,y:%d)]\n",
           event.button.button, event.button.x, event.button.y);
      } 
      else if ((event.button.x > down->w)
            && (event.button.x < down->w * 2)
            && (event.button.y > down->h * 2)
            && (event.button.y < down->h * 3)) {
        y_scrolling += 12;
        printf ("Pfeil nach unten angeklickt\n");
        printf ("[Button (%d) an Position (x:%d,y:%d)]\n",
           event.button.button, event.button.x, event.button.y);
      } 
      else if ((event.button.x > right->w * 2)
            && (event.button.x < right->w * 3)
            && (event.button.y > right->h)
            && (event.button.y < right->h * 2)) {
        x_scrolling += 12;
        printf ("Pfeil nach rechts angeklickt\n");
        printf ("[Button (%d) an Position (x:%d,y:%d)]\n",
           event.button.button, event.button.x, event.button.y);
      } 
      else {
        printf ("Maus-Button (%d) gedrückt an Position "
            " (x:%d,y:%d)]\n",
            event.button.button, event.button.x, event.button.y);
      }
      break;
    case SDL_MOUSEMOTION:
      printf ("Mouse-Motion: ");
      printf ("Neue Position (x:%d,y:%d). ",
         event.motion.x, event.motion.y);
      printf ("Veränderung zur alten Pos. :(%i,%i)\n",
         event.motion.xrel, event.motion.yrel);
      break;
    case SDL_QUIT:
      printf ("Quit event. Bye.\n");
      exit (EXIT_SUCCESS);
    }
  }
  return 1;
}

int main (void) {
  int done = 1;

  if (SDL_Init (SDL_INIT_VIDEO) != 0) {
    printf ("Konnte SDL nicht initialisieren: %s\n",
       SDL_GetError ());
    return EXIT_FAILURE;
  }
  atexit (SDL_Quit);
  screen = SDL_SetVideoMode (640, 480, 16,
                             SDL_DOUBLEBUF | SDL_HWSURFACE);
  if (screen == NULL) {
    printf ("Kann Videomodus nicht setzen: %s\n",
       SDL_GetError ());
    return EXIT_FAILURE;
  }
  srand (time (0));

  up = load_image ("up.png");
  right = load_image ("right.png");
  down = load_image ("down.png");
  left = load_image ("left.png");
  background = load_image ("background1.png");
  RandBackground ();
  black = SDL_MapRGB (screen->format, 0, 0, 0);
  SDL_FillRect (screen, 0, black);
  DrawBackground (0, 0);

  RS_Blit (up, up->h, 0);
  RS_Blit (left, 0, left->w);
  RS_Blit (down, down->h, down->w * 2);
  RS_Blit (right, down->h * 2, left->w);
  SDL_UpdateRect (screen, 0, 0, 0, 0);
  while (done) {
    done = eventloop ();
    SDL_FillRect (screen, 0, black);
    DrawBackground (x_scrolling, y_scrolling);
    RS_Blit (up, up->h, 0);
    RS_Blit (left, 0, left->w);
    RS_Blit (down, down->h, down->w * 2);
    RS_Blit (right, down->h * 2, left->w);
    SDL_Flip (screen);
  }
  /* Ressourcen wieder freigeben */
  SDL_FreeSurface (up);
  SDL_FreeSurface (down);
  SDL_FreeSurface (right);
  SDL_FreeSurface (left);
  SDL_FreeSurface (background);
  SDL_FreeSurface (screen);
  return EXIT_SUCCESS;
}
