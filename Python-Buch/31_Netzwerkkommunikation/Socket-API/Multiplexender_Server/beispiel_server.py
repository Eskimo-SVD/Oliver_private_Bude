#!/usr/bin/env python

import socket
import selectors


def message(selector, client):
    nachricht = client.recv(1024)
    ip = client.getpeername()[0]
    if nachricht:
        print("[{}] {}".format(ip, nachricht.decode()))
    else:
        print("+++ Verbindung zu {} beendet".format(ip))
        selector.unregister(client)
        client.close()


def accept(selector, sock):
    connection, addr = sock.accept()
    connection.setblocking(False)
    selector.register(connection, selectors.EVENT_READ, message)


if __name__ == "__main__":
    with socket.create_server(("", 50000)) as s:
        s.setblocking(False)
        s.listen(1)

        selector = selectors.DefaultSelector()
        selector.register(s, selectors.EVENT_READ, accept)

        while True:
            for key, mask in selector.select():
                key.data(selector, key.fileobj)
