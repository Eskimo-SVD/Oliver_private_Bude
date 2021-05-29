#!/usr/bin/env python

import socket


if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind(("", 50000))

        while True:
            daten, addr = s.recvfrom(1024)
            print("[{}] {}".format(addr[0], daten.decode()))
