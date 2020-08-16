#!/usr/bin/awk -f
#
# Programmname: countfields.awk

{
   field[FILENAME]+=NF
}

END {
   for(word in field)
      print "Anzahl Felder in " word " : " field[word]
}