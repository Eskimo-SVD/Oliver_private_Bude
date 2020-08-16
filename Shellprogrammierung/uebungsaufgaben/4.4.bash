#! /bin/bash

#Stunde in Variable lesen

STUNDE=$(date +%H)

#Auswerten der Stunden
case "$STUNDE" in
  06|07|08|09|10|11|12)    echo "Guten Morgen";;
  1[3-8])                  echo "Guten Tag";;
  19|20|21|22)             echo "Guten Abend";;
  23|01|02|03|04|05)       echo "Gute Nacht";;
esac

