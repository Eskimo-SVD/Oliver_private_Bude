#!/usr/bin/env python


class MeinLogfile:
    def __init__(self, logfile):
        self.logfile = logfile
        self.f = None
        
    def eintrag(self, text):
        self.f.write("==> {}\n\r".format(text))
        
    def __enter__(self):
        self.f = open(self.logfile, "w")
        return self
        
    def __exit__(self, exc_type, exc_value, traceback):
        self.f.close()
    

if __name__ == "__main__":
    with MeinLogfile("logfile.txt") as log:
        log.eintrag("Hallo Welt")
        log.eintrag("Na, wie gehts?")
        print("Neues logfile wurde geschrieben")
