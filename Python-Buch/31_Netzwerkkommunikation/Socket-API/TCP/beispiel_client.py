#!/usr/bin/env python

import socket


if __name__ == "__main__":
    ip = input("IP-Adresse: ")
    with socket.create_connection((ip, 50000)) as s:
        while True:
            nachricht = input("Nachricht: ")
            s.send(nachricht.encode())
            antwort = s.recv(1024)
            print("[{}] {}".format(ip, antwort.decode()))
