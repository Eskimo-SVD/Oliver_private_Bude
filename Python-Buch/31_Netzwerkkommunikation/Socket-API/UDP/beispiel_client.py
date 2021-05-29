#!/usr/bin/env python

import socket


if __name__ == "__main__":
    ip = input("IP-Adresse: ")
    nachricht = input("Nachricht: ")

    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.sendto(nachricht.encode(), (ip, 50000))
