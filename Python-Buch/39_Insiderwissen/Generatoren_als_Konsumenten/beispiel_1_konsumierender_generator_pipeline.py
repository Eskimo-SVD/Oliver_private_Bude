#!/usr/bin/env python


def konsument(f):
    def h_f(*args, **kwargs):
        gen = f(*args, **kwargs)
        next(gen)
        return gen
    return h_f


@konsument
def filter_hebe(stufe, ziel):
    while True:
        ziel.send(stufe + (yield))


@konsument
def filter_mittelwert(fenster, ziel):
    werte = []
    while True:
        werte.append((yield))
        if len(werte) >= fenster:
            ziel.send(sum(werte)/fenster)
            werte.pop(0)


@konsument
def ausgabe():
    while True:
        print((yield))


if __name__ == "__main__":
    p = ausgabe()
    f = filter_hebe(10, p)
    f = filter_mittelwert(2, f)

    for d in [1, 3, 2, 4, 2, 1]:
        f.send(d)
