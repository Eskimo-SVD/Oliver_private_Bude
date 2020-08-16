#!/bin/bash

declare -a ADR_ARRAY

ADR=`	zenity --forms --title="Eine neue Adresse einlesen" \
		--text="Geben Sie die Informationen ein" \
		--separator=";" \
		--add-entry="Vorname" \
		--add-entry="Nachname" \
		--add-entry="Straße" \
		--add-entry="Hausnummer" \
		--add-entry="Postleitzahl" \
		--add-entry="Ort" \
		--add-entry="Email" \
		--add-calendar="Geburtstag"` 

for ((z=1; z<=8; z++))
do
	ADR_ARRAY[$z]=`echo $ADR | cut -d\; -f$z`
done
zenity --list --width=1000 --height=400\
	--title="Die neue Adresse" \
	--column="Vorname" --column="Nachname" \
	--column="Straße" --column="Hausnummer" \
	--column="Postleitzahl" --column="Ort" \
	--column="Email" --column="Geburtstag" \
	${ADR_ARRAY[1]} ${ADR_ARRAY[2]} ${ADR_ARRAY[3]} ${ADR_ARRAY[3]} \
	${ADR_ARRAY[5]} ${ADR_ARRAY[6]} ${ADR_ARRAY[7]} ${ADR_ARRAY[8]}
	


