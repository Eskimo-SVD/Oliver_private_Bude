/* mysql2.c */
#include <stdio.h>
#include <stdlib.h>
#if defined __WIN32__ || _MSC_VER
   #include "my_global.h"
   #include "mysql.h"
   //#pragma comment(lib,"libmysql.lib")
#else
   #include <mysql.h>   
#endif

int main (int argc, char **argv) {
   int i;
   char *groups[] = {
      "client", "WinMySQLadmin", NULL 
   };

   my_init ();
   printf ("Ursprüngliche Argumente:\n");
   for (i = 0; i < argc; i++)
      printf ("argv[%d] : %s\n", i, argv[i]);

   load_defaults ("my", (const char **)groups, &argc, &argv);

   printf ("Angepasste Argumente nach load_default():\n");
   for (i = 0; i < argc; i++)
      printf ("argv[%d] : %s\n", i, argv[i]);
   return EXIT_SUCCESS;
}

