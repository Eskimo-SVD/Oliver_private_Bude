/* isfile.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define ESUCCESS 0 

int main(void) {
   FILE *fp;

   fp = fopen("testfile", "r");
   if(errno == ENOENT) {
      /* errno wieder zurücksetzen */
      errno = ESUCCESS;
      fp = fopen ("testfile", "w");
      if(NULL == fp) {
         perror(NULL);
         return EXIT_FAILURE;
      }  
      else
         printf("Datei \"testfile\" angelegt\n");
   }
   else
      printf("Datei \"testfile\" exisitiert bereits\n");
   fclose(fp);
   return EXIT_SUCCESS;
}

