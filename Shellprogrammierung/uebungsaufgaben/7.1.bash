#!/bin/bash

signal_INT() # Wenn strg+c gedrückt wird
{
	local ENDE=""
	local NEUDAT=""
	while [ "$ENDE" != "J" -o "$ENDE" != "N" ]
	do
		echo "Wollen Sie das Programm vorzeitig beenden? (j/n) : "
		read ENDE
		ENDE=$(echo $ENDE | tr 'a-z' 'A-Z')
		if [ "$ENDE" = "J" ]
		then
			while [ -z "$NEUDAT" ]
			do
				read -p "Name der neuen Datei eingeben : " NEUDAT
				cp $1 $NEUDAT
			done	
			cat $1
			rm $1
			exit 0
		else
			return 0
		fi	
	done	
}
# Temporaere Datei unter OS-X erstellen
#OSX_PFAD=$(basename $0)
#ATEI=$(mktemp -t $OSX_PFAD)
# Temporaere Datei unter Linux erstellen
DATEI=$(mktmp)
trap 'echo Das Skript kann nicht angehalten werden!' SIGTSTP
trap 'signal_INT $DATEI ' 2
while true
do
	NAME=""
	TEL=""
	while [ -z "$NAME" -o -z "$TEL" ]
	do
		read -p "Name und Telefonnummer eingeben : " NAME TEL
		if [ -z "$NAME" ]
		then
			echo  "Kein Name eingegeben"
			continue
		fi
		if [ -z "$TEL" ]
		then
			echo  "Keine Telefonnummer eingegeben!"
			continue
		fi	
	done	
	echo "$NAME $TEL" >>$DATEI
done

