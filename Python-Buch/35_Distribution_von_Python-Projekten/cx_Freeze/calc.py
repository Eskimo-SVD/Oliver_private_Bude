#!/usr/bin/env python

import sys

if __name__ == "__main__":
    if len(sys.argv) > 2:
        print("Ergebnis: {}".format(int(sys.argv[1]) + int(sys.argv[2])))
