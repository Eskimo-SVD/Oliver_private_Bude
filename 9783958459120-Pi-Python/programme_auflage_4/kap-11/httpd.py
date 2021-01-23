#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  httpd.py 
# HTTP-Server, der CGI-Skripte verarbeiten kann.
# Die CGI-Skripte müssen in einem Unterverzeichnis des
# Verzeichnisses sein, in dem die Programmdatei des Servers ist.
# Dieses Unterverzeichnis hat den Namen cgi-bin.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 11
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from http.server import HTTPServer, CGIHTTPRequestHandler
serveradresse =("", 80)                               #1
server=HTTPServer(serveradresse,
                  CGIHTTPRequestHandler)              #2
server.serve_forever()                                #3













                    
