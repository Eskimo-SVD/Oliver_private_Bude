#!/bin/sh
# Name: html_ps.cgi

echo "Content-type: text/html"
echo

cat /srv/www/htdocs/docs/header.txt
ps -ef
cat /srv/www/htdocs/docs/footer.txt
exit 0