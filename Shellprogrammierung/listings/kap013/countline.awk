#!/usr/bin/awk -f
#
# Programmname: countline.awk

BEGIN {
   count=0
}

# Haupt-Aktionsteil
{ 
  count++
}

END {
   printf "Anzahl Zeilen : %d\n", count
}