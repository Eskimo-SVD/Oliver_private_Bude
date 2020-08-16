#!/bin/bash

clear
echo "### Kopieren einer Datei ###"
echo ""
while [ -z "$QUELLE" ]
do
	echo -n "Geben Sie die Quelle an : "
	read QUELLE
done

if [ -e "$QUELLE" ]
then
	if [ ! -r "$QUELLE" ]
	then
		echo "Sie haben kein Leserecht an $QUELLE"
		exit 1
	fi
	else
		echo "$QUELLE ist nicht vorhanden! "
		exit 2
fi

while [ -z "$ZIEL" ]
do
	read -p "Geben Sie das Ziel an : " ZIEL
done
if [ -e "$ZIEL" ]
then
	if [ ! -d "$ZIEL" ]
	then
		echo "$ZIEL ist kein Verzeichnis "
		exit 3
	else
		if [ ! -w "$ZIEL"  ]
		then
			echo "An $ZIEL fehlt Ihnen das Schreibrecht! "
			exit 4
		fi
	fi
else
	echo "$ZIEL ist nicht vorhanden"
	exit 4
fi

if [ -d "$QUELLE" ]
then
	cp -r $QUELLE $ZIEL
else
	cp -r $QUELLE $ZIEL
fi

	


