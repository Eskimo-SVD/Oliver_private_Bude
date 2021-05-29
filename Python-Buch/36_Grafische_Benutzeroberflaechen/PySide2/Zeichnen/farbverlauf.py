#!/usr/bin/env python

from PySide2 import QtWidgets, QtGui
import sys


class MeinWidget(QtWidgets.QWidget):
    def __init__(self, parent=None): 
        super().__init__(parent)
        self.pen = QtGui.QPen(QtGui.QColor(0,0,0)) 
        self.pen.setWidth(3) 
        self.brush = QtGui.QBrush(QtGui.QLinearGradient(10, 10, 130, 130))
        
    def paintEvent(self, event): 
        painter = QtGui.QPainter(self) 
        painter.setPen(self.pen) 
        painter.setBrush(self.brush) 
        painter.drawRect(10, 10, 130, 130)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    widget = MeinWidget()
    widget.resize(150, 150)
    widget.show()
    sys.exit(app.exec_())
 
