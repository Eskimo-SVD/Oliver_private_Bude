#!/bin/sh
# Name: html_access_log.cgi
# Apaches access_log analysieren und ausgeben
echo "Content-type: text/html"
echo

cat /srv/www/htdocs/docs/header.txt
./readaccess /pfad/zum/logfile/access_log
cat /srv/www/htdocs/docs/footer.txt 
exit 0