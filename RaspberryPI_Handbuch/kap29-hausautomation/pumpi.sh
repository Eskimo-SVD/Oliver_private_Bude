#! /bin/bash
# Datei /usr/local/shellscripts/pumpi/pumpi.sh
# Dieses Script läuft per Cron alle 15 min.
# Es schaltet Port 1 einer NetIO ein,
# sobald die Leistung der Photovoltaik einen
# Schwellenwert überschreitet, oder bei
# Unterschreitung des Wertes aus.

WDIR=/usr/local/shellscripts/pumpi
WEBDIR=/var/www
RRDDIR=$WDIR/rrd

WEBBOX=192.168.2.178
ROUTER=192.168.2.1
NETIO=192.168.2.11

#Schwellenwert in Watt
SWERT=$(cat $WEBDIR/schwelle.txt);
echo "Schwellenwert = $SWERT";

# 1. WLAN-Verbindung prüfen
WLANSIG=$(/sbin/iwconfig wlan0|grep "Link Q"|\
          cut -f2 -d\=|cut -f1 -d\/);

if [ -z "$WLANSIG" ]; then
  logger "WLAN-Signalstärke: unbekannt";
  echo "$WLANSIG von 100" > $WEBDIR/wlansig.txt;
else
  logger "WLAN-Signalstärke: $WLANSIG% ";
  echo "$WLANSIG Prozent" > $WEBDIR/wlansig.txt;
fi

# 2. prüfen, ob NetIO erreichbar ist
NETIOCONN=$(httping -G -t 5s -c 5 -g http://$NETIO|\
            grep connects|cut -f2 -d\,|cut -f1 -d\,|\
            tr -d [:blank:]|cut -b1)

if [ -z "$NETIOCONN" ]; then
  NETIOCONN=0
fi

if [ $NETIOCONN -le 3 ]; then
  NETIOCONN=0
  logger "NETIO nicht erreichbar"
      echo "keine Verbindung" > $WEBDIR/netioconn.txt 
  #Alarmierung per Mail
  #[...]
else
  NETIOCONN=1
  logger "NetIO: OK"
  echo "OK" > $WEBDIR/netioconn.txt
fi


# 3. Prüfen, ob Webbox erreichbar ist
WEBBOXCONN=$(httping -G -t 5s -c 5 -g http://$WEBBOX|\
             grep connects|cut -f2 -d\,|cut -f1 -d\,|\
             tr -d [:blank:]|cut -b1)

if [ -z "$WEBBOXCONN" ]; then
  WEBBOXCONN=0
fi
if [ $WEBBOXCONN -le 3 ]; then 
  WEBBOXCONN=0
  logger "Webbox nicht erreichbar"
  echo "keine Verbindung" > $WEBDIR/webboxconn.txt
else
  WEBBOXCONN=1
  logger "Webbox: OK"
  echo "OK" > $WEBDIR/webboxconn.txt
fi

PVINPUT=$(cat $WEBDIR/pvleistung.txt);

# Der folgende kleine Kunstgriff ist notwendig, weil $PVINPUT
# evtl. nicht in allen Fällen als Integer erkannt wird.
PVLEISTUNG=$(echo $((PVINPUT*1)));
echo "PV-Leistung = $PVLEISTUNG"

# weiter machen, wenn Verbindung zur Webbox und Steckdose OK sind
if [ "$WEBBOXCONN" = "1" ] && [ "$NETIOCONN" = "1" ]; then

    if [ $SWERT -eq 1 ]; then
      $WDIR/netio.sh $NETIO 1uuu;
      logger "Permanent eingeschaltet"
      #RRD
      echo "$SWERT" > $WDIR/rrd-ein.txt 
      echo "0" > $WDIR/rrd-aus.txt 
    elif [ $SWERT -eq 0 ]; then
      $WDIR/netio.sh $NETIO 0uuu;
      logger "Permanent ausgeschaltet"
      #RRD
      echo "0" > $WDIR/rrd-ein.txt
      echo "$SWERT" > $WDIR/rrd-aus.txt
    elif [ $PVLEISTUNG -ge $SWERT ]; then
      $WDIR/netio.sh $NETIO 1uuu
      logger "$PVLEISTUNG groesser $SWERT: eingeschaltet" 
      #RRD
      echo $SWERT > $WDIR/rrd-ein.txt
      echo "0" > $WDIR/rrd-aus.txt
    else
      $WDIR/netio.sh $NETIO 0uuu
      logger "$PVLEISTUNG kleiner $SWERT: ausgeschaltet"
      echo "0" > $WDIR/rrd-ein.txt
      echo "$SWERT" > $WDIR/rrd-aus.txt
    fi

else

    # sicher ist sicher: war eine der Prüfungen negativ, 
    # wird die Steckdose ausgeschaltet
    $WDIR/netio.sh $NETIO 0uuu
    logger "Webbox oder NetIO nicht erreichbar"
fi
