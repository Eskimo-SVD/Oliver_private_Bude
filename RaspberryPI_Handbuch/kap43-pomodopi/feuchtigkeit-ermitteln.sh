#!/bin/bash
WDIR=/usr/local/shellscripts/moisturesensor
ETCDIR=$WDIR/etc/
OUTDIR=$WDIR/output

MOISTPROZENT=$($WDIR/moist_einmal.py|cut -f1 -d\.);
logger "$MOISTPROZENT Prozent Substratfeuchte"
echo $MOISTPROZENT > $ETCDIR/moisture-vh400-1.text

