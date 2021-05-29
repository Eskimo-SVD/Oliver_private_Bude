#!/usr/bin/env python

import telnetlib


class POP3Telnet:
    def __init__(self, host, port):
        self.tel = telnetlib.Telnet(host, port)
        self.lese_daten()
        
    def close(self):
        self.tel.close()
        
    def lese_daten(self):
        return self.tel.read_until(b".\r\n", 20.0)
        
    def kommando(self, kom):
        self.tel.write(("{}\r\n".format(kom)).encode())
        return self.lese_daten()


if __name__ == "__main__":
    host = "pop.beispiel.de"
    port = 110
    user = "Benutzername"
    passwd = "Passwort"

    pop = POP3Telnet(host, port)
    pop.kommando("USER {}".format(user))
    pop.kommando("PASS {}".format(passwd))
    pop.kommando("LIST")
    print(pop.lese_daten().decode())
    pop.kommando("QUIT")
    pop.close()
