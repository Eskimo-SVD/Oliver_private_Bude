/* read_shadow.c */
/* Programm ben�tigt Superuser-Rechte  */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <shadow.h>
#include <string.h>
#include <time.h>

struct spwd *getshadow(const char *loginname) {
   struct spwd *shadow_ptr;

   while( shadow_ptr=getspent() ) {
      if( strcmp(shadow_ptr->sp_namp, loginname) == 0) {
         endspent();
         return shadow_ptr;
      }
   }
   endspent();
   return NULL;
}

int main(int argc, char *argv[]) {
   struct spwd *shadow_ptr;

   if( argc != 2 ) {
      fprintf(stderr, "Usage: %s Name\n", argv[0]);
      exit (EXIT_FAILURE);
   }

   shadow_ptr=getshadow(argv[1]);
   if(shadow_ptr == NULL) {
      printf("Konnte nichts �ber %s ermitteln\n", argv[1]);
      exit (EXIT_FAILURE);
   }

   printf("Folgendes wurde zu %s ermittelt: \n", argv[1]);
   printf("Benutzername              : %s\n",
      shadow_ptr->sp_namp);
   printf("Passwort (veschl�sselt)   : %s\n", 
      shadow_ptr->sp_pwdp);
   printf("Tag der letzten �nderung  : %li Tage\n",
      shadow_ptr->sp_lstchg);
   printf("N�chste �nderung m�glich  : %li Tage\n", 
      shadow_ptr->sp_min);
   printf("N�chste �nderung f�llig   : %li Tage\n", 
      shadow_ptr->sp_max);
   printf("Warnung, wenn Passw�rt f�llig %li Tage zuvor!\n", 
      shadow_ptr->sp_warn);
   printf("Konto nach %li Tage Ablauf der Frist sperren!\n", 
      shadow_ptr->sp_inact);

   return EXIT_SUCCESS;
}
