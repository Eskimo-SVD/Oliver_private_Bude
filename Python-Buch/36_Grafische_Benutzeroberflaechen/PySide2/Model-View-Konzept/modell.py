from PySide2 import QtCore


class Modell(QtCore.QAbstractListModel):
    def __init__(self, dateiname, parent=None): 
        super().__init__(parent)
        self.datensatz = []
        
        # Lade Datensatz
        with open(dateiname) as f:
            lst = []
            for zeile in f: 
                if not zeile.strip():
                    self.datensatz.append(lst) 
                    lst = []
                else: 
                    lst.append(zeile.strip())
            if lst: 
                self.datensatz.append(lst) 
            
    def rowCount(self, parent=QtCore.QModelIndex()):
        return len(self.datensatz)
        
    def data(self, index, role=QtCore.Qt.DisplayRole): 
        return self.datensatz[index.row()]
        
    def flags(self, index):
        return QtCore.Qt.ItemIsSelectable | QtCore.Qt.ItemIsEditable | QtCore.Qt.ItemIsEnabled

    def setData(self, index, value, role=QtCore.Qt.EditRole):
        self.datensatz[index.row()] = value
        self.layoutChanged.emit()
        return True

