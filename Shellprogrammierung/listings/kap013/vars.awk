#!/usr/bin/awk -f
#
# Programmname: vars.awk

BEGIN {
   count=0
   # Ausgabetrennzeichen: Minuszeichen
   OFS="-"
}

/USA/ {
 print $1, $2, $3
 count++ 
}

END {
   printf "%d Ergebnisse (von %d Zeilen) gefunden in %s\n",
      count, NR, FILENAME
   printf "Datei %s befindet sich in %s\n", 
      FILENAME, ENVIRON["PWD"]
}