/* write_vec.c */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 3 // Anzahl der Elemente

int main(int argc, char **argv) {
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  const char *str[] = {"Ein Teststring\n", "Noch einer\n",
    "Der letzte im Bunde\n"};
  struct iovec vec[MAX];
  ssize_t length = 0;
  int fd, i;

  //unlink("test");
  umask(0);
  fd = open("test", O_WRONLY | O_CREAT | O_EXCL, mode);
  if(fd == -1) {
      perror("open()");
      return EXIT_FAILURE;
  }
  // Einzelne Daten in die Struktur legen
  for(i = 0; i < MAX; ++i) {
      vec[i].iov_base = (void *)str[i];
      vec[i].iov_len  = strlen(str[i]);
      length += strlen(str[i]);
  }
  // Jetzt in die Datei schreiben
  if(writev(fd, vec, MAX) != length) {
      perror("writev()");
      return EXIT_FAILURE;
  }
  close(fd);
  return EXIT_SUCCESS;
}
