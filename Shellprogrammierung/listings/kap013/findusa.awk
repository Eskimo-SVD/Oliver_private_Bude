#!/usr/bin/awk -f
#
# Programmname: findusa.awk

{
   if( $0 ~ /USA/ )
      print "USA gefunden in Zeile " NR
   else
      print "USA nicht gefunden in Zeile "   NR
}