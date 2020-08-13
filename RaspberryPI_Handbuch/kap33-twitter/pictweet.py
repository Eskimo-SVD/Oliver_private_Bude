#!/usr/bin/env python
# Bibliotheken laden
import sys
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
# Tweet senden
photo = open('webcam.jpg', 'rb')
api.update_status_with_media(media = photo, 
          status = 'Heute ist es leider grau.')
