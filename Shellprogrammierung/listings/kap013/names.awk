#!/usr/bin/awk -f
#
# Programmname: names.awk


{
   string = string $2 " "  
}

END {
   print string
}