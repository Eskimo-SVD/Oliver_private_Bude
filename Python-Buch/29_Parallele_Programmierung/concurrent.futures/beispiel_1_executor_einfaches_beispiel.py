#!/usr/bin/env python

from concurrent import futures
from time import sleep, time


def test(t):
    sleep(t)
    print(f"Ich habe {t} Sekunden gewartet. Zeit: {time():.0f}")


if __name__ == "__main__":
    e = futures.ThreadPoolExecutor(max_workers=3)
    print(f"Startzeit:                          {time():.0f}")
    e.submit(test, 9)
    e.submit(test, 2)
    e.submit(test, 5)
    e.submit(test, 6)
    print("Alle Aufgaben gestartet.")
    e.shutdown()
    print("Alle Aufgaben erledigt.")

