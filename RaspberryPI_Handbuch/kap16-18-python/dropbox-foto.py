#!/usr/bin/python3
import datetime, dropbox, picamera
db = dropbox.Dropbox('your-token')

# Foto erstellen und lokal speichern
localname = 'tmp.jpg'
camera = picamera.PiCamera()
camera.resolution=(1280, 960)
camera.capture(localname)
camera.close()

# Foto hochladen
f = open(localname, 'rb')
today = datetime.date.today()
upname = today.strftime('/rapi-%Y-%m-%d.jpg')
db.files_upload(f.read(), upname)
f.close()



