#!/usr/bin/python3

import re

pattern = r '^ [A-Za-z0-9\.\+_-]+@[A-Za-z0-9\._-]+\.[a-zA-Z]+$ '
email = input ("Geben Sie eine E-Mail -Adresse ein: ")

if re.match(pattern , email):
    print ("Die E-Mail -Adresse ist OK.")
else:
    print ("Die E-Mail -Adresse sieht fehlerhaft aus.")