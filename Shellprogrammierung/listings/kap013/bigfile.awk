#!/usr/bin/awk -f
#
# Programmname: bigfile.awk

{
   my_ls="/bin/ls -ld '" quoting($0) "' 2>/dev/null"
   if( my_ls | getline ) {
      if( $5 > filesize ) {
         filename=$8
         filesize=$5
      }
   }
   close(my_ls)
}

END {
   if( filename )
     print "Größte Datei ist " filename " mit " filesize " Bytes"
   else
      print "Konnte keine größte Datei ermitteln?!?"
}

function quoting(s, n) {
   n=s
   gsub(/'/, "'\"'\"'", n)
   return n
}