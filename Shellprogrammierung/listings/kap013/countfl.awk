#!/usr/bin/awk -f
#
# Programmname: countfl.awk

{
   while( i <=NF  ) {
      fields++
      i++
   }
   i=0
   lines++
}

END {
   print "Anzahl Felder in " FILENAME ": " fields
   print "Anzahl Zeilen in " FILENAME ": " lines
}