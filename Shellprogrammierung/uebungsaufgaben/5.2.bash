#! /bin/bash

#Einlesen der Datei /etc/passwd
exec 3< ./passwd

#Oeffnen der Datei user.txt
exec 4> ./user.txt
BACKIFS=$IFS 
IFS=:
while read LINE <&3
do
	echo ZEILE $LINE
	set $LINE
	echo "$1 $3 $4 $7"  >&4 
done
IFS=$BACKIFS
#Schliessen der Datei 
exec 4>&-
exec <user.txt
printf "%-10s %-5s %-5s %-15s\n" "Benutzer"  "UID"  "GID"  "Loginshell"
echo ""
while read USER USERID GID SHELL
do 
	printf "%-10s %-5s %-5s %-15s\n" $USER $USERID $GID $SHELL
done

	
