#!/usr/bin/env python

import sys
from PySide2 import QtWidgets
from hauptdialog import Ui_Hauptdialog


class MeinDialog(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.ui = Ui_Hauptdialog()
        self.ui.setupUi(self)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    dialog = MeinDialog()
    dialog.show()
    sys.exit(app.exec_())

