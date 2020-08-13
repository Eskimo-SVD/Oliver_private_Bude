#! /bin/bash
# Datei /usr/local/shellscripts/pumpi/webbox.sh
# dieses Script liest den aktuellen
# Output der PV aus der Webbox aus
# und schreibt ihn in die Datei
# $WEBDIR/pvleistung.txt

WDIR=/usr/local/shellscripts/pumpi
WEBDIR=/var/www
RRDDIR=$WDIR/rrd

WEBBOX=192.168.2.178
ROUTER=192.168.2.1
NETIO=192.168.2.11

wget -O /tmp/webbox.tmp 192.168.2.178/home.htm
PVLEISTUNG=\
  $(cat /tmp/webbox.tmp |grep Power|cut -f2 -d\>|cut -f1 -d" ")

# prüfen, ob Daten angekommen sind (Verbindung zur
# Webbox könnte gestört sein)
if [ -z "$PVLEISTUNG" ]; then
  logger "keine Daten von der Webbox"
  PVLEISTUNG=0
  echo $PVLEISTUNG > $WEBDIR/pvleistung.txt
else
  logger "PV-Leistung = $PVLEISTUNG";
  # Der folgende Vergleich geht schief, wenn $PVLEISTUNG
  # kein Integer ist. Das passiert bei der Webbox immer 
  # dann, wenn die Leistung > 10 kW ist.
  if ! [ "$PVLEISTUNG" -eq "$PVLEISTUNG" 2> /dev/null ]
  then
      # Kommaformat korrigieren - unter 10 kW liefert die 
	  # Webbox den Output 4stellig (zB 5647 Watt), darüber
	  # als zB 10.3 kW
	  KOMMA=$(echo "$PVLEISTUNG"|sed s/\,/\./); 
	  logger  "Wert ueber 10kW, wird konvertiert" > /dev/stderr
	  NEWWATT=$(echo "$KOMMA * 1000"|bc -l|cut -f1 -d\.);
	  logger "konvertierter Wert:  $NEWWATT"
      echo $NEWWATT > $WEBDIR/pvleistung.txt
  else
      echo $PVLEISTUNG > $WEBDIR/pvleistung.txt 
  fi
fi



# RRD erstellen, falls sie noch nicht existiert, und füllen
if [ -e $RRDDIR/webbox.rrd ]; then
    echo "OK, webbox.rrd exists.";
   else
    rrdtool create $RRDDIR/webbox.rrd --step 60  \
    DS:data1:GAUGE:180:0:16000 \
    DS:data2:GAUGE:180:0:16000 \
    DS:data3:GAUGE:180:0:16000 \
    DS:data4:GAUGE:180:0:16000 \
    RRA:AVERAGE:0.5:1:600 \
    RRA:AVERAGE:0.5:6:700 \
    RRA:AVERAGE:0.5:24:775 \
    RRA:AVERAGE:0.5:288:797 \
    RRA:MAX:0.5:1:600 \
    RRA:MAX:0.5:6:700 \
    RRA:MAX:0.5:24:775 \
    RRA:MAX:0.5:288:797;
    echo "RRD created";
fi

DATA1=$(cat $WEBDIR/pvleistung.txt);
DATA2=$(cat $WDIR/rrd-ein.txt);
DATA3=$(cat $WDIR/rrd-aus.txt);
rrdtool update $RRDDIR/webbox.rrd N:$DATA1:$DATA2:$DATA3:U;

#Grafik erzeugen
for i in -4h -24h -7d -30d -360d; do 
  rrdtool graph $WEBDIR/webbox$i.gif \
    -l 0 -r --border=0 -c GRID#ffffff00 -c BACK#ffffff \
    --lazy --slope-mode --start $i \
    --title "PV-Leistung und PumPi Schaltzyklen ($i)" \
    --vertical-label "Watt" -w 400 -h 140 \
    DEF:data3=$RRDDIR/webbox.rrd:data3:\
      MAX AREA:data3#ff777750:"aus\n"  \
    DEF:data1=$RRDDIR/webbox.rrd:data1:\
      MAX AREA:data1#7777ff:"PV-Leistung (Watt)\n" \
    DEF:data2=$RRDDIR/webbox.rrd:data2:\
      MAX LINE2:data2#77ff77:"ein / Schaltschwelle\n" 
done
