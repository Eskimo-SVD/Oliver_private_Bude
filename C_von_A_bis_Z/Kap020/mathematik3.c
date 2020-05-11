/* mathematik3.c */
#include <stdio.h>
#include <stdlib.h>
/* Bei Linux den Compilerflag -lm mit angeben */
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON

int main(void) {
   double d1=0, d2=1.0, dges;
   fexcept_t flagp;
   // Exception-Statusflags sichern
   fegetexceptflag(&flagp, FE_ALL_EXCEPT );
   // Mit Absicht ein Division durch 0 auslösen
   dges = d2 / d1;
   if( fetestexcept( FE_DIVBYZERO ) ) {
      printf("Exception ausgelöst: Divsion durch 0 !\n");
   } 
   // Exception-Statusflags wiederherstellen
   fesetexceptflag(&flagp, FE_ALL_EXCEPT);
   // Sollte jetzt nicht mehr ausgeführt werden
   if( fetestexcept( FE_DIVBYZERO ) ) {
      printf("Exception ausgelöst: Divsion durch 0 !\n");
   }
   return EXIT_SUCCESS;
}

