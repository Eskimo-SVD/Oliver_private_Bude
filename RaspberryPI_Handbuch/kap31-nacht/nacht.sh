```bash
#! /bin/bash
WDIR=/home/pi/shellscripts/lux
TRIGGER=300
TRADFRI=/$WDIR/ikea.sh
TRADFRIONOFF=/$WDIR/ikea-on-off.sh
HUECMD=/$WDIR/hue.sh
HUECMDONOFF=/$WDIR/hue-on-off.sh
STATUS="OFF"

# Dieses Programm wertet einen Luxsensor vom
# Typ BH1570 aus und steuert Ikea- und 
# Hue-Leuchtmittel anhand der Messwerte
while true; do

  LUX=$($WDIR/lux)
  
  # gewünschte Helligkeit in Prozent ausrechnen
  PROZ=$(echo "scale=2;( 100 - ($LUX / $TRIGGER ) * 100)"\
         |bc -l|cut -f1 -d\.);
  
  # Für das Hue-System Prozentwert mit 2.54 multiplizieren, 
  # denn es erwartet Werte von 1 - 254
  HUELIGHT=$(echo "($PROZ * 2.54)"|bc -l|cut -f1 -d\.)
  echo "MESSWERT = $LUX"

  if [ $LUX -lt $TRIGGER ]; then
     echo "Messwert unter $TRIGGER lux" 	

     if [ "$STATUS" = "OFF" ]; then
       echo "Status bisher: off. Leuchten einschalten"; 
       $TRADFRIONOFF "on";
       $HUECMDONOFF "true";

       echo "Leuchten auf $PROZ Prozent"      
       $TRADFRI $PROZ 
       $HUECMD $HUELIGHT 
       STATUS="ON"
      
     else
       echo "Messwert unter Trigger und Status = on"

       echo "$lampe auf $PROZ Prozent";
       $TRADFRI $PROZ 
       $HUECMD $HUELIGHT
      fi

  else
      if [ "$STATUS" = "ON" ]; then
        echo "Messwert über Trigger und Status=on; Ausschalten."
        echo "$lampe ausschalten"
	$TRADFRI 1 
	$HUECMD 1
	$TRADFRIONOFF "off"
	$HUECMDONOFF "false"
	STATUS="OFF"
      else
	echo "Messwert ueber Trigger und Status=off. Keine Aktion"
      fi 

  fi	  
  sleep 5 
done 
```

