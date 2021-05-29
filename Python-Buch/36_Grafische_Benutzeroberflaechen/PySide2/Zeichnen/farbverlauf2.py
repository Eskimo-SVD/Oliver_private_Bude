#!/usr/bin/env python

from PySide2 import QtWidgets, QtGui, QtCore
import sys


class MeinWidget(QtWidgets.QWidget):
    def __init__(self, parent=None): 
        super().__init__(parent)
        self.grafik = QtGui.QImage("kaffee.png")
        self.ziel = QtCore.QRect(10, 10, 810, 610)
        self.quelle = QtCore.QRect(0, 0, self.grafik.width(), self.grafik.height())

        self.pen = QtGui.QPen(QtGui.QColor(0,0,0)) 
        self.pen.setWidth(3)

        gradient = QtGui.QLinearGradient(10, 10, 810, 610)
        gradient.setColorAt(0.0, QtGui.QColor(0,0,0,255))
        gradient.setColorAt(1.0, QtGui.QColor(255,255,255,0))
        self.brush = QtGui.QBrush(gradient)
        
    def paintEvent(self, event):
        painter = QtGui.QPainter(self)
        painter.drawImage(self.ziel, self.grafik, self.quelle)
        
        painter.setPen(self.pen) 
        painter.setBrush(self.brush) 
        painter.drawRect(10, 10, 810, 610)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    widget = MeinWidget()
    widget.resize(830, 630)
    widget.show()
    sys.exit(app.exec_())
 
