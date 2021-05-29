#!/usr/bin/env python

from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage
from email.mime.text import MIMEText


if __name__ == "__main__":
    msg = MIMEMultipart()
    msg["Subject"] = "Hallo Welt"
    msg["From"] = "Donald Duck <don@ld.de>"
    msg["To"] = "Onkel Dagobert <d@gobert.de>"

    text = MIMEText("Dies ist meine selbst erstellte E-Mail.")
    msg.attach(text)

    with open("kaffee.png", "rb") as f:
        bild = MIMEImage(f.read())
        msg.attach(bild)

    print(msg.as_string())
