# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'hauptdialog.ui',
# licensing of 'hauptdialog.ui' applies.
#
# Created: Mon Mar 16 19:52:24 2020
#      by: pyside2-uic  running on PySide2 5.13.2
#
# WARNING! All changes made in this file will be lost!

from PySide2 import QtCore, QtGui, QtWidgets

class Ui_Hauptdialog(object):
    def setupUi(self, Hauptdialog):
        Hauptdialog.setObjectName("Hauptdialog")
        Hauptdialog.resize(331, 399)
        self.verticalLayout = QtWidgets.QVBoxLayout(Hauptdialog)
        self.verticalLayout.setObjectName("verticalLayout")
        self.groupBox = QtWidgets.QGroupBox(Hauptdialog)
        self.groupBox.setObjectName("groupBox")
        self.gridLayout = QtWidgets.QGridLayout(self.groupBox)
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(self.groupBox)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 2, 1)
        self.vorname = QtWidgets.QLineEdit(self.groupBox)
        self.vorname.setObjectName("vorname")
        self.gridLayout.addWidget(self.vorname, 0, 1, 1, 1)
        self.nachname = QtWidgets.QLineEdit(self.groupBox)
        self.nachname.setObjectName("nachname")
        self.gridLayout.addWidget(self.nachname, 1, 1, 2, 1)
        self.label_2 = QtWidgets.QLabel(self.groupBox)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 2, 0, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.groupBox)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 3, 0, 1, 1)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.geburtsdatum = QtWidgets.QDateEdit(self.groupBox)
        self.geburtsdatum.setObjectName("geburtsdatum")
        self.horizontalLayout_2.addWidget(self.geburtsdatum)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem)
        self.gridLayout.addLayout(self.horizontalLayout_2, 3, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(self.groupBox)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 4, 0, 1, 1)
        self.adresse = QtWidgets.QTextEdit(self.groupBox)
        self.adresse.setObjectName("adresse")
        self.gridLayout.addWidget(self.adresse, 4, 1, 1, 1)
        self.verticalLayout.addWidget(self.groupBox)
        self.groupBox_2 = QtWidgets.QGroupBox(Hauptdialog)
        self.groupBox_2.setObjectName("groupBox_2")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.groupBox_2)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.agb = QtWidgets.QCheckBox(self.groupBox_2)
        self.agb.setObjectName("agb")
        self.verticalLayout_2.addWidget(self.agb)
        self.katalog = QtWidgets.QCheckBox(self.groupBox_2)
        self.katalog.setObjectName("katalog")
        self.verticalLayout_2.addWidget(self.katalog)
        self.verticalLayout.addWidget(self.groupBox_2)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem1)
        self.buttonOK = QtWidgets.QPushButton(Hauptdialog)
        self.buttonOK.setDefault(True)
        self.buttonOK.setObjectName("buttonOK")
        self.horizontalLayout.addWidget(self.buttonOK)
        self.buttonAbbrechen = QtWidgets.QPushButton(Hauptdialog)
        self.buttonAbbrechen.setObjectName("buttonAbbrechen")
        self.horizontalLayout.addWidget(self.buttonAbbrechen)
        self.verticalLayout.addLayout(self.horizontalLayout)

        self.retranslateUi(Hauptdialog)
        QtCore.QMetaObject.connectSlotsByName(Hauptdialog)

    def retranslateUi(self, Hauptdialog):
        Hauptdialog.setWindowTitle(QtWidgets.QApplication.translate("Hauptdialog", "Dialog", None, -1))
        self.groupBox.setTitle(QtWidgets.QApplication.translate("Hauptdialog", "Persönliche Daten", None, -1))
        self.label.setText(QtWidgets.QApplication.translate("Hauptdialog", "Vorname", None, -1))
        self.label_2.setText(QtWidgets.QApplication.translate("Hauptdialog", "Nachname", None, -1))
        self.label_3.setText(QtWidgets.QApplication.translate("Hauptdialog", "Geburtsdatum", None, -1))
        self.label_4.setText(QtWidgets.QApplication.translate("Hauptdialog", "Adresse", None, -1))
        self.groupBox_2.setTitle(QtWidgets.QApplication.translate("Hauptdialog", "Weitere Angaben", None, -1))
        self.agb.setText(QtWidgets.QApplication.translate("Hauptdialog", "AGBs gelesen und akzeptiert", None, -1))
        self.katalog.setText(QtWidgets.QApplication.translate("Hauptdialog", "Katalog bestellen", None, -1))
        self.buttonOK.setText(QtWidgets.QApplication.translate("Hauptdialog", "OK", None, -1))
        self.buttonAbbrechen.setText(QtWidgets.QApplication.translate("Hauptdialog", "Abbrechen", None, -1))

