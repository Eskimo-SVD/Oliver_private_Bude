#!/bin/bash
# Script-Datei 
# /usr/local/shellscripts/bewaesserung/bewaesserung.sh

WDIR=/usr/local/shellscripts/bewaesserung
MOISTURE=$(cat /usr/local/shellscripts/moisturesensor/etc/moisture-vh400-1.text)

# zum Debugging
logger "Feuchtigkeit: $MOISTURE Prozent";

# Relaismodul/Magnetventil schalten
if [ $MOISTURE -ge 75 ]; then
  # Feuchtigkeit gleich oder über 75%, 
  # Magnetventil ausschalten
  logger "Ventil ausschalten"
  $WDIR/pin7-high.py
elif [ $MOISTURE -ge 65 ] && [ $MOISTURE -le 74 ]; then
  # Feuchtigkeit zw. 65 und 75%
  # nichts ändern
  logger "alles im gruenen Bereich" 
else
  # Feuchtigkeit unter 65 %
  # Magnetventil einschalten
  logger "Wasser marsch"
  $WDIR/pin7-low.py
fi

