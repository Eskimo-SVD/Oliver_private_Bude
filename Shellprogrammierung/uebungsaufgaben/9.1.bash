#!/bin/bash

if [ $# -lt 2 ]
then
	echo "Es müssen mindestens 2 Parameter angegeben werden"
	echo "usage: $0 quelle <quelle...> ziel"
	exit 1
fi

#Letzten Parameter als Ziel festlegen
ZIEL_NR=\$$#
ZIEL=$(eval echo $ZIEL_NR)
if [ ! -d "$ZIEL" -o ! -w "$ZIEL" ]
then
	echo "$ZIEL ist kein Verzeichnis oder Sie haben keine Rechte"
	exit 1
fi	
#Zaehler fuer die Schleife 
COUNTER_ENDE=$(($# - 1))
COUNTER=1
while [ $COUNTER -le $COUNTER_ENDE ]
do
	QUELLE_NR=\$$COUNTER
	QUELLE=$(eval echo $QUELLE_NR)
	VERZ=$(dirname $QUELLE)
	if [ ! -w $VERZ ]
	then
		echo "Ihnen fehlt das Recht die Quelldatei zu verschieben"
		COUNTER=$((COUNTER+1))
		continue
	fi
	if [ ! -e $QUELLE ]
	then
		echo "$QUELLE existiert nicht"
		COUNTER=$((COUNTER+1))
		continue
	fi	
	echo "Verschiebe $QUELLE nach $ZIEL"
	mv $QUELLE $ZIEL
	COUNTER=$((COUNTER+1))
done


