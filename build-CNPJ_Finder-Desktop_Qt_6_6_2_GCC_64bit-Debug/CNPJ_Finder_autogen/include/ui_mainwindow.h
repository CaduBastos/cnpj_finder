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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QToolButton *toolButton_cp_dots;
    QLabel *label_input_cnpj;
    QLineEdit *lineEdit_input;
    QLineEdit *lineEdit_output_dots;
    QLabel *label_cnpj_formated;
    QLineEdit *lineEdit_output_astrk;
    QLabel *label_cnpj_formated_2;
    QToolButton *toolButton_cp_astrk;
    QToolButton *toolButton_cls_input;
    QFrame *line;
    QLineEdit *lineEdit_output_social_name;
    QLabel *label_social_name;
    QLineEdit *lineEdit_output_fake_name;
    QLabel *label_fake_name;
    QLabel *label_type_;
    QLabel *label_type_company_output;
    QLabel *label_email;
    QLineEdit *lineEdit_output_email;
    QLabel *label_phone;
    QLineEdit *lineEdit_output_phone;
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
        toolButton_cp_dots = new QToolButton(centralwidget);
        toolButton_cp_dots->setObjectName("toolButton_cp_dots");
        toolButton_cp_dots->setGeometry(QRect(410, 90, 41, 25));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("edit-copy")));
        toolButton_cp_dots->setIcon(icon);
        label_input_cnpj = new QLabel(centralwidget);
        label_input_cnpj->setObjectName("label_input_cnpj");
        label_input_cnpj->setGeometry(QRect(130, 50, 91, 20));
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
        toolButton_cp_astrk = new QToolButton(centralwidget);
        toolButton_cp_astrk->setObjectName("toolButton_cp_astrk");
        toolButton_cp_astrk->setGeometry(QRect(410, 130, 41, 25));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("edit-paste")));
        toolButton_cp_astrk->setIcon(icon1);
        toolButton_cls_input = new QToolButton(centralwidget);
        toolButton_cls_input->setObjectName("toolButton_cls_input");
        toolButton_cls_input->setGeometry(QRect(410, 50, 41, 25));
        toolButton_cls_input->setIcon(icon);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 172, 631, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit_output_social_name = new QLineEdit(centralwidget);
        lineEdit_output_social_name->setObjectName("lineEdit_output_social_name");
        lineEdit_output_social_name->setGeometry(QRect(160, 220, 441, 25));
        label_social_name = new QLabel(centralwidget);
        label_social_name->setObjectName("label_social_name");
        label_social_name->setGeometry(QRect(70, 221, 81, 20));
        lineEdit_output_fake_name = new QLineEdit(centralwidget);
        lineEdit_output_fake_name->setObjectName("lineEdit_output_fake_name");
        lineEdit_output_fake_name->setGeometry(QRect(160, 260, 441, 25));
        label_fake_name = new QLabel(centralwidget);
        label_fake_name->setObjectName("label_fake_name");
        label_fake_name->setGeometry(QRect(53, 261, 101, 20));
        label_type_ = new QLabel(centralwidget);
        label_type_->setObjectName("label_type_");
        label_type_->setGeometry(QRect(60, 300, 40, 20));
        label_type_company_output = new QLabel(centralwidget);
        label_type_company_output->setObjectName("label_type_company_output");
        label_type_company_output->setEnabled(true);
        label_type_company_output->setGeometry(QRect(100, 300, 50, 20));
        label_email = new QLabel(centralwidget);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(110, 334, 41, 20));
        lineEdit_output_email = new QLineEdit(centralwidget);
        lineEdit_output_email->setObjectName("lineEdit_output_email");
        lineEdit_output_email->setGeometry(QRect(161, 333, 281, 25));
        label_phone = new QLabel(centralwidget);
        label_phone->setObjectName("label_phone");
        label_phone->setGeometry(QRect(91, 371, 61, 20));
        lineEdit_output_phone = new QLineEdit(centralwidget);
        lineEdit_output_phone->setObjectName("lineEdit_output_phone");
        lineEdit_output_phone->setGeometry(QRect(160, 370, 281, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 651, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CNPJ Formatter", nullptr));
        toolButton_cp_dots->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        label_input_cnpj->setText(QCoreApplication::translate("MainWindow", "Digite o CNPJ", nullptr));
        label_cnpj_formated->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado", nullptr));
        label_cnpj_formated_2->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado(*)", nullptr));
        toolButton_cp_astrk->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cls_input->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        label_social_name->setText(QCoreApplication::translate("MainWindow", "Raz\303\243o social", nullptr));
        label_fake_name->setText(QCoreApplication::translate("MainWindow", "Nome fantasia", nullptr));
        label_type_->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
        label_type_company_output->setText(QString());
        label_email->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        lineEdit_output_email->setText(QString());
        label_phone->setText(QCoreApplication::translate("MainWindow", "Telefone", nullptr));
        lineEdit_output_phone->setText(QString());
#if QT_CONFIG(accessibility)
        statusbar->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
