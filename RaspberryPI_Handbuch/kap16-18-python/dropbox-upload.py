#!/usr/bin/python3
import dropbox
db = dropbox.Dropbox('your-token')
fname = 'test.jpg'     # Name einer lokalen Datei
dname = '/upload.jpg'  # Name der Datei in Dropbox
f = open(fname, 'rb')
response = db.files_upload(f.read(), dname)
print('uploaded:', response)
f.close()

