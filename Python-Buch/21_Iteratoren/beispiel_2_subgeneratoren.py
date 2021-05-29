#!/usr/bin/env python


def jungen():
    yield "Phillip"
    yield "Sven"


def maedchen():
    yield "Carina"
    yield "Lina"


def namen(auch_jungen=True):
    yield from maedchen()
    if auch_jungen:
        yield from jungen()


if __name__ == "__main__":
    print("namen():     ", list(namen()))
    print("namen(False):", list(namen(False)))

