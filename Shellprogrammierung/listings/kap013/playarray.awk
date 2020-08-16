#!/usr/bin/awk -f
#
# Programmname: playarray.awk

{
   # komplette Zeile in das Array mit dem Index NR ablegen
   line[NR]=$0
   # Anzahl der Felder (Wörter) in das Array 
   # fields mit dem Index NR ablegen
   fields[NR]=NF
}

END {
   for(i=1; i <=NR; i++) {
      printf "Zeile %2d hat %2d Felder:\n", i, fields[i]
      print line[i]
   }
}