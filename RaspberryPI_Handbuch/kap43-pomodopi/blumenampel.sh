#!/bin/bash
WDIR=/usr/local/shellscripts/ampel
MOISTURE=$(cat /usr/local/shellscripts/moisturesensor/etc/moisture-vh400-1.text)

# zum Debugging
logger "Feuchtigkeit: $MOISTURE Prozent";

# Ampel schalten
if [ $MOISTURE -ge 65 ]; then
  # Ampel auf Gruen schalten
  clewarecontrol -d 901846 -as 2 1
  # Rot und Gelb ausschalten
  clewarecontrol -d 901846 -as 0 0
  clewarecontrol -d 901846 -as 1 0
elif [ $MOISTURE -ge 55 ] && [ $MOISTURE -le 64 ]; then
  # Ampel auf Gelb schalten
  clewarecontrol -d 901846 -as 1 1
  # Rot und Gruen ausschalten
  clewarecontrol -d 901846 -as 0 0
  clewarecontrol -d 901846 -as 2 0
else
  # Ampel auf Rot schalten
  clewarecontrol -d 901846 -as 0 1
  # Gelb und Gruen ausschalten
  clewarecontrol -d 901846 -as 1 0
  clewarecontrol -d 901846 -as 2 0
fi

