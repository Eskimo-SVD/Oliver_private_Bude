/* memory.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static long get_mem_total (void) {
   FILE *fp;
   char buffer[1024];
   size_t bytes_read;
   char *match;
   long mem_tot;

   if((fp = fopen("/proc/meminfo", "r")) == NULL) {
      perror("fopen()");
      exit(EXIT_FAILURE);
   }
   bytes_read = fread (buffer, 1, sizeof (buffer), fp);
   fclose (fp);
   if (bytes_read == 0 || bytes_read == sizeof (buffer))
      return 0;
   buffer[bytes_read] = '\0';
   /* Suchen nach der Stringfolge "Memtotal" */
   match = strstr (buffer, "MemTotal");
   if (match == NULL) /* Nicht gefunden */
      return 0;
   sscanf (match, "MemTotal: %ld", &mem_tot);
   return (mem_tot/1024); /* 1MB = 1024KB */
}

int main (void) {
  long memory = get_mem_total();
  if(memory == 0)
     printf("Konnte RAM nicht ermitteln\n");
  else
     printf("Vorhandener Arbeitsspeicher: %ldMB\n" ,memory);
  return EXIT_SUCCESS;
}
