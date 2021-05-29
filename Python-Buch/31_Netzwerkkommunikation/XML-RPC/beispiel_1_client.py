#!/usr/bin/env python

from xmlrpc.client import ServerProxy


if __name__ == "__main__":
    cli = ServerProxy("http://localhost:1337")
    print(cli.fak(5))
    print(cli.quad(5))
