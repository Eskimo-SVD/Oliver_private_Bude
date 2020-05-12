/* eventloop1.c */
#include <stdio.h>
#include <stdlib.h>

static int event_loop( void ) {
   int ereignis = 0;
   /* Eine Ereignisschleife */
   if( ereignis )
      return 1;
   else
      return 0;
}

int main(void) {
  int loop = 0;
  while( !loop )
     loop = event_loop();
  return EXIT_SUCCESS;
}
