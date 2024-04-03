#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QRegularExpression>
#include <QMessageBox>
#include <QClipboard>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

#include <QJsonDocument>
#include <QJsonObject>

bool CNPJvalidate(QString CNPJ);
void showMessage(QString type, QString message);

QString CNPJformat_dots(QString cnpj);
QString CNPJformat_astrk(QString cnpj);

QNetworkAccessManager netmanager;         //Define a network manager object

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Developed by Cadu Bastos");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_cp_dots_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_dots->text());
}

void MainWindow::on_toolButton_cp_astrk_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_astrk->text());
}

void MainWindow::on_lineEdit_input_editingFinished()
{
    QString data;

    data = (ui->lineEdit_input->text());    //Catch and store the text inserted

    if(CNPJvalidate(data)){

        data = data.remove(QRegularExpression("[^0-9]"));
        data = CNPJformat_dots(data);       //Format data inserted to pattern xx.xxx.xxx/xxxx-xx
        ui->lineEdit_output_dots->setText(data);

        //ui->plainTextEdit_history->appendPlainText(data + "\n");    //Append to the history the data inserted

        data = CNPJformat_astrk(data);      //Format data inserted to pattern xx*xxx*xxx*xxxx*xx
        ui->lineEdit_output_astrk->setText(data);

        //Format the url with cnpj inserted to send http get
        QUrl url("https://receitaws.com.br/v1/cnpj/" + data.remove(QRegularExpression("[^0-9]")));
        QNetworkRequest request(url);

        QNetworkReply *reply = netmanager.get(request);

        //Wait for the reply and response
        QEventLoop response_loop;
        QObject::connect(reply, &QNetworkReply::finished, &response_loop, &QEventLoop::quit);
        response_loop.exec();

        //Check if http request was succesful
        if(reply->error()==QNetworkReply::NoError){

            QByteArray response = reply->readAll();                     //Get data from reply
            reply->deleteLater();                                       //free memory alocated for network reply

            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);  //Initialize a Json document from http request response data
            QJsonObject jsonObj = jsonDoc.object();                     //Extract the Json object of Json document jsonDoc
            qDebug() << "JSON: " << jsonObj;                            //Print to debug Json file

            //Print the main informations about the company
            ui->lineEdit_output_social_name->setText(jsonObj.value("nome").toString());
            ui->lineEdit_output_fake_name->setText(jsonObj.value("fantasia").toString());
            ui->label_type->setText("Tipo: " + jsonObj.value("tipo").toString());
            ui->label_last_update->setText("Última atualização: " + jsonObj.value("ultima_atualizacao").toString());
            ui->label_status->setText("Situação: " + jsonObj.value("situacao").toString());
            ui->label_status_2->setText("Status: " + jsonObj.value("status").toString());
            ui->label_size->setText("Porte: " + jsonObj.value("porte").toString());

            //Print the contact informations
            ui->lineEdit_output_email->setText(jsonObj.value("email").toString());
            ui->lineEdit_output_phone->setText(jsonObj.value("telefone").toString());

            //Print the location informations about the company
            ui->lineEdit_output_cep->setText(jsonObj.value("cep").toString());
            ui->lineEdit_output_street->setText(jsonObj.value("logradouro").toString());
            ui->lineEdit_output_neighborhood->setText(jsonObj.value("bairro").toString());
            ui->lineEdit_output_city->setText(jsonObj.value("municipio").toString());
            ui->label_uf->setText("UF: " + jsonObj.value("uf").toString());
            ui->label_number->setText("Número: " + jsonObj.value("numero").toString());

        }
        else{
            qDebug() << "Error: " << reply->errorString();

            int http_status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();      //Read and store the http status code returned from http request

            switch(http_status_code){
            case 429:
                qDebug() << "Error: Too many requests - http status code: 429";
                showMessage("critical", "Limite de consultas atingido! Aguarde 1 minuto.");
                break;
            case 504:
                qDebug() << "Error: Timeout - http status code: 504";
                showMessage("critical", "Timeout atingido!");
                break;
            default:
                qDebug() << "Error: Unknow error - http code: unknow";
                showMessage("critical", "Erro desconhecido!");
            }
        }
    }
    else showMessage("critical", "CNPJ inválido");
}

void MainWindow::on_pushButton_cls_input_clicked(bool checked)
{
    ui->lineEdit_input->clear();
    ui->lineEdit_output_dots->clear();
    ui->lineEdit_output_astrk->clear();
}

QString CNPJformat_dots(QString cnpj){

    cnpj.remove(QRegularExpression("[^0-9]"));  //Remove not numbers characters of the string
   // if(cnpj.size()<18){
    cnpj.resize(18);                            //Check if cnpj was inserted with separators characteres. if not, resize the string

    cnpj[17]=cnpj[13];                          //Move characters to the right position //-xx
    cnpj[16]=cnpj[12];

    cnpj[14]=cnpj[11];                          ///xxxx-
    cnpj[13]=cnpj[10];
    cnpj[12]=cnpj[9];
    cnpj[11]=cnpj[8];

    cnpj[9]=cnpj[7];                            //.xxx/
    cnpj[8]=cnpj[6];
    cnpj[7]=cnpj[5];

    cnpj[5]=cnpj[4];                            //.xxx.
    cnpj[4]=cnpj[3];
    cnpj[3]=cnpj[2];                            //xx. don't need to be moved

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

void showMessage(QString type, QString message){

    //NoIcon, Question, Information, Warning, Critical
    if(type == "warning")
        QMessageBox::warning(nullptr, "Alerta", message);
    else if(type == "critical")
        QMessageBox::critical(nullptr, "Erro", message);
    else if(type == "information")
        QMessageBox::information(nullptr, "Info", message);
    else
        QMessageBox::question(nullptr, "", message);
}
/*
void MainWindow::on_action_theme_light_triggered()
{
    mainWindow.setStyleSheet("backgroud-color: white");
}

void MainWindow::on_action_theme_dark_triggered()
{
    MainWindow.setStyleSheet("backgroud-color: grey");
}
*/
