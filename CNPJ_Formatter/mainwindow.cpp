#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <string>
#include <QString>
#include <QRegularExpression>
#include <QMessageBox>
#include <QClipboard>
#include <QPlainTextEdit>

bool CNPJvalidate(QString CNPJ);
void showMessage();
QString CNPJformat_dots(QString cnpj);
QString CNPJformat_astrk(QString cnpj);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_cp_dots_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_dots->text());
}

void MainWindow::on_pushButton_cp_astrk_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_astrk->text());
}

void MainWindow::on_lineEdit_input_editingFinished()
{
    QString data;
    data = (ui->lineEdit_input->text());    //Catch and store the text inserted

    if(CNPJvalidate(data)){

        data = CNPJformat_dots(data);       //Format data inserted to pattern xx.xxx.xxx/xxxx-xx
        ui->lineEdit_output_dots->setText(data);
        ui->plainTextEdit_history->appendPlainText(data + "\n");       //Append to the history the data inserted

        data = CNPJformat_astrk(data);      //Format data inserted to pattern xx*xxx*xxx*xxxx*xx
        ui->lineEdit_output_astrk->setText(data);
    }
    else showMessage();
}

QString CNPJformat_dots(QString cnpj){

    cnpj = cnpj.trimmed();                  //Remove the blank characters at the beginning and the end of string
    if(cnpj.size()<18){
        cnpj.resize(18);                    //Check if cnpj was inserted with separators characteres. if not, resize the string

        cnpj[17]=cnpj[13];                  //Move characters to the right position //-xx
        cnpj[16]=cnpj[12];

        cnpj[14]=cnpj[11];                  ///xxxx-
        cnpj[13]=cnpj[10];
        cnpj[12]=cnpj[9];
        cnpj[11]=cnpj[8];

        cnpj[9]=cnpj[7];                    //.xxx/
        cnpj[8]=cnpj[6];
        cnpj[7]=cnpj[5];

        cnpj[5]=cnpj[4];                    //.xxx.
        cnpj[4]=cnpj[3];
        cnpj[3]=cnpj[2];                    //xx. don't need to be moved
    }
    //add the separator characters
    cnpj[2]=QChar('.');
    cnpj[6]=QChar('.');
    cnpj[10]=QChar('/');
    cnpj[15]=QChar('-');

    return cnpj;
}

QString CNPJformat_astrk(QString cnpj){

    cnpj[2]=QChar('*');
    cnpj[6]=QChar('*');
    cnpj[10]=QChar('*');
    cnpj[15]=QChar('*');

    return cnpj;
}

bool CNPJvalidate(QString cnpj){
    // Remove not number characters of CNPJ
    cnpj.remove(QRegularExpression("[^0-9]"));

    // Check if CNPJ has 14 digits
    if (cnpj.length() != 14)
        return false;

    // Calculate the verified digits
    int digitos[14];
    for (int i = 0; i < 14; ++i) {
        digitos[i] = cnpj.at(i).digitValue();
    }

    int soma = 0;
    int peso = 5;
    for (int i = 0; i < 12; ++i) {
        soma += digitos[i] * peso;
        peso = (peso == 2) ? 9 : peso - 1;
    }

    int digito1 = (soma % 11 < 2) ? 0 : (11 - (soma % 11));

    soma = 0;
    peso = 6;
    for (int i = 0; i < 13; ++i) {
        soma += digitos[i] * peso;
        peso = (peso == 2) ? 9 : peso - 1;
    }

    int digito2 = (soma % 11 < 2) ? 0 : (11 - (soma % 11));

    // Check if the calculated digits match the verified digits
    return (digitos[12] == digito1 && digitos[13] == digito2);
}

void showMessage() {

    QMessageBox::warning(nullptr, "ERRO!", "CNPJ inválido!");
}

void MainWindow::on_pushButton_cls_input_clicked(bool checked)
{
    ui->lineEdit_input->clear();
    ui->lineEdit_output_dots->clear();
    ui->lineEdit_output_astrk->clear();
}

