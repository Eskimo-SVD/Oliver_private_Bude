#!/usr/bin/env python

import sys
from PySide2 import QtWidgets, QtCore
from hauptdialog import Ui_Hauptdialog


class MeinDialog(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.ui = Ui_Hauptdialog()
        self.ui.setupUi(self)

        # Slots einrichten
        self.ui.buttonOK.clicked.connect(self.onOK)
        self.ui.buttonAbbrechen.clicked.connect(self.onAbbrechen)

    def onOK(self):
        # Daten auslesen
        print("Vorname: {}".format(self.ui.vorname.text()))
        print("Nachname: {}".format(self.ui.nachname.text()))
        print("Adresse: {}".format(self.ui.adresse.toPlainText()))
        
        datum = self.ui.geburtsdatum.date().toString("dd.MM.yyyy")
        print("Geburtsdatum: {}".format(datum))
        
        if self.ui.agb.checkState():
            print("AGBs akzeptiert")
        if self.ui.katalog.checkState():
            print("Katalog bestellt")
            
        self.close()

    def onAbbrechen(self):
        print("Schade")
        self.close()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    dialog = MeinDialog()
    dialog.show()
    sys.exit(app.exec_())

