#!/usr/bin/awk -f
#
# Programmname: timestamp.awk

BEGIN {
    now = systime()
    # macht eine Ausgabe ala date
    timestamp = strftime("%a %b %d %H:%M:%S %Z %Y", now)
}

{
   print
}

END {
   print timestamp
}