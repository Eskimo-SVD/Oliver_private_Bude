#!/usr/bin/awk -f
#
# Programmname: search.awk

BEGIN {
   # Suchstring eingeben 
   print "Wonach suchen Sie : "
   getline searchstring
   # Datei zum Suchen eingeben
   print "In welcher Datei  : "
   getline file
   # Zeilenweise aus der Datei lesen
   while( getline < file ) {
      if($0 ~ searchstring) {
         print
      }
   }   
   close(file)
}