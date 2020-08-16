#!/usr/bin/awk -f
#
# Programmname: splitting.awk

/Coleman/ {
   # Durchläuft alle Felder einer Zeile
   split($0, field)
}

END {
   for(word in field)
      print field[word]
}