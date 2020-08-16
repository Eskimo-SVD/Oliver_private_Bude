#!/bin/bash

#Beispiel für yad

ADDR_ARRAY=($(yad \
--item-separator=";" \
--separator="\\n" \
--form \
--field="Eine Adresse eingeben:LBL" \
--field="Vorname:CBE" NA \
--field="Nachname:CBE" NA \
--field="Straße:CBE" NA \
--field="Hausnummer:NUM"  \
--field="Postleitzahl:CBE" \
--field="Ort:CBE" NA \
--field="Geburtstag:DT" \
--field="In einer Datei speichern?:CHK"))

LANG_ARRAY=`echo ${#ADDR_ARRAY[*]}`
SAVE=$((LANG_ARRAY-1))

if [ ${ADDR_ARRAY[SAVE]} = "TRUE" ]
then
	while [ `echo ${#FILE_ARRAY[*]}` -ne 1 ]
	do
		FILE_ARRAY=($(yad \
		--item-separator=";" \
		--separator="\\n" \
		--form \
		--field="Eine Datei wählen:LBL" \
		--field="Erstellen Sie eine neue Datei:SFL" \
		--field="Oder eine bestehende Datei auswählen:LBL" \
		--field="Wählen Sie eine Datei zum speichern:FL" ))

		if [ `echo ${#FILE_ARRAY[*]}` -ne 1 ] 
		then
			yad --text "Bitte genau eine Auswahl treffen" \
			--button="Weiter":1 \
			--button="Abbruch":0
			JN=$?
			if [ "$JN" -eq 0 ]
			then
				yad --text="Aufwiedersehen" \
				--button=gtk-ok:1
				exit
			else
				yad --text="Dann noch mal" \
				--button=gtk-ok:0
				continue
			fi
		fi	
	done	
fi
echo "Datei = ${FILE_ARRAY[0]} "
if [ ! -r ${FILE_ARRAY[0]} ]
then
	yad --text="Sie haben kein Schreibrecht an der Datei" \
 		--button=gtk-ok:1
	exit
fi

COUNT=$((LANG_ARRAY - 1))
exec 3>> ${FILE_ARRAY[0]}
for (( i=0 ; i < $COUNT ; i++ ))
do
	echo -n "${ADDR_ARRAY[$i]};" >&3
done
echo " " >&3
exec 3>&-

