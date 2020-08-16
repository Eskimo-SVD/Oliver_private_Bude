#!/usr/bin/awk -f
#
# Programmname: winner80er.awk

{
   for(i=4; i<=NF; i++) {
      if( $i >= 1980 && $i < 1990 ) {
         print $0
         # gefunden -> Abbruchbedingung für for
         i=NF;
      }
   }
}