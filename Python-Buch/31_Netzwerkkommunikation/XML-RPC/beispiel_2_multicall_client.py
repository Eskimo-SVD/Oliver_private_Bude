#!/usr/bin/env python

from xmlrpc.client import ServerProxy, MultiCall


if __name__ == "__main__":
    cli = ServerProxy("http://localhost:1337")

    mc = MultiCall(cli)
    for i in range(10):
        mc.fak(i)
        mc.quad(i)

    for ergebnis in mc():
        print(ergebnis)
