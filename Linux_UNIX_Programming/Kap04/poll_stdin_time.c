/* poll_stdin_time.c */
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

static int poll_stdin_time(int sekunden) {
  struct timeval timeout;
  fd_set read_fds;

  FD_ZERO(&read_fds);
  FD_SET(STDIN_FILENO, &read_fds);
  timeout.tv_sec = sekunden;
  timeout.tv_usec = 0;
  return select(STDIN_FILENO + 1, &read_fds, NULL,
   NULL, &timeout);
}

/* oder im C99-Standard:
static int poll_stdin_time(int sekunden) {
  struct timeval timeout = {.tv_sec = sekunden, .tv_usec = 0};
  fd_set read_fds;

  FD_ZERO(&read_fds);
  FD_SET(STDIN_FILENO, &read_fds);
  return select(STDIN_FILENO + 1, &read_fds, NULL,
   NULL, &timeout);
}
*/

int main(void) {
    int ret;
    printf("Warte 5 Sek. auf Eingabe (ENTER-Taste)!\n");
    ret = poll_stdin_time(5);
    if(ret == 0)
       printf("Zeit abgelaufen\n");
    else if(ret == 1)
       printf("Danke!!!\n");
    else
       perror("select()");
    return 0;
}
