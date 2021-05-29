#!/usr/bin/env python

from PySide2 import QtWidgets
import sys
import modell
import view


if __name__ == "__main__":
    m = modell.Modell("adressbuch.txt")
    app = QtWidgets.QApplication(sys.argv)
    liste = view.View(m)
    liste.resize(200, 500)
    liste.show()
    sys.exit(app.exec_())
