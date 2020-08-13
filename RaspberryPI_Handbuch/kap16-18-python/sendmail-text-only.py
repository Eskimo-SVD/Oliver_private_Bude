#!/usr/bin/python3
import smtplib, sys
from email.mime.text import MIMEText
from email.header import Header

frm  = 'Absender <sender@myhost.com>'
to   = 'Ziel <ziel@otherhost.com>'
subj = 'Test-Mail von Python mit äöüß'
msg  = 'Das ist\nder Nachrichtentext mit äöüß.'

try:
  mime = MIMEText(msg, 'plain', 'utf-8')
  mime['From'] = frm
  mime['To']   = to
  mime['Subject'] = Header(subj, 'utf-8')

  smtp = smtplib.SMTP("myhost.com")
  smtp.starttls()
  smtp.login("username", "password")
  smtp.sendmail(frm, to, mime.as_string())
  smtp.quit()
except:
  print("Beim E-Mail-Versand ist ein Fehler aufgetreten:", sys.exc_info())