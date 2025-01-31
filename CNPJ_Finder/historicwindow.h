#ifndef HISTORICWINDOW_H
#define HISTORICWINDOW_H

#include <QDockWidget>
#include <QStringList>
#include <QStringListModel>

namespace Ui {
class HistoricWindow;
}

class HistoricWindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit HistoricWindow(QWidget *parent = nullptr);
    ~HistoricWindow();

    void historic_list_setup(QString CNPJ, QString social_name, QString fake_name);

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::HistoricWindow *ui;
    QStringListModel *historic_listView_model = new QStringListModel(this);
    QStringList historic_window_stringList;
};

#endif // HISTORICWINDOW_H
