#!/usr/bin/env python

from concurrent import futures
from time import sleep, time


def test(t):
    sleep(t)
    print(f"Ich habe {t} Sekunden gewartet. Zeit: {time():.0f}")


if __name__ == "__main__":
    print(f"Startzeit:                          {time():.0f}")
    with futures.ProcessPoolExecutor(max_workers=3) as e:
        e.submit(test, 9)
        e.submit(test, 2)
        e.submit(test, 5)
        e.submit(test, 6)
        print("Alle Aufgaben gestartet.")

    print("Alle Aufgaben erledigt.")
