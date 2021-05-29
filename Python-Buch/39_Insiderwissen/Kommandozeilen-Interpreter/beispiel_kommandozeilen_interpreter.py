#!/usr/bin/env python

import cmd
import time


class MeineKonsole(cmd.Cmd):
    def __init__(self):
        super().__init__()
        self.prompt = "==> "

    def do_date(self, prm):
        d = time.localtime()
        print("Heute ist der {:02}.{:02}.{:02}".format(d[2],d[1],d[0]))
        return False

    def help_date(self):
        print("Gibt das aktuelle Datum aus")

    def do_time(self, prm):
        z = time.localtime()
        print("Es ist {:02}:{:02}:{:02} Uhr".format(z[3], z[4], z[5]))
        return False
        
    def do_timer(self, prm):
        if prm == "start":
            self.startTime = time.time()
        elif prm == "get":
            print("Es sind {} Sekunden vergangen.".format(int(time.time() - self.startTime)))

    def do_exit(self, prm):
        print("Auf Wiedersehen")
        return True


if __name__ == "__main__":
    konsole = MeineKonsole()
    konsole.cmdloop()
