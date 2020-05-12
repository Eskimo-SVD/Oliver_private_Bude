/* sdl6.c */
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#define BALLS        5
#define MAX_SPEED1   6
#define MAX_SPEED2   10

typedef struct ball {
  int x, y;        /* Aktuelle Position */
  int dx, dy;      /* Bewegung für nächste Position */
}ball_t;

/* Array für die Bälle */
static ball_t balls1[BALLS];
static ball_t balls2[BALLS];

/* Verschieden Surface's */
static SDL_Surface *screen;
static SDL_Surface *ball;
static SDL_Surface *ball2;

/* Für Alpha-Blending von ball2 */
static int intensiv = 0;

/* Startwerte für die Bälle */
static void init_balls1 (void) {
  int i;
  for (i = 0; i < BALLS; i++) {
    balls1[i].x = rand () % screen->w;
    balls1[i].y = rand () % screen->h;
    balls1[i].dx = (rand () % (MAX_SPEED1 * 2)) - MAX_SPEED1;
    balls1[i].dy = (rand () % (MAX_SPEED1 * 2)) - MAX_SPEED1;

    balls2[i].x = rand () % screen->w;
    balls2[i].y = rand () % screen->h;
    balls2[i].dx = (rand () % (MAX_SPEED2 * 2)) - MAX_SPEED2;
    balls2[i].dy = (rand () % (MAX_SPEED2 * 2)) - MAX_SPEED2;
  }
}

/* Bewegt jeden Ball anhand des Bewegungsfeldes dx, dy */
static void move_balls1 (void) {
  int i;
  for (i = 0; i < BALLS; i++) {
    /* Ball um entsprechenden dy, dx Wert verschieben */
    balls1[i].x += balls1[i].dx;
    balls1[i].y += balls1[i].dy;
    /* Ball an der linken oder rechten Seite des */
    /* Bildschirms angekommen ...                */
    if (balls1[i].x < 0 || balls1[i].x > screen->w - 1)
      balls1[i].dx = -balls1[i].dx;
    /* Ball an der oberen oder unteren Seite des */
    /* Bildschirms angekommen ...                */
    if (balls1[i].y < 0 || balls1[i].y > screen->h - 1)
      balls1[i].dy = -balls1[i].dy;
    /* Das gleich Spiel nochmals mit der zweiten Sorte */
    /* von Bällen ...                                  */
    balls2[i].x += balls2[i].dx;
    balls2[i].y += balls2[i].dy;
    if (balls2[i].x < 0 || balls2[i].x > screen->w - 1)
      balls2[i].dx = -balls2[i].dx;
    if (balls2[i].y < 0 || balls2[i].y > screen->h - 1)
      balls2[i].dy = -balls2[i].dy;
  }
}

/* Jeden Ball einzelnen auf den (Haupt)-Surface zeichnen */
static void draw_balls1 (void) {
  int i;
  SDL_Rect src, src2, dest;
  for (i = 0; i < BALLS; i++) {
    /* Daten vom Ball - Quelle */
    src.x = 0;
    src.y = 0;
    src.w = ball->w;
    src.h = ball->h;
    /* Wohin den Ball kopieren - Ziele */
    dest.x = balls1[i].x - ball->w / 2;
    dest.y = balls1[i].y - ball->h / 2;
    dest.w = ball->w;
    dest.h = ball->h;
    /* Quelle nach Ziel kopieren */
    SDL_BlitSurface (ball, &src, screen, &dest);
    /* Daten von Ball - Quelle */
    src2.x = 0;
    src2.y = 0;
    src2.w = ball2->w;
    src2.h = ball2->h;
    /* Wohin den Ball kopieren - Ziele */
    dest.x = balls2[i].x - ball2->w / 2;
    dest.y = balls2[i].y - ball2->h / 2;
    dest.w = ball2->w;
    dest.h = ball2->h;
    /* Für Alpha-Blending-Effekt des Balls */
    if (intensiv < 255)
      intensiv++;
    else
      intensiv = 0;
    /* Alpha-Blending setzen */
    SDL_SetAlpha(ball2, SDL_SRCALPHA | SDL_RLEACCEL, intensiv);
    /* Quelle nach Ziel kopieren */
    SDL_BlitSurface (ball2, &src2, screen, &dest);
  }
}

int main (void) {
  SDL_Surface *temp, *temp2;
  SDL_Surface *background;
  SDL_Rect src, dest;
  int frames;

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
  temp = IMG_Load ("background.png");
  background = SDL_DisplayFormat (temp);
  if (background == NULL) {
    printf("Konnte Grafik nicht laden: %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  SDL_FreeSurface (temp);
  temp = IMG_Load ("ball1.png");
  if (temp == NULL) {
    printf ("Konnte Grafik nicht laden: %s\n",SDL_GetError ());
    return EXIT_FAILURE;
  }
  temp2 = IMG_Load ("ball2.png");
  if (temp2 == NULL) {
    printf ("Konnte Grafik nicht laden: %s\n",SDL_GetError ());
    return EXIT_FAILURE;
  }

  /* Farbenschlüssel für Transparenz der beiden Bälle setzen */
  SDL_SetColorKey (temp, SDL_SRCCOLORKEY | SDL_RLEACCEL,
                   (Uint16) SDL_MapRGB (temp->format, 0, 0, 0));
  SDL_SetColorKey (temp2,SDL_SRCCOLORKEY | SDL_RLEACCEL,
                   (Uint16) SDL_MapRGB (temp2->format, 0, 0, 0));
  /* Alpha-Blending setzen */
  SDL_SetAlpha (temp, SDL_SRCALPHA | SDL_RLEACCEL, 100);
  SDL_SetAlpha (temp2, SDL_SRCALPHA | SDL_RLEACCEL, 0);
  ball = SDL_DisplayFormat (temp);
  if (ball == NULL) {
    printf ("Konnte Grafik nicht konvertieren: %s\n",
       SDL_GetError ());
    return EXIT_FAILURE;
  }
  SDL_FreeSurface (temp);
  ball2 = SDL_DisplayFormat (temp2);
  if (ball2 == NULL) {
    printf ("Konnte Grafik nicht konvertieren: %s\n",
       SDL_GetError ());
    return EXIT_FAILURE;
  }
  SDL_FreeSurface (temp2);
  /* Einzelnen Bälle mit Werte initialisieren */
  init_balls1 ();
  for (frames = 0; frames < 1000; frames++) {
    /* Hintergrund zeichnen */
    src.x = 0;
    src.y = 0;
    src.w = background->w;
    src.h = background->h;
    dest = src;
    SDL_BlitSurface (background, &src, screen, &dest);
    /* Alle Bälle neu zeichnen */
    draw_balls1 ();
    /* doppelten Framebuffer tauschen */
    SDL_Flip (screen);
    /* nächste Postion für die Bälle holen */
    move_balls1 ();
    SDL_Delay(10); /* Verschnaufpause für die CPU */
  }
  /* Ressourcen wieder freigeben */
  SDL_FreeSurface (background);
  SDL_FreeSurface (ball);
  SDL_FreeSurface (ball2);
  return EXIT_SUCCESS;
}
