#!/usr/bin/env python

from argparse import ArgumentParser


if __name__ == "__main__":
    parser = ArgumentParser(description = "Ein Taschenrechner")
    parser.add_argument("-o", "--operation", default="plus", help="Rechenoperation")
    parser.add_argument("operanden", metavar="Operand", type=float, nargs="+", help="Operanden")
    parser.add_argument("-i", "--integer", dest="type", action="store_const", const=int, default=float, help="Ganzzahlige Berechnung")
    args = parser.parse_args()

    calc = {
        "plus"    : lambda a, b: a + b,
        "minus"   : lambda a, b: a - b,
        "mal"     : lambda a, b: a * b,
        "geteilt" : lambda a, b: a / b
        }

    op = args.operation
    if op in calc:
        ergebnis = args.type(args.operanden[0])
        for z in args.operanden[1:]:
            ergebnis = calc[op](ergebnis, args.type(z))
        print("Ergebnis:", ergebnis)
    else:
        parser.error("{} ist keine gültige Operation".format(op))
