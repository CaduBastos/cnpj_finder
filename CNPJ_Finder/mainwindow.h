#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_action_theme_dark_triggered();
    void on_action_theme_light_triggered();
//    void on_action_about_triggered();

    void on_toolButton_cp_dots_clicked(bool checked);
    void on_toolButton_cp_astrk_clicked(bool checked);
    void on_toolButton_cp_cep_clicked();
    void on_toolButton_cp_cep_clicked(bool checked);
    void on_toolButton_cp_street_clicked(bool checked);
    void on_toolButton_cp_neighborhood_clicked(bool checked);
    void on_toolButton_cp_city_clicked(bool checked);
    void on_toolButton_cp_email_clicked(bool checked);
    void on_toolButton_cp_phone_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
