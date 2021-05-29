#!/usr/bin/env python


def jungen():
    yield "Phillip"
    yield "Sven"
    return 2


def maedchen():
    yield "Carina"
    yield "Lina"
    return 2


def namen(auch_jungen=True):
    anzahl_maedchen = (yield from maedchen())
    print("{} Mädchen".format(anzahl_maedchen))
    if auch_jungen:
        anzahl_jungen = (yield from jungen())
        print("{} Jungen".format(anzahl_jungen))


if __name__ == "__main__":
    print("namen():     ", list(namen()))
    print("namen(False):", list(namen(False)))

