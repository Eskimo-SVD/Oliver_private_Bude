#!/usr/bin/env python

from PySide2 import QtWidgets, QtGui, QtCore
import sys


class MeinWidget(QtWidgets.QWidget):
    def __init__(self, parent=None): 
        super().__init__(parent)
        self.pen = QtGui.QPen(QtGui.QColor(0,0,0)) 
        self.pen.setWidth(3) 
        self.brush = QtGui.QBrush(QtGui.QColor(255,255,255,0))

        self.painterPath = QtGui.QPainterPath()
        self.painterPath.moveTo(10,10)
        self.painterPath.lineTo(10,140)
        self.painterPath.lineTo(100,140)
        self.painterPath.cubicTo(140,140, 140,10, 10,10)
        
    def paintEvent(self, event): 
        painter = QtGui.QPainter(self)
        painter.setRenderHints(QtGui.QPainter.Antialiasing)
        
        painter.setPen(self.pen) 
        painter.setBrush(self.brush)

        transformation = QtGui.QTransform()
        for i in range(5):
            painter.setTransform(transformation)
            painter.drawPath(self.painterPath)
            
            transformation.translate(70, 0)
            transformation.scale(0.6, 0.6)
            transformation.rotate(20)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    widget = MeinWidget()
    widget.resize(150, 150)
    widget.show()
    sys.exit(app.exec_())
 
