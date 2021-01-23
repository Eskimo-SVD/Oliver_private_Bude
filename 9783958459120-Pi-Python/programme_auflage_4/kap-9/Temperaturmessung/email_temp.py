#--------------------------------------------------------------
# Dateiname:  email_temp.py
# Daten werden per E-Mail gesendet
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

import smtplib
from email.mime.text import MIMEText
def send_temp(temp, to_address):   
    # Sendet E-Mail mit Temperatur an to_address                    
    m = MIMEText('Temperatur: ' + str(temp) + '°C.')  #1
    m['To'] = to_address                              #2   
    m['From'] = 'absender@absenderdomäne'           
    m['Subject'] = 'Temperaturdaten'                   

    s = smtplib.SMTP('smtp-Server')                   #3
    s.login('Login-Name', 'Passwort')                 #4
    s.send_message(m)                                 #5
    s.quit()

if __name__ == '__main__':                   
    send_temp(20.0, 'empfänger@empfängerdomäne')      #6


    
    
    
        
