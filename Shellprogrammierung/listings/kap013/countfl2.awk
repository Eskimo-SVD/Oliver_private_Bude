#!/usr/bin/awk -f
#
# Programmname: countfl2.awk

{
   do {
      fields++
      i++
   } while (i<=NF)
   i=0
   lines++
}

END {
   print "Anzahl Felder in " FILENAME ": " fields
   print "Anzahl Zeilen in " FILENAME ": " lines
}