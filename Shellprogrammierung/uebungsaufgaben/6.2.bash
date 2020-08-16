#!/bin/bash

DATEIEN=($@)
ANZAHL=0
rechte(){
local COUNTER=0
while [ $COUNTER -lt $# ]
do
	if [ ! -e ${DATEIEN[$COUNTER]} ]
	then
		RECHTE[$COUNTER]="KEINE DATEI"
		COUNTER=$((COUNTER+1))
		continue
	fi	
	RECHTE[COUNTER]=$(ls -l ${DATEIEN[$COUNTER]} | cut -c2-10)
	COUNTER=$((COUNTER+1))
done
}

rechte $DATEIEN[$@]
printf "%-50s %-15s\n"  "Dateiname" "Rechte"
echo""
while [ $ANZAHL -lt $# ]
do
	printf "%-50s %-15s\n" "${DATEIEN[$ANZAHL]}" "${RECHTE[$ANZAHL]}"
	ANZAHL=$((ANZAHL+1))
done

