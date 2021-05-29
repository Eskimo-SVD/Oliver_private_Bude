#!/usr/bin/env python

import csv

if __name__ == "__main__":
    reader = csv.reader(open("beispieldaten_namen.csv"))
    for zeile in reader:
        print(zeile)
