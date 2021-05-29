#!/usr/bin/env python

import imaplib


if __name__ == "__main__":
    im = imaplib.IMAP4("imap.hostname.de")
    im.login("Benutzername", "Passwort")

    print("Vorhandene Mailboxen:")
    for mb in im.list()[1]:
        name = mb.split(b'"."')[-1]
        print(" - {}".format(name.decode().strip(' "')))

    mb = input("Welche Mailbox soll angezeigt werden: ")
    im.select(mb)
    status, daten = im.search(None, "ALL")

    for mailnr in daten[0].split():
        typ, daten = im.fetch(mailnr, "(RFC822)")
        print("{}\n+++\n".format(daten[0][1].decode()))

    im.close()
    im.logout()
