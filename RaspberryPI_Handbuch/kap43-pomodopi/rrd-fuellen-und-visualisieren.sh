#!/bin/bash
WDIR=/usr/local/shellscripts/moisturesensor
ETCDIR=$WDIR/etc/
OUTDIR=$WDIR/output

MOISTPROZ=$(cat $ETCDIR/moisture-vh400-1.text);
echo "$MOISTPROZ Prozent Substratfeuchte"

rrdtool update $ETCDIR/moisture.rrd N:$MOISTPROZ:U

for i in -4h -12h -24h -7d -30d -90d -180d -360d; do

  rrdtool graph $OUTDIR/moisture$i.gif \
    --border=0 -c GRID#ffffff00 -c BACK#ffffff \
    --lazy --slope-mode --start $i \
    --title "Bodenfeuchtigkeit ($i)" \
    --vertical-label "Prozent" -w 400 -h 140 \
    DEF:data1=$ETCDIR/moisture.rrd:data1:AVERAGE \
    DEF:data2=$ETCDIR/moisture.rrd:data2:AVERAGE \
    CDEF:shading2=data1,0.98,* AREA:shading2#0000F9:\
      "Bodenfeuchtigkeit (aktuell $MOISTPROZ Prozent)\n" \
    CDEF:shading10=data1,0.90,* AREA:shading10#0F0FF9 \
    CDEF:shading15=data1,0.85,* AREA:shading15#1818F9 \
    CDEF:shading20=data1,0.80,* AREA:shading20#2D2DF9 \
    CDEF:shading25=data1,0.75,* AREA:shading25#3C3CF9 \
    CDEF:shading30=data1,0.70,* AREA:shading30#4B4BF9 \
    CDEF:shading35=data1,0.65,* AREA:shading35#5A5AF9 \
    CDEF:shading40=data1,0.60,* AREA:shading40#6969F9 \
    CDEF:shading45=data1,0.55,* AREA:shading45#7878F9 \
    CDEF:shading50=data1,0.50,* AREA:shading50#8787F9 \
    CDEF:shading55=data1,0.45,* AREA:shading55#9696F9 \
    CDEF:shading60=data1,0.40,* AREA:shading60#A5A5F9 \
    CDEF:shading65=data1,0.35,* AREA:shading65#B4B4F9 \
    CDEF:shading70=data1,0.30,* AREA:shading70#C3C3F9 \
    CDEF:shading75=data1,0.25,* AREA:shading75#D2D2F9 \
    CDEF:shading80=data1,0.20,* AREA:shading80#E1E1F9 \
    CDEF:shading85=data1,0.15,* AREA:shading85#E1E1F9

done

