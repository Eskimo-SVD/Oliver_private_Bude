#!/usr/bin/env python

import threading


class PrimzahlThread(threading.Thread):
    EinAusLock = threading.Lock()
    
    def __init__(self, zahl):
        super().__init__()
        self.Zahl = zahl

    def run(self):
        i = 2
        while i*i <= self.Zahl:
            if self.Zahl % i == 0:
                with PrimzahlThread.EinAusLock:
                    print(f"{self.Zahl} ist nicht prim, "
                          f"da {self.Zahl} = {i} * {self.Zahl // i}")
                return
            i += 1
        with PrimzahlThread.EinAusLock:
            print(f"{self.Zahl} ist prim")


if __name__ == "__main__":
    meine_threads = []
    eingabe = input("> ")

    while eingabe != "e":
        try:
            thread = PrimzahlThread(int(eingabe))
            meine_threads.append(thread)
            thread.start()
        except ValueError:
            with PrimzahlThread.EinAusLock:
                print("Falsche Eingabe!")

        with PrimzahlThread.EinAusLock:
            eingabe = input("> ")

    for t in meine_threads:
        t.join()

