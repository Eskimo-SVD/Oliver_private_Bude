/* mysql1.c */
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
   MYSQL  *my;
   /* Handle initialisieren */
   my = mysql_init(NULL);
   if(my == NULL) {
      fprintf(stderr, " Initialisierung fehlgeschlagen\n");
      return EXIT_SUCCESS;
   }
   /* Mit dem Server verbinden */ 
   if( mysql_real_connect (
        my,   /* Zeiger auf MYSQL-Handler*/
        NULL, /* Host-Name*/
        NULL, /* User-Name*/
        NULL, /* Passwort für user_name */
        NULL,  /* Name der Datenbank*/
        0,     /* Port (default=0) */
        NULL,  /* Socket (default=NULL)*/
        0      /* keine Flags */  )  == NULL) {
      fprintf (stderr, "Fehler mysql_real_connect():"
        "%u (%s)\n",mysql_errno (my), mysql_error (my));
   } 
   else
      printf("Erfolgreich mit dem MySQL-Server verbunden\n");

   /* Hier befindet sich der Code für die Arbeit mit MySQL */

   /* Verbindung trennen */
   mysql_close (my);
   return EXIT_SUCCESS;
}

