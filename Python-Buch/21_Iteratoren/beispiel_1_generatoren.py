#!/usr/bin/env python


def namen(auch_jungen=True):
    yield "Carina"
    yield "Lina"
    if not auch_jungen:
        return
    yield "Phillip"
    yield "Sven"


if __name__ == "__main__":
    print("namen():     ", list(namen()))
    print("namen(False):", list(namen(False)))

