#! /bin/bash
# Datei /usr/local/shellscripts/pumpi/netio.sh

#Benutzername und Passwort
USER=charly
PASS=s3cr3t

# in $1 steht die IP der Ziel-NetIO
# IP zu Kontrollzwecken ausgeben
echo "$1";

# in $2 steht entweder "status" oder oder die
# Schalt-Änderung, zB "uu1u"
echo "$2";
if [ "$2" = "status" ]; then
  ACTION="port=list";
else
  ACTION="port=$2";
fi

echo "debug ACTION = $ACTION"
URL="http://$1/tgi/control.tgi?login=p:$USER:$PASS&$ACTION"
wget -O /tmp/return.txt -i $URL 

# clear
echo "Status of power outlets on $1"
cat /tmp/return.txt|cut -f2 -d\>|cut -f1 -d\< && \
  echo"" >> /tmp/netio.output
cat /tmp/netio.output
rm /tmp/return.txt; rm /tmp/netio.output;
