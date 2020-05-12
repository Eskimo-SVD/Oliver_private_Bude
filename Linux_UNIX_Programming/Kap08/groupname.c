/* groupname.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>
#include <string.h>

int main(int argc, char *argv[]) {
   struct group *group_ptr;
   int i=0;

   if( argc != 2 ) {
      fprintf(stderr, "Usage: %s Name\n", argv[0]);
      exit (EXIT_FAILURE);
   }

   group_ptr=getgrnam(argv[1]);
   if(group_ptr == NULL) {
      printf("Konnte nichts �ber %s ermitteln\n", argv[1]);
      exit (EXIT_FAILURE);
   }

   printf("Folgendes wurde zu %s ermittelt: \n", argv[1]);
   printf("Gruppenname             : %s\n",
      group_ptr->gr_name);
   printf("Passwort (veschl�sselt) : %s\n",
      group_ptr->gr_passwd);
   printf("Gruppennummer           : %d\n",
      group_ptr->gr_gid);
   printf("Mitglieder dieser Gruppe : \n");
   while( group_ptr->gr_mem[i] != NULL )
      printf("\tName       : %s\n", group_ptr->gr_mem[i++]);

   return EXIT_SUCCESS;
}
