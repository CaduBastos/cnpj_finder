/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_cp_dots;
    QLabel *label_type_cnpj;
    QLineEdit *lineEdit_input;
    QLineEdit *lineEdit_output_dots;
    QLabel *label_cnpj_formated;
    QLineEdit *lineEdit_output_astrk;
    QLabel *label_cnpj_formated_2;
    QPushButton *pushButton_cp_astrk;
    QPushButton *pushButton_cls_input;
    QPlainTextEdit *plainTextEdit_history;
    QLabel *label_history;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(651, 679);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_cp_dots = new QPushButton(centralwidget);
        pushButton_cp_dots->setObjectName("pushButton_cp_dots");
        pushButton_cp_dots->setGeometry(QRect(410, 90, 71, 25));
        label_type_cnpj = new QLabel(centralwidget);
        label_type_cnpj->setObjectName("label_type_cnpj");
        label_type_cnpj->setGeometry(QRect(130, 50, 91, 20));
        lineEdit_input = new QLineEdit(centralwidget);
        lineEdit_input->setObjectName("lineEdit_input");
        lineEdit_input->setGeometry(QRect(230, 50, 161, 25));
        lineEdit_input->setInputMethodHints(Qt::ImhPreferNumbers);
        lineEdit_output_dots = new QLineEdit(centralwidget);
        lineEdit_output_dots->setObjectName("lineEdit_output_dots");
        lineEdit_output_dots->setGeometry(QRect(230, 90, 161, 25));
        label_cnpj_formated = new QLabel(centralwidget);
        label_cnpj_formated->setObjectName("label_cnpj_formated");
        label_cnpj_formated->setGeometry(QRect(110, 90, 111, 20));
        lineEdit_output_astrk = new QLineEdit(centralwidget);
        lineEdit_output_astrk->setObjectName("lineEdit_output_astrk");
        lineEdit_output_astrk->setGeometry(QRect(230, 130, 161, 25));
        label_cnpj_formated_2 = new QLabel(centralwidget);
        label_cnpj_formated_2->setObjectName("label_cnpj_formated_2");
        label_cnpj_formated_2->setGeometry(QRect(90, 130, 131, 20));
        pushButton_cp_astrk = new QPushButton(centralwidget);
        pushButton_cp_astrk->setObjectName("pushButton_cp_astrk");
        pushButton_cp_astrk->setGeometry(QRect(410, 130, 71, 25));
        pushButton_cls_input = new QPushButton(centralwidget);
        pushButton_cls_input->setObjectName("pushButton_cls_input");
        pushButton_cls_input->setGeometry(QRect(410, 50, 71, 25));
        plainTextEdit_history = new QPlainTextEdit(centralwidget);
        plainTextEdit_history->setObjectName("plainTextEdit_history");
        plainTextEdit_history->setGeometry(QRect(30, 220, 591, 411));
        label_history = new QLabel(centralwidget);
        label_history->setObjectName("label_history");
        label_history->setGeometry(QRect(30, 190, 61, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 651, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CNPJ Formatter", nullptr));
        pushButton_cp_dots->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        label_type_cnpj->setText(QCoreApplication::translate("MainWindow", "Digite o CNPJ", nullptr));
        label_cnpj_formated->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado", nullptr));
        label_cnpj_formated_2->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado(*)", nullptr));
        pushButton_cp_astrk->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        pushButton_cls_input->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        plainTextEdit_history->setDocumentTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
        label_history->setText(QCoreApplication::translate("MainWindow", "Hist\303\263rico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
