#!/usr/bin/awk -f
#
# Programmname: winner.awk

{
   for(i=4; i<=NF; i++)
      string[$2]= string[$2] $i "-"
}

END {
   for(word in string)
      print "Titel von " word " in den Jahren : " string[word]
}