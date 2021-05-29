#!/usr/bin/env python

from xmlrpc.server import SimpleXMLRPCServer as Server


def fak(n):
    """ Berechnet die Fakultaet der ganzen Zahl n. """
    erg = 1
    for i in range(2, n+1):
        erg *= i
    return erg


def quad(n):
    """ Berechnet das Quadrat der Zahl n. """
    return n*n


if __name__ == "__main__":
    with Server(("", 1337)) as srv:
        srv.register_function(fak)
        srv.register_function(quad)
        srv.serve_forever()
