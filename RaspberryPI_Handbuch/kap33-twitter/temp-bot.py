#!/usr/bin/env python

#Datei /opt/twitter/tweetbot.py

# Bibliotheken laden
import sys
import os
from twython import Twython

# diese Information kopieren Sie von der Registrierungs-Webseite
API_KEY = 'w3mjFAsjAySvsh7quHDHsqgRY'
API_SECRET = 
  'iF6di8kCLfs52oDVp1BaB8zLi47rJkD2Og1j1gZMugVEj4rXeY'
ACCESS_TOKEN = 
  '15959734-FwnN5i024dlLrEbzdpdisjcGJDQSgCIMN0o5mIy9J'
ACCESS_TOKEN_SECRET = 
      'AaBwptX6xSaM2a0NAWrINj1eNfB75ziunDXs8DlP1Ky6w'

# Zugriff auf die API
api = Twython(API_KEY, API_SECRET,
      ACCESS_TOKEN,ACCESS_TOKEN_SECRET) 

cmd = '/opt/vc/bin/vcgencmd measure_temp'
line = os.popen(cmd).readline().strip()
temp = line.split('=')[1].split("'")[0]
api.update_status(status =
    'Die Temperatur der Raspberry-CPU ist '+temp+' C')
