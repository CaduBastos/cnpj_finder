#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "historicwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lineEdit_input_editingFinished();
    void on_pushButton_cls_input_clicked(bool checked);
    void on_toolButton_cp_dots_clicked(bool checked);
    void on_toolButton_cp_astrk_clicked(bool checked);
    void on_toolButton_cp_cep_clicked(bool checked);
    void on_toolButton_cp_street_clicked(bool checked);
    void on_toolButton_cp_neighborhood_clicked(bool checked);
    void on_toolButton_cp_city_clicked(bool checked);
    void on_toolButton_cp_email_clicked(bool checked);
    void on_toolButton_cp_phone_clicked(bool checked);
    void on_toolButton_cp_social_name_clicked(bool checked);
    void on_toolButton_cp_fake_name_clicked(bool checked);

    void on_actionHist_rico_triggered(bool checked);


private:
    Ui::MainWindow *ui;
    HistoricWindow *historicwindow;
    QStandardItemModel *qsa_table_model; //model data of qsa_table
};
#endif // MAINWINDOW_H
