from PySide2 import QtWidgets, QtGui, QtCore


class ViewDelegate(QtWidgets.QItemDelegate):
    def __init__(self, parent=None): 
        super().__init__(parent) 
        self.rahmenStift = QtGui.QPen(QtGui.QColor(0,0,0)) 
        self.titelTextStift = QtGui.QPen(QtGui.QColor(255,255,255)) 
        self.titelFarbe = QtGui.QBrush(QtGui.QColor(120,120,120)) 
        self.textStift = QtGui.QPen(QtGui.QColor(0,0,0)) 
        self.titelFarbeAktiv = QtGui.QBrush(QtGui.QColor(0,0,120)) 
        self.hintergrundFarbeAktiv = QtGui.QBrush(QtGui.QColor(230,230,255)) 
        self.titelSchriftart = QtGui.QFont("Helvetica", 10, QtGui.QFont.Bold) 
        self.textSchriftart = QtGui.QFont("Helvetica", 10) 
        self.zeilenHoehe = 15
        self.titelHoehe = 20
        self.abstand = 4
        self.abstandInnen = 2
        self.abstandText = 4
        
    def sizeHint(self, option, index):
        anz = len(index.data())
        return QtCore.QSize(170, self.zeilenHoehe*anz + self.titelHoehe)

    def paint(self, painter, option, index):
        rahmen = option.rect.adjusted(self.abstand, self.abstand, -self.abstand, -self.abstand) 
        rahmenTitel = rahmen.adjusted(self.abstandInnen, self.abstandInnen, -self.abstandInnen+1, 0) 
        rahmenTitel.setHeight(self.titelHoehe) 
        rahmenTitelText = rahmenTitel.adjusted(self.abstandText, 0, self.abstandText, 0) 
        datensatz = index.data()
        
        painter.save()
        if option.state & QtWidgets.QStyle.State_Selected:
            painter.fillRect(rahmen, self.hintergrundFarbeAktiv)
            painter.fillRect(rahmenTitel, self.titelFarbeAktiv)
        else:
            painter.fillRect(rahmenTitel, self.titelFarbe)
        painter.setPen(self.rahmenStift)
        painter.drawRect(rahmen) 
        
        # Titel schreiben
        painter.setPen(self.titelTextStift) 
        painter.setFont(self.titelSchriftart) 
        painter.drawText(rahmenTitelText, QtCore.Qt.AlignLeft | QtCore.Qt.AlignVCenter, datensatz[0])
                    
        # Adresse schreiben
        painter.setPen(self.textStift) 
        painter.setFont(self.textSchriftart) 
        for i, eintrag in enumerate(datensatz[1:]): 
            painter.drawText(rahmenTitel.x() + self.abstandText, rahmenTitel.bottom() + (i+1)*self.zeilenHoehe, eintrag)
        painter.restore()
        
    def createEditor(self, parent, option, index):
        return QtWidgets.QTextEdit(parent)
            
    def setEditorData(self, editor, index):
        editor.setPlainText("\n".join(index.data()))

    def updateEditorGeometry(self, editor, option, index):
        rahmen = option.rect.adjusted(self.abstand, self.abstand, -self.abstand, -self.abstand) 
        editor.setGeometry(rahmen)
            
    def setModelData(self, editor, model, index):
        model.setData(index, editor.toPlainText().split("\n"))
            
    def eventFilter(self, editor, event):
        if event.type() == QtCore.QEvent.KeyPress and event.key() in (QtCore.Qt.Key_Return, QtCore.Qt.Key_Enter):
            return False
        return QtWidgets.QItemDelegate.eventFilter(self, editor, event)


class View(QtWidgets.QListView):
   def __init__(self, modell, parent=None): 
       super().__init__(parent) 
       self.delegate = ViewDelegate()
       self.setItemDelegate(self.delegate) 
       self.setModel(modell)
       self.setVerticalScrollMode(QtWidgets.QListView.ScrollPerPixel)
