#!/bin/sh
# myenv.cgi
# Umgebungsvariablen auf einem Server anzeigen

echo "Content-type: text/html"
echo 
echo "<html><body><h2>Umgebungsvariablen von"\
     " `uname -n` (`date`)</h2>"
echo "<pre>"
# Wenn env nicht vorhanden, dann printenv ausführen ...
env || printenv
echo "</pre></body></html>"