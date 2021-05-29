#!/usr/bin/env python

import threading


class MeinThread(threading.Thread):
    zaehler = 0

    def run(self):
        for i in range(2000000):
            MeinThread.zaehler += 1


if __name__ == "__main__":
    t1 = MeinThread()
    t2 = MeinThread()
    t1.start(), t2.start()
    t1.join(), t2.join()

    print(MeinThread.zaehler)
