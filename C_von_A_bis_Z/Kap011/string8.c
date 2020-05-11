/* string8.c */
#include <stdio.h>
#include <stdlib.h>

/*Passwort*/
const char p[]=  { "123xyz456" };

int check_passwort(char passw[]) {
   int i, n = sizeof(p) / sizeof(char);

   for(i=0; i < n; i++)
      if(passw[i] != p[i])
         return 0; /* Falsches Passwort */
   return 1;   /* Richtiges Passwort */
}

int main(void) {
   char Name[20], passwort[10];

   printf("Login-Name : ");
   fgets(Name, 20, stdin);
   printf("Passwort   : ");
   fgets(passwort, 10, stdin);

   if( check_passwort(passwort) == 1)
      printf("Willkommen im System %s\n",Name);
   else
      printf("Falsches Passwort! Systemzugriff verweigert.\n");
   return EXIT_SUCCESS;
}

