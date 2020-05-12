/* sdl10.c */
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SOUNDS 5

struct sample {
  Uint8 *daten;
  Uint32 pos;
  Uint32 len;
} sounds[SOUNDS];

static void
AudioMixing (void *nichtVerwendet, Uint8 * stream, int laenge) {
  unsigned int i;
  Uint32 menge;
  for (i = 0; i < SOUNDS; ++i) {
    menge = (sounds[i].len - sounds[i].pos);
    if (menge > laenge) {
      menge = laenge;
    }
    SDL_MixAudio(stream, &sounds[i].daten[sounds[i].pos],
       menge, SDL_MIX_MAXVOLUME);
    sounds[i].pos += menge;
  }
}

static void
AudioPlay (const char *datei) {
  int index;
  SDL_AudioSpec wave;
  Uint8 *daten;
  Uint32 len;
  SDL_AudioCVT cvt;
  /* einen leeren Audio-Slot suchen */
  for (index = 0; index < SOUNDS; ++index) {
    if (sounds[index].pos == sounds[index].len) {
      break;
    }
  }
  if (index == SOUNDS)
    return;
  /* Audio-Datei laden und nach 16 Bit und 22KHz wandeln */
  if (SDL_LoadWAV (datei, &wave, &daten, &len) == NULL) {
    fprintf (stderr, "Konnte '%s' nicht laden: %s\n",
       datei, SDL_GetError ());
    return;
  }
  SDL_BuildAudioCVT ( &cvt, wave.format, wave.channels,
                      wave.freq, AUDIO_S16, 2, 22050 );
  cvt.buf = malloc (len * cvt.len_mult);
  memcpy (cvt.buf, daten, len);
  cvt.len = len;
  SDL_ConvertAudio (&cvt);
  SDL_FreeWAV (daten);
  /* die Audiodaten in den Slot schreiben */
  /* (Abspielen startet sofort)           */
  if (sounds[index].daten) {
    free (sounds[index].daten);
  }
  SDL_LockAudio ();
  sounds[index].daten = cvt.buf;
  sounds[index].len = cvt.len_cvt;
  sounds[index].pos = 0;
  SDL_UnlockAudio ();
}

static int eventloop (void) {
  SDL_Event event;
  while (SDL_WaitEvent (&event)) {
    SDL_keysym keysym;
    switch (event.type) {
    case SDL_KEYDOWN:
      keysym = event.key.keysym;
      if (keysym.sym == SDLK_ESCAPE) {
        printf ("ESCAPE gedrückt.\n");
        return EXIT_SUCCESS;
      }
      if (keysym.sym == SDLK_a) {
        printf ("Alarm\n");
        AudioPlay ("alarm.wav");
      }
      if (keysym.sym == SDLK_c) {
        printf ("Cry in the hall\n");
        AudioPlay ("cry 2.wav");
      }
      if (keysym.sym == SDLK_b) {
        printf ("Blood\n");
        AudioPlay ("bloodflo.wav");
      }
      if (keysym.sym == SDLK_m) {
        printf ("Like a cat?\n");
        AudioPlay ("meeeow.wav");
      }
      if (keysym.sym == SDLK_z) {
        printf ("Are you angry?\n");
        AudioPlay ("zorn.wav");
      }
      break;
    case SDL_QUIT:
      printf ("Quit event. Bye.\n");
      return EXIT_SUCCESS;
    }
  }
  return 1;
}

int main (void) {
  SDL_Surface *screen;
  int done = 1;
  SDL_AudioSpec format;

  if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    printf ("Unable to initialize SDL: %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  atexit (SDL_Quit);
  atexit (SDL_CloseAudio);
  screen = SDL_SetVideoMode (256, 256, 16, 0);
  if (screen == NULL) {
    printf ("Unable to set video mode: %s\n", SDL_GetError ());
    return EXIT_FAILURE;
  }
  /* Format: 16 Bit, stereo, 22 KHz */
  format.freq = 22050;
  format.format = AUDIO_S16;
  format.channels = 2;
  format.samples = 512;
  format.callback = AudioMixing;
  format.userdata = NULL;
  /* das Audio-Gerät öffnen und das Abspielen beginnen */
  if (SDL_OpenAudio (&format, NULL) < 0) {
    printf ("Audio-Gerät konnte nicht geöffnet werden: %s\n",
       SDL_GetError ());
    exit (EXIT_FAILURE);
  }
  SDL_PauseAudio (0);
  while (done) {
    printf ("ESC für Ende\n  A, C, Z, M und B für Sound "
            " abspielen.\n");
    done = eventloop ();
  }
  SDL_PauseAudio (1);
  SDL_CloseAudio();
  return EXIT_SUCCESS;
}
