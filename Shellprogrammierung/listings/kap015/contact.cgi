#!/bin/sh
# Name: contact.cgi
# Auswerten der Formmail

empfaenger="you@host"

( cat << MAIL
From: www@`hostname`
To: $empfaenger
Subject: Kontakt-Anfrage Ihrer Webseite

Inhalt der Eingabe lautet:

MAIL
# Eingabestring dekodieren
cat - | tr '&+=' '\n \t' | echo -e `sed 's/%\(..\)/\\\x\1/g'`

  echo ""
  echo "Abgeschickt am `date`"
) | sendmail -t

echo "Content-type: text/html"
echo ""

echo "<html><body>"
echo "Vielen Dank fuer Ihre Anfrage!"
echo "</body></html>"
exit 0