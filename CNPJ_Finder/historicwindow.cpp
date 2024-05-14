#include "historicwindow.h"
#include "ui_historicwindow.h"

#include <QListView>
#include <QStringListModel>

#include <QDateTime>

#include <qdebug.h>

HistoricWindow::HistoricWindow(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::HistoricWindow)
{
    ui->setupUi(this);
}

HistoricWindow::~HistoricWindow()
{
    delete ui;
}

void HistoricWindow::historic_list_setup(QString CNPJ, QString social_name, QString fake_name)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();   //read the current time from PC
    QString formattedDateTime = currentDateTime.toString("dd/MM/yyyy hh:mm:ss");
    historic_window_stringList << "--------------------------------------------------------------------------------------------------------------------------------"
        << "    Data: " + formattedDateTime
        << "    CNPJ: " + CNPJ
        << "    Razão social: " + social_name
        << "    Nome fantasia: " + fake_name + "\n";
    ui->listView_historic->setModel(historic_listView_model);
    historic_listView_model->setStringList(historic_window_stringList);
}
