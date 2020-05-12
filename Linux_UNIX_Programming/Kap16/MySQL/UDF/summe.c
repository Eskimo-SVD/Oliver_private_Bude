/* summe.c */
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>

long long
summe( UDF_INIT * initid, UDF_ARGS * args, char *is_null,
       char *error ) {
  long long summe=0;
  unsigned int i;
  for(i = 0; i<args->arg_count; i++)
    summe += *((long long *) args->args[i]);
  return summe;
}

my_bool
summe_init (UDF_INIT * initid, UDF_ARGS * args, char *message) {
  unsigned int i;
  if (args->arg_count < 1) {
    strncpy (message,
             "SUMME(): Mindestens 1 Argument angeben!",
             MYSQL_ERRMSG_SIZE);
    return 1;
  }
  for (i = 0; i < args->arg_count; i++)
    if (args->arg_type[i] != INT_RESULT) {
      strncpy (message,
               "SUMME(): Nur eine Ganzzahl als Argumente!",
               MYSQL_ERRMSG_SIZE);
      return 1;
    }
  initid->maybe_null = 0;
  return 0;
}
