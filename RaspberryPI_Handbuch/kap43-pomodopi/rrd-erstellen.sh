#!/bin/bash
WDIR=/usr/local/shellscripts/moisturesensor
ETCDIR=$WDIR/etc/
OUTDIR=$WDIR/output

rrdtool create $ETCDIR/moisture.rrd --step 60 \
  DS:data1:GAUGE:120:0:100 \
  DS:data2:GAUGE:120:0:100 \
  RRA:AVERAGE:0.5:1:2160 \
  RRA:AVERAGE:0.5:5:2016 \
  RRA:AVERAGE:0.5:15:2880 \
  RRA:AVERAGE:0.5:60:8760 \
  RRA:MAX:0.5:1:2160 \
  RRA:MAX:0.5:5:2016 \
  RRA:MAX:0.5:15:2880 \
  RRA:MAX:0.5:60:8760

