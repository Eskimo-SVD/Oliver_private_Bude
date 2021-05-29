#!/usr/bin/env python

class A1:
    def __init__(self):
        self._X = 100

    def getX(self):
        return self._X

    def setX(self, wert):
        if wert < 0:
            return
        self._X = wert


class A2:
    def __init__(self):
        self.X = 100

    def getX(self):
        print("Getter gerufen")
        return self._X

    def setX(self, wert):
        print("Setter gerufen")
        if wert < 0:
            return
        self._X = wert

    X = property(getX, setX)


if __name__ == "__main__":
    a = A1()
    print(a.getX())
    a.setX(300)
    print(a.getX())
    a.setX(-20)
    print(a.getX())

    print("----------------------------")

    a = A2()
    print(a.X)
    a.X = 300
    print(a.X)
    a.X = -20
    print(a.X)
