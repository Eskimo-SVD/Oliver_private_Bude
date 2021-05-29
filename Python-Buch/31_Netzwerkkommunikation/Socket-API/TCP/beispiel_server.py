#!/usr/bin/env python

import socket


if __name__ == "__main__":
    with socket.create_server(("", 50000)) as s:
        s.listen(1)

        while True:
            komm, addr = s.accept()
            while True:
                data = komm.recv(1024)

                if not data:
                    komm.close()
                    break

                print("[{}] {}".format(addr[0], data.decode()))
                nachricht = input("Antwort: ")
                komm.send(nachricht.encode())
