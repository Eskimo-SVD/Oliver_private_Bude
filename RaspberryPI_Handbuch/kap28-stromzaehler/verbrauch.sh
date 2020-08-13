#!/bin/bash
# Datei /usr/local/shellscripts/verbrauch/verbrauch.sh
WDIR=/usr/local/shellscripts/verbrauch
RRDDIR=$WDIR/rrd
IMGDIR=$WDIR/bilder

# Zählerstand extrahieren (der Zählerstand steht in den
# Bytes 285 bis 294, muss je nach Zählermodell angepasst werden
BEZUGZAEHLERSTAND=$(cat $WDIR/sml.txt|cut -b285-294);

# in Dezimalzahlen umrechnen
BZZDEZIMAL=$(echo "ibase=16;obase=A;$BEZUGZAEHLERSTAND"|bc);

# Ergebnis in Wh
BZZWH=$(echo "scale=4;$BZZDEZIMAL/10"|bc -l);

echo "Der aktuelle Bezugszählerstand ist $BZZKWH Wh."

# RRD anlegen, falls sie noch nicht existiert
if [ -e $RRDDIR/verbrauch.rrd ]; then
  echo "OK, verbauch.rrd exists.";
else
  rrdtool create $RRDDIR/verbrauch.rrd --step 60 \
    DS:data1:GAUGE:180:0:U \
    DS:data2:GAUGE:180:0:U \
    DS:data3:GAUGE:180:0:U \
    DS:data4:GAUGE:180:0:U \
    RRA:MAX:0.5:1:600 \
    RRA:MAX:0.5:6:700 \
    RRA:MAX:0.5:24:775 \
    RRA:MAX:0.5:288:797;
  echo "RRD created";
fi

# Mit dem folgenden Kommando werden die Daten 
# in die RRD geschrieben
rrdtool update $RRDDIR/energiebilanz.rrd N:$BZZWH:U:U:U;

# ab hier werden die Auswertungsgrafiken generiert
for i in -4h -8h -24h -7d -30d -90d -180d -360d; do
  rrdtool graph $IMGDIR/verbrauch-$i.gif \
    -c GRID#ffffff00 -c BACK#ffffff \
    -c SHADEA#ffffff -c SHADEB#ffffff \
    --lazy --slope-mode --start $i \
    --title "Verbrauch ($i)" --vertical-label "Watt" \
    -w 750 -h 150 \
    DEF:data1=$RRDDIR/verbrauch.rrd:data1:AVERGAGE \
    AREA:data1#aa5555:"Verbrauch";
done
