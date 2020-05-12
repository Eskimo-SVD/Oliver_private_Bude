/* eventloop2.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#ifndef _POSIX_PRIORITY_SCHEDULING
   #error "sched_yield() ist hier nicht vorhanden"
#endif

static int event_loop( void ) {
   int ereignis = 0;
   /* Eine Ereignisschleife */
   if( ereignis )
      return 1;
   else
      return 0;
}

int main() {
  int loop = 0;
  while( !loop ) {
     loop = event_loop();
     sched_yield();
  }
  return EXIT_SUCCESS;
}
