#!/usr/bin/awk -f
#
# Programmname: names2.awk

BEGIN {
   i=2
}

{
   string = string $i " "  
}

END {
   print string
}