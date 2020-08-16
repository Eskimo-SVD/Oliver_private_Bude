#!/bin/sh
# a_html_reader.cgi

echo "Content-type: text/html"
echo ""

cat << HEADER
<HTML>
<HEAD><TITLE>Ausgabe der Datei: $1</TITLE>
</HEAD>
<BODY bgcolor="#FFFF00" text="#000000">
<HR SIZE=3>
<H1>Ausgabe der Datei: $1 </H1>
<HR SIZE=3>
<P>
<SMALL>
<PRE>
HEADER

cat $1

cat << FOOTER
</PRE>
</SMALL>
<P>
<HR SIZE=3>
<H1><B>Ende</B> Ausgabe der Datei: $1 </H1>
<HR SIZE=3>
</BODY>
</HTML>
FOOTER

exit 0