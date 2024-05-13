#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "historicwindow.h"
#include "ui_historicwindow.h"

#include <QApplication>
#include <QRegularExpression>
#include <QMessageBox>
#include <QClipboard>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QListWidget>

#include <QTableView>
#include <QHeaderView>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

bool CNPJvalidate(QString CNPJ);
void showMessage(QString type, QString message);

QString CNPJformat_dots(QString cnpj);
QString CNPJformat_astrk(QString cnpj);

QNetworkAccessManager netmanager;         //Define a network manager object

HistoricWindow *historicwindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->statusbar->showMessage("Developed by Cadu Bastos");

    //Configure the tableView_qsa for qsa data
    qsa_table_model = new QStandardItemModel(0, 3, this);
    qsa_table_model->setHorizontalHeaderLabels({"Nome", "Qualificação", "País de origem"});
    ui->tableView_qsa->setModel(qsa_table_model);

    historicwindow = new HistoricWindow(this);
    historicwindow->close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete historicwindow;
}

void MainWindow::on_lineEdit_input_editingFinished()
{
    QString data;

    data = (ui->lineEdit_input->text());    //Catch and store the text inserted

    if(CNPJvalidate(data)){

        data = data.remove(QRegularExpression("[^0-9]"));
        data = CNPJformat_dots(data);       //Format data inserted to pattern xx.xxx.xxx/xxxx-xx
        ui->lineEdit_output_dots->setText(data);

        data = CNPJformat_astrk(data);      //Format data inserted to pattern xx*xxx*xxx*xxxx*xx
        ui->lineEdit_output_astrk->setText(data);

        //Format the url with cnpj inserted to send http get
        QUrl url("https://receitaws.com.br/v1/cnpj/" + data.remove(QRegularExpression("[^0-9]")));
        QNetworkRequest request(url);
        ui->statusbar->showMessage("Carregando...");

        QNetworkReply *reply = netmanager.get(request);

        //Wait for the reply and response
        QEventLoop response_loop;
        QObject::connect(reply, &QNetworkReply::finished, &response_loop, &QEventLoop::quit);
        response_loop.exec();

        //Check if http request was succesful
        if(reply->error()==QNetworkReply::NoError){

            ui->statusbar->clearMessage();

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

            //Print the QSA informations
            QJsonArray qsa_array = jsonObj.value("qsa").toArray();
            foreach(const QJsonValue &qsa_value, qsa_array){

                QString name = qsa_value.toObject().value("nome").toString();
                QString qual = qsa_value.toObject().value("qual").toString();
                QString country = qsa_value.toObject().value("pais_origem").toString();

                QList<QStandardItem*> row_data = {
                    new QStandardItem(name),
                    new QStandardItem(qual),
                    new QStandardItem(country)};

                qsa_table_model->appendRow(row_data);
            }
            ui->tableView_qsa->resizeColumnsToContents();
            ui->tableView_qsa->update();

            //entering search data to history
            historicwindow->historic_list_setup(CNPJformat_dots(data), jsonObj.value("nome").toString(), jsonObj.value("fantasia").toString());
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
    ui->lineEdit_output_social_name->clear();
    ui->lineEdit_output_fake_name->clear();
    ui->label_type->setText(" ");
    ui->label_last_update->setText(" ");
    ui->label_status->setText(" ");
    ui->label_status_2->setText(" ");
    ui->label_size->setText(" ");
    ui->lineEdit_output_email->clear();
    ui->lineEdit_output_phone->clear();
    ui->lineEdit_output_cep->clear();
    ui->lineEdit_output_street->clear();
    ui->lineEdit_output_neighborhood->clear();
    ui->lineEdit_output_city->clear();
    ui->label_uf->setText(" ");
    ui->label_number->setText(" ");
    qsa_table_model->removeRows(0, qsa_table_model->rowCount());
    ui->tableView_qsa->update();
}

QString CNPJformat_dots(QString cnpj){

    cnpj.remove(QRegularExpression("[^0-9]"));  //Remove not numbers characters of the string
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

void MainWindow::on_toolButton_cp_cep_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_cep->text());
}

void MainWindow::on_toolButton_cp_street_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_street->text());
}

void MainWindow::on_toolButton_cp_neighborhood_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_neighborhood->text());
}

void MainWindow::on_toolButton_cp_city_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_city->text());
}

void MainWindow::on_toolButton_cp_email_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_email->text());
}

void MainWindow::on_toolButton_cp_phone_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_phone->text());
}

void MainWindow::on_toolButton_cp_social_name_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_social_name->text());
}

void MainWindow::on_toolButton_cp_fake_name_clicked(bool checked)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit_output_fake_name->text());
}

void MainWindow::on_actionHist_rico_triggered(bool checked)
{
    int mainWindowHeight = this->height();
    int mainWindowWidht = this->width();
    historicwindow->setGeometry(0, 20, mainWindowWidht, mainWindowHeight-20);
    historicwindow->show();
}

