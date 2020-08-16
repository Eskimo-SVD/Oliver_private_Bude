#!/usr/bin/awk -f
#
# Programmname: FILEprint.awk

{
  FILEprint($0)
}

function FILEprint( line ) {
   if(length(line) == 0)
      return "Leerer String"
   else
      print FILENAME "(" NR ") : " line

}