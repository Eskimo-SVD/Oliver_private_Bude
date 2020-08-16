#!/usr/bin/awk -f
#
# Programmname: countwords.awk

{
   # Durchläuft alle Felder einer Zeile
   for(f=1; f <= NF; ++f)
     field[$f]++
}

END {
   for(word in field)
      print word, field[word]
}