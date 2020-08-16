#!/bin/bash

#Abfangen fehlerhafter Anzahl an Argumenten
if [ $# -ne 2 ]
then
	echo "Fehler beim Aufruf es müssen genau 2 Argumente"
	echo "übergeben werden. Ihr Vor- und Nachname."
	exit 1
fi

#Umwandeln des Vornamens in Grossbuchstaben
VORNAME=`echo $1 | tr '[a-z]' '[A-Z]'`

#Ausgabe
echo "Hallo $VORNAME $2 es ist $(date +%H:%M) Uhr"
exit 0

