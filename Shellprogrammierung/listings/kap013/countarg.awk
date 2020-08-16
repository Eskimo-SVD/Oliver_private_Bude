#!/usr/bin/awk -f
#
# Programmname: countarg.awk

BEGIN {
   print "Anzahl Argumente in ARGC : " , ARGC
   # einzelne Argumente durchlaufen
   for(i=0; i < ARGC; i++)
      printf "ARGV[%d] = %s\n", i, ARGV[i]
}