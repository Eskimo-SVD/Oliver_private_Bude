#!/usr/bin/env python

from PySide2 import QtWidgets, QtGui, QtCore
import sys


class MeinWidget(QtWidgets.QWidget):
    def __init__(self, parent=None): 
        super().__init__(parent)
        self.grafik = QtGui.QImage("kaffee.png")
        self.ziel = QtCore.QRect(10, 10, 810, 610)
        self.quelle = QtCore.QRect(0, 0, self.grafik.width(), self.grafik.height())
        
    def paintEvent(self, event):
        painter = QtGui.QPainter(self)
        painter.drawImage(self.ziel, self.grafik, self.quelle)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    widget = MeinWidget()
    widget.resize(830, 630)
    widget.show()
    sys.exit(app.exec_())
 
