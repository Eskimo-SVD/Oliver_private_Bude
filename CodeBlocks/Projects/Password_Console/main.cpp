#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include "QMessageBox"
#include "string"
#include "QVector"

#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::generate_Key);

}




void MainWindow::generate_Key()
{
    QVector<QString> Keys;
    int number = ui->spinBox->value();

    QString generate_password = "";




    ui->lineEdit->clear();

    if (ui->checkBox_5->checkState() == 2)
    {
        QVector<QString> Key_Change;
        Key_Change << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "I" << "J" << "K" << "L" << "M" << "N" << "O" << "P" << "Q" << "R" << "S" << "T" << "U" << "V" << "W" << "X" << "Y" << "Z";
        for(int i = 0; i < Key_Change.size(); i++)
        {
            Keys.append(Key_Change[i]);
        }

    }
    if (ui->checkBox_5->checkState() == 2)
    {
        QVector<QString> Key_Change;
        Key_Change << "a" << "b" << "c" << "d" << "e" << "f" << "g" << "h" << "i" << "j" << "k" << "l" << "m" << "n" << "o" << "p" << "q" << "r" << "s" << "t" << "u" << "v" << "w" << "x" << "y" << "z";
        for(int i = 0; i < Key_Change.size(); i++)
        {
            Keys.append(Key_Change[i]);
        }
    }
    if (ui->checkBox_5->checkState() == 2)
    {
        QVector<QString> Key_Change;
        Key_Change << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0";
        for(int i = 0; i < Key_Change.size(); i++)
        {
            Keys.append(Key_Change[i]);
        }
    }
    if (ui->checkBox_5->checkState() == 2)
    {
        QVector<QString> Key_Change;
        Key_Change << "ä" << "ü" << "ö"<< "Ä" << "Ü" << "Ö" << "ä" << "ü" << "ö"<< "Ä" << "Ü" << "Ö"<< "ä" << "ü" << "ö" << "Ä" << "Ü" << "Ö" << "ä" << "ü" << "ö"<< "Ä" << "Ü" << "Ö";
        for(int i = 0; i < Key_Change.size(); i++)
        {
            Keys.append(Key_Change[i]);
        }
    }
    if (ui->checkBox_5->checkState() == 2)
    {
        QVector<QString> Key_Change;
        Key_Change << "!" << "§" << "$" << "%" << "&" << "/" << "(" << ")" << "=" << "?" << "!" << "§" << "$" << "%" << "&" << "/" << "(" << ")" << "=" << "?" << "$" << "%" << "&" << "/" << "(" << ")" << "=" << "?";
        for(int i = 0; i < Key_Change.size(); i++)
        {
            Keys.append(Key_Change[i]);
        }
    }
    if(ui->checkBox->checkState() == 0 && ui->checkBox_2->checkState() == 0 && ui->checkBox_3->checkState() == 0 && ui->checkBox_4->checkState() == 0 && ui->checkBox_5->checkState() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Please Setup the Settings!");
        msgBox.exec();
    }

    for(int d = 0; d < number; d++)
    {
        generate_password = generate_password + Keys.at(rand() % Keys.size() + 1);
        ui->lineEdit->setText(generate_password);
    }


}




MainWindow::~MainWindow()
{
    delete ui;
}

