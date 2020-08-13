#!/usr/bin/python3
# Datei funk_ping.py
import os

# Ihre Smartphone-IP-Adresse
ip = "192.168.188.37"

# Parameter -c gibt die Zyklenzahl an
# -c 1 = 1 x Ping
os.system("ping -c 1 " + ip)
print (os.system("ping -c 1 " + ip))

if os.system("ping -c 1 " + ip) == 0:
   # Handy erreichbar, Steckdosen EIN 
   print ("Handy antwortet")
   os.system("sudo /home/pi/rcswitch-pi/./send 11000 3 1")
else:
   # Handy nicht erreichbar, Steckdosen AUS
   print ("Keine Antwort")
   os.system("sudo /home/pi/rcswitch-pi/./send 11000 3 0")