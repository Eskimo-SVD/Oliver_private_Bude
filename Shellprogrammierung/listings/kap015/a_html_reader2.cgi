#!/bin/sh
echo "Content-type: text/html"
echo ""

cat /srv/www/htdocs/docs/header.txt
cat $1
cat /srv/www/htdocs/docs/footer.txt
exit 0