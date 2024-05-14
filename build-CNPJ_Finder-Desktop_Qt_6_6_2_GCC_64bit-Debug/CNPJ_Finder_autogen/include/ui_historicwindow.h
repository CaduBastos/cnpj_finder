/********************************************************************************
** Form generated from reading UI file 'historicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICWINDOW_H
#define UI_HISTORICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoricWindow
{
public:
    QListView *listView_historic;
    QLabel *label_historic_list_title;

    void setupUi(QWidget *HistoricWindow)
    {
        if (HistoricWindow->objectName().isEmpty())
            HistoricWindow->setObjectName("HistoricWindow");
        HistoricWindow->setEnabled(true);
        HistoricWindow->resize(752, 679);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HistoricWindow->sizePolicy().hasHeightForWidth());
        HistoricWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        HistoricWindow->setFont(font);
        HistoricWindow->setWindowOpacity(100.000000000000000);
        HistoricWindow->setAutoFillBackground(true);
        listView_historic = new QListView(HistoricWindow);
        listView_historic->setObjectName("listView_historic");
        listView_historic->setGeometry(QRect(78, 55, 591, 571));
        QFont font1;
        font1.setPointSize(12);
        font1.setKerning(true);
        listView_historic->setFont(font1);
        listView_historic->setEditTriggers(QAbstractItemView::AllEditTriggers);
        listView_historic->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView_historic->setItemAlignment(Qt::AlignLeading);
        label_historic_list_title = new QLabel(HistoricWindow);
        label_historic_list_title->setObjectName("label_historic_list_title");
        label_historic_list_title->setGeometry(QRect(90, 28, 150, 17));

        retranslateUi(HistoricWindow);

        QMetaObject::connectSlotsByName(HistoricWindow);
    } // setupUi

    void retranslateUi(QWidget *HistoricWindow)
    {
        HistoricWindow->setWindowTitle(QString());
        label_historic_list_title->setText(QCoreApplication::translate("HistoricWindow", "Hist\303\263rico de consultas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoricWindow: public Ui_HistoricWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICWINDOW_H
