/* cpy_file.c */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCKSIZE 64 // bytes

ssize_t write2(int fd, const void *buffer, size_t count) {
    size_t noch_zu_schreiben = count;
    while(noch_zu_schreiben > 0) {
        ssize_t geschrieben = write(fd, buffer, count);
        if(geschrieben == -1)
            return -1; // Ein Fehler bei bei write()
        else
            noch_zu_schreiben -= geschrieben;
    }
    return count;
}


int main(int argc, char **argv) {
  // Zugriffsrechte für die neue Datei: -rw-rw-r--
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  char buffer[BLOCKSIZE];
  int fd_r, fd_w; // Filedeskriptoren
  int n;

  // Alle Zugriffsrechte der Einschränkungsmaske erlauben
  umask(0);

  if(argc < 3) {
      fprintf(stderr, "> %s quelldatei zieldatei\n", *argv);
      return EXIT_FAILURE;
  }

  fd_r = open(argv[1], O_RDONLY);
  fd_w = open(argv[2], O_WRONLY | O_EXCL | O_CREAT, mode);

  if(fd_r == -1 || fd_w == -1) {
      perror("Fehler bei open()");
      return EXIT_FAILURE;
  }
  while((n = read(fd_r, buffer, BLOCKSIZE)) > 0)
      if(write2(fd_w, buffer, n) < 0)
          perror("Fehler bei write()");
  return EXIT_SUCCESS;
}

