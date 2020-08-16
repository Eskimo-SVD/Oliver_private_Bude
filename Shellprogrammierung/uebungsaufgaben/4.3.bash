#! /bin/bash

if [ $# -ne 1 ]
then
	echo "Es wird genau ein Dateiname als Argument erwartet"
	exit 1
fi

if [ -f $1 ]
then
	if [ -r $1 ]
	then
		echo -n "Sie können $1 LESEN "
	fi	
	if [ -w $1 ]
  then
	  echo -n "SCHREIBEN "
	fi	
	if [ -x $1 ]
	then
		echo -n "AUSFÜHREN"
	fi
else
	echo "$1 ist keine Datei"
	exit 1
fi
echo " "


