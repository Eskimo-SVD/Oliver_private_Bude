/* mein_C.c */
#include "mysyntax.h"

START
 BLOCKANFANG
     GANZZAHL zahl;
     SCHREIB "Hallo Welt" END
     NEUEZEILE
     SCHREIB "Zahleingabe: " END
     EINGABE "%d", &zahl END
     SCHREIB "Die Zahl war %d", zahl END
     NEUEZEILE
   ENDESTART
 BLOCKENDE

