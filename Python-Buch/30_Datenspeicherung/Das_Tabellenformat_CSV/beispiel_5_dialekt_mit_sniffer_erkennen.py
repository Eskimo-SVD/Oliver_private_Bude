#!/usr/bin/env python

import csv

if __name__ == "__main__":
     sample = open("beispieldaten_namen.csv").read(1024)
     dialect = csv.Sniffer().sniff(sample)
     print("Trennzeichen:", dialect.delimiter)
     print("Spaltenkoepfe vorhanden:", csv.Sniffer().has_header(sample))

     reader = csv.reader(open("beispieldaten_namen.csv"), dialect)
     for row in reader:
          print(row)

