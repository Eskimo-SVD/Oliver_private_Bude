#----------------------------------------------------
# Dateiname:  photo_email.py.py
# Das Programm sendet jede Stunde ein Foto per E-Mail.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from picamera import PiCamera
from time import sleep
import smtplib
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart

while True:
    camera = PiCamera()                          #1
    camera.resolution = (640, 480) 
    time.sleep(2)                                #2            
    camera.capture('foto.jpg')                 
    camera.close()

    f = open('foto.jpg', 'rb')                   #3
    image = MIMEImage(f.read())
    f.close()
    m = MIMEMultipart()                          #4                    
    m['To'] = 'empfaenger@adresse'
    m['From'] = 'absender@adresse'
    m['Subject'] = 'Foto von Zuhause'
    m.attach(image)

    s = smtplib.SMTP('post.webmailer.de')        #5
    s.login('Login-Name', 'passwort')
    s.send_message(m)       
    s.quit()
    sleep(3600)                                  #6



    
    
    
        
