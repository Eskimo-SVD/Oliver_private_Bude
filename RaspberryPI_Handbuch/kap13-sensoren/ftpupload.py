#!/usr/bin/python3
import ftplib, picamera, sys, time
cam = picamera.PiCamera()

def upload(): 
    session = ftplib.FTP('ftp.beispiel.com', 'ftp_username@domain.de', 'PASSWORD')
    directory = "/PFAD_AUF_DEM_SERVER"
    session.cwd(directory)
    file = open('bild.jpg','rb')
    session.storbinary('STOR bild.jpg', file)
    file.close()
    session.quit()
    return

try:
    while True:        
        cam.capture('bild.jpg')
        time.sleep(1)  
        upload()
        
except KeyboardInterrupt:
  cam.close()
  sys.exit()