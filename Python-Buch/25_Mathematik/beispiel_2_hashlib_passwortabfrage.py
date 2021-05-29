#!/usr/bin/env python

import hashlib

if __name__ == "__main__":
    pwhash = "578127b714de227824ab105689da0ed2"  # hashlib.md5("Mein Passwort")

    m = hashlib.md5(bytes(input("Ihr Passwort bitte: "), "utf-8"))
    if pwhash == m.hexdigest():
        print("Zugriff erlaubt")
    else:
        print("Zugriff verweigert")
