#!/usr/bin/env python

from email.message import Message


if __name__ == "__main__":
    msg = Message()
    msg.set_payload("Dies ist meine selbst erstellte E-Mail.")
    msg["Subject"] = "Hallo Welt"
    msg["From"] = "Donald Duck <don@ld.de>"
    msg["To"] = "Onkel Dagobert <d@gobert.de>"
    print(msg.as_string())
