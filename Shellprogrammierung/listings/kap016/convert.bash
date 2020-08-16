#!/bin/bash
VERZEICHNIS=`dirname $1`

if [ $# -eq 0 ]
then
	for i in `ls $1`
	do
  	NAME_NEU=$(echo  $i | awk -F. '{print $1}')
  	NAME_NEU=${NAME_NEU}.eps
  	convert ${1}${i} ${1}${NAME_NEU}
	done
fi

if [ $# -gt 0 ]
then
	for i
	do
  	NAME_NEU=$(echo  $i | awk -F. '{print $1}')
		echo "NAME ohne == $NAME_NEU"
  	NAME_NEU=${NAME_NEU}.eps
		echo "NAME mit neu == $NAME_NEU"
  	#convert ${1}${i} ${1}${NAME_NEU}
  	convert ${i} ${NAME_NEU}
	done
fi





