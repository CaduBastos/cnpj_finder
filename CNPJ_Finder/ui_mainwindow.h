/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDark;
    QAction *actionWhite_2;
    QAction *actionDark_2;
    QAction *actionSobre;
    QAction *actionHist_rico;
    QWidget *centralwidget;
    QFrame *cnpj_fields;
    QLabel *label_input_cnpj;
    QLineEdit *lineEdit_input;
    QLabel *label_cnpj_formated;
    QToolButton *toolButton_cp_astrk;
    QLineEdit *lineEdit_output_dots;
    QLabel *label_cnpj_formated_2;
    QToolButton *toolButton_cp_dots;
    QPushButton *pushButton_cls_input;
    QLineEdit *lineEdit_output_astrk;
    QGroupBox *group_location;
    QLabel *label_number;
    QLineEdit *lineEdit_output_city;
    QLineEdit *lineEdit_output_neighborhood;
    QLabel *label_city;
    QLabel *label_complement;
    QLineEdit *lineEdit_output_complement;
    QLabel *label_street;
    QLabel *label_neighborhood;
    QLineEdit *lineEdit_output_cep;
    QLabel *label_uf;
    QLineEdit *lineEdit_output_street;
    QLabel *label_cep;
    QToolButton *toolButton_cp_cep;
    QToolButton *toolButton_cp_street;
    QToolButton *toolButton_cp_neighborhood;
    QToolButton *toolButton_cp_city;
    QGroupBox *group_contact;
    QLabel *label_phone;
    QLabel *label_email;
    QLineEdit *lineEdit_output_email;
    QLineEdit *lineEdit_output_phone;
    QToolButton *toolButton_cp_email;
    QToolButton *toolButton_cp_phone;
    QGroupBox *company_informations;
    QLabel *label_status;
    QLineEdit *lineEdit_output_social_name;
    QLabel *label_fake_name;
    QLineEdit *lineEdit_output_fake_name;
    QLabel *label_last_update;
    QLabel *label_type;
    QLabel *label_social_name;
    QLabel *label_status_2;
    QLabel *label_size;
    QToolButton *toolButton_cp_social_name;
    QToolButton *toolButton_cp_fake_name;
    QTableView *tableView_qsa;
    QLabel *label_qsa;
    QMenuBar *menubar;
    QMenu *menuConfigura_es;
    QMenu *menuTema;
    QMenu *menuTema_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1197, 679);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName("actionDark");
        actionWhite_2 = new QAction(MainWindow);
        actionWhite_2->setObjectName("actionWhite_2");
        actionDark_2 = new QAction(MainWindow);
        actionDark_2->setObjectName("actionDark_2");
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName("actionSobre");
        actionHist_rico = new QAction(MainWindow);
        actionHist_rico->setObjectName("actionHist_rico");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        cnpj_fields = new QFrame(centralwidget);
        cnpj_fields->setObjectName("cnpj_fields");
        cnpj_fields->setGeometry(QRect(21, 40, 401, 131));
        QFont font;
        font.setItalic(false);
        cnpj_fields->setFont(font);
        cnpj_fields->setFrameShape(QFrame::Box);
        cnpj_fields->setFrameShadow(QFrame::Raised);
        label_input_cnpj = new QLabel(cnpj_fields);
        label_input_cnpj->setObjectName("label_input_cnpj");
        label_input_cnpj->setGeometry(QRect(50, 13, 91, 20));
        lineEdit_input = new QLineEdit(cnpj_fields);
        lineEdit_input->setObjectName("lineEdit_input");
        lineEdit_input->setGeometry(QRect(150, 13, 161, 25));
        lineEdit_input->setInputMethodHints(Qt::ImhPreferNumbers);
        label_cnpj_formated = new QLabel(cnpj_fields);
        label_cnpj_formated->setObjectName("label_cnpj_formated");
        label_cnpj_formated->setGeometry(QRect(30, 53, 111, 20));
        toolButton_cp_astrk = new QToolButton(cnpj_fields);
        toolButton_cp_astrk->setObjectName("toolButton_cp_astrk");
        toolButton_cp_astrk->setGeometry(QRect(320, 93, 41, 25));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("edit-copy")));
        toolButton_cp_astrk->setIcon(icon);
        lineEdit_output_dots = new QLineEdit(cnpj_fields);
        lineEdit_output_dots->setObjectName("lineEdit_output_dots");
        lineEdit_output_dots->setGeometry(QRect(150, 53, 161, 25));
        label_cnpj_formated_2 = new QLabel(cnpj_fields);
        label_cnpj_formated_2->setObjectName("label_cnpj_formated_2");
        label_cnpj_formated_2->setGeometry(QRect(10, 93, 131, 20));
        toolButton_cp_dots = new QToolButton(cnpj_fields);
        toolButton_cp_dots->setObjectName("toolButton_cp_dots");
        toolButton_cp_dots->setGeometry(QRect(320, 53, 41, 25));
        toolButton_cp_dots->setIcon(icon);
        pushButton_cls_input = new QPushButton(cnpj_fields);
        pushButton_cls_input->setObjectName("pushButton_cls_input");
        pushButton_cls_input->setGeometry(QRect(320, 13, 71, 25));
        lineEdit_output_astrk = new QLineEdit(cnpj_fields);
        lineEdit_output_astrk->setObjectName("lineEdit_output_astrk");
        lineEdit_output_astrk->setGeometry(QRect(150, 93, 161, 25));
        group_location = new QGroupBox(centralwidget);
        group_location->setObjectName("group_location");
        group_location->setGeometry(QRect(21, 230, 501, 271));
        QFont font1;
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setKerning(true);
        group_location->setFont(font1);
        group_location->setMouseTracking(false);
        group_location->setAutoFillBackground(false);
        group_location->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        group_location->setFlat(false);
        group_location->setCheckable(false);
        label_number = new QLabel(group_location);
        label_number->setObjectName("label_number");
        label_number->setGeometry(QRect(220, 197, 131, 20));
        lineEdit_output_city = new QLineEdit(group_location);
        lineEdit_output_city->setObjectName("lineEdit_output_city");
        lineEdit_output_city->setGeometry(QRect(120, 157, 281, 25));
        lineEdit_output_neighborhood = new QLineEdit(group_location);
        lineEdit_output_neighborhood->setObjectName("lineEdit_output_neighborhood");
        lineEdit_output_neighborhood->setGeometry(QRect(121, 117, 251, 25));
        label_city = new QLabel(group_location);
        label_city->setObjectName("label_city");
        label_city->setGeometry(QRect(43, 157, 71, 20));
        label_complement = new QLabel(group_location);
        label_complement->setObjectName("label_complement");
        label_complement->setGeometry(QRect(12, 227, 101, 20));
        lineEdit_output_complement = new QLineEdit(group_location);
        lineEdit_output_complement->setObjectName("lineEdit_output_complement");
        lineEdit_output_complement->setGeometry(QRect(120, 227, 321, 25));
        label_street = new QLabel(group_location);
        label_street->setObjectName("label_street");
        label_street->setGeometry(QRect(30, 77, 81, 20));
        label_neighborhood = new QLabel(group_location);
        label_neighborhood->setObjectName("label_neighborhood");
        label_neighborhood->setGeometry(QRect(67, 118, 41, 20));
        lineEdit_output_cep = new QLineEdit(group_location);
        lineEdit_output_cep->setObjectName("lineEdit_output_cep");
        lineEdit_output_cep->setGeometry(QRect(121, 40, 161, 25));
        label_uf = new QLabel(group_location);
        label_uf->setObjectName("label_uf");
        label_uf->setGeometry(QRect(70, 197, 51, 20));
        lineEdit_output_street = new QLineEdit(group_location);
        lineEdit_output_street->setObjectName("lineEdit_output_street");
        lineEdit_output_street->setGeometry(QRect(120, 77, 321, 25));
        label_cep = new QLabel(group_location);
        label_cep->setObjectName("label_cep");
        label_cep->setGeometry(QRect(80, 41, 31, 20));
        toolButton_cp_cep = new QToolButton(group_location);
        toolButton_cp_cep->setObjectName("toolButton_cp_cep");
        toolButton_cp_cep->setGeometry(QRect(291, 40, 41, 25));
        toolButton_cp_cep->setIcon(icon);
        toolButton_cp_street = new QToolButton(group_location);
        toolButton_cp_street->setObjectName("toolButton_cp_street");
        toolButton_cp_street->setGeometry(QRect(450, 77, 41, 25));
        toolButton_cp_street->setIcon(icon);
        toolButton_cp_neighborhood = new QToolButton(group_location);
        toolButton_cp_neighborhood->setObjectName("toolButton_cp_neighborhood");
        toolButton_cp_neighborhood->setGeometry(QRect(381, 117, 41, 25));
        toolButton_cp_neighborhood->setIcon(icon);
        toolButton_cp_city = new QToolButton(group_location);
        toolButton_cp_city->setObjectName("toolButton_cp_city");
        toolButton_cp_city->setGeometry(QRect(410, 158, 41, 25));
        toolButton_cp_city->setIcon(icon);
        group_contact = new QGroupBox(centralwidget);
        group_contact->setObjectName("group_contact");
        group_contact->setGeometry(QRect(550, 230, 520, 111));
        group_contact->setAutoFillBackground(false);
        group_contact->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        group_contact->setFlat(false);
        group_contact->setCheckable(false);
        label_phone = new QLabel(group_contact);
        label_phone->setObjectName("label_phone");
        label_phone->setGeometry(QRect(10, 70, 61, 20));
        label_email = new QLabel(group_contact);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(30, 34, 41, 20));
        lineEdit_output_email = new QLineEdit(group_contact);
        lineEdit_output_email->setObjectName("lineEdit_output_email");
        lineEdit_output_email->setGeometry(QRect(81, 33, 361, 25));
        lineEdit_output_phone = new QLineEdit(group_contact);
        lineEdit_output_phone->setObjectName("lineEdit_output_phone");
        lineEdit_output_phone->setGeometry(QRect(80, 70, 291, 25));
        toolButton_cp_email = new QToolButton(group_contact);
        toolButton_cp_email->setObjectName("toolButton_cp_email");
        toolButton_cp_email->setGeometry(QRect(451, 33, 41, 25));
        toolButton_cp_email->setIcon(icon);
        toolButton_cp_phone = new QToolButton(group_contact);
        toolButton_cp_phone->setObjectName("toolButton_cp_phone");
        toolButton_cp_phone->setGeometry(QRect(380, 70, 41, 25));
        toolButton_cp_phone->setIcon(icon);
        company_informations = new QGroupBox(centralwidget);
        company_informations->setObjectName("company_informations");
        company_informations->setGeometry(QRect(431, 20, 741, 201));
        company_informations->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_status = new QLabel(company_informations);
        label_status->setObjectName("label_status");
        label_status->setGeometry(QRect(20, 160, 141, 20));
        lineEdit_output_social_name = new QLineEdit(company_informations);
        lineEdit_output_social_name->setObjectName("lineEdit_output_social_name");
        lineEdit_output_social_name->setGeometry(QRect(120, 40, 551, 25));
        label_fake_name = new QLabel(company_informations);
        label_fake_name->setObjectName("label_fake_name");
        label_fake_name->setGeometry(QRect(13, 81, 101, 20));
        lineEdit_output_fake_name = new QLineEdit(company_informations);
        lineEdit_output_fake_name->setObjectName("lineEdit_output_fake_name");
        lineEdit_output_fake_name->setGeometry(QRect(120, 80, 551, 25));
        label_last_update = new QLabel(company_informations);
        label_last_update->setObjectName("label_last_update");
        label_last_update->setGeometry(QRect(250, 120, 311, 20));
        label_type = new QLabel(company_informations);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(20, 120, 141, 20));
        label_social_name = new QLabel(company_informations);
        label_social_name->setObjectName("label_social_name");
        label_social_name->setGeometry(QRect(30, 41, 81, 20));
        label_status_2 = new QLabel(company_informations);
        label_status_2->setObjectName("label_status_2");
        label_status_2->setGeometry(QRect(251, 160, 141, 20));
        label_size = new QLabel(company_informations);
        label_size->setObjectName("label_size");
        label_size->setGeometry(QRect(490, 160, 181, 20));
        toolButton_cp_social_name = new QToolButton(company_informations);
        toolButton_cp_social_name->setObjectName("toolButton_cp_social_name");
        toolButton_cp_social_name->setGeometry(QRect(680, 40, 41, 25));
        toolButton_cp_social_name->setIcon(icon);
        toolButton_cp_fake_name = new QToolButton(company_informations);
        toolButton_cp_fake_name->setObjectName("toolButton_cp_fake_name");
        toolButton_cp_fake_name->setGeometry(QRect(680, 80, 41, 25));
        toolButton_cp_fake_name->setIcon(icon);
        tableView_qsa = new QTableView(centralwidget);
        tableView_qsa->setObjectName("tableView_qsa");
        tableView_qsa->setGeometry(QRect(548, 380, 621, 251));
        tableView_qsa->setAlternatingRowColors(false);
        tableView_qsa->horizontalHeader()->setDefaultSectionSize(205);
        tableView_qsa->verticalHeader()->setVisible(false);
        tableView_qsa->verticalHeader()->setDefaultSectionSize(57);
        label_qsa = new QLabel(centralwidget);
        label_qsa->setObjectName("label_qsa");
        label_qsa->setGeometry(QRect(551, 360, 31, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1197, 22));
        menuConfigura_es = new QMenu(menubar);
        menuConfigura_es->setObjectName("menuConfigura_es");
        menuTema = new QMenu(menuConfigura_es);
        menuTema->setObjectName("menuTema");
        menuTema_2 = new QMenu(menuTema);
        menuTema_2->setObjectName("menuTema_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        QFont font2;
        font2.setPointSize(10);
        font2.setItalic(true);
        statusbar->setFont(font2);
        statusbar->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConfigura_es->menuAction());
        menuConfigura_es->addAction(menuTema->menuAction());
        menuConfigura_es->addAction(actionHist_rico);
        menuConfigura_es->addAction(actionSobre);
        menuTema->addAction(menuTema_2->menuAction());
        menuTema_2->addAction(actionWhite_2);
        menuTema_2->addAction(actionDark_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CNPJ Formatter 1.0", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionWhite_2->setText(QCoreApplication::translate("MainWindow", "White", nullptr));
        actionDark_2->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionSobre->setText(QCoreApplication::translate("MainWindow", "Sobre", nullptr));
        actionHist_rico->setText(QCoreApplication::translate("MainWindow", "Hist\303\263rico", nullptr));
        label_input_cnpj->setText(QCoreApplication::translate("MainWindow", "Digite o CNPJ", nullptr));
        label_cnpj_formated->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado", nullptr));
        toolButton_cp_astrk->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        label_cnpj_formated_2->setText(QCoreApplication::translate("MainWindow", "CNPJ formatado(*)", nullptr));
        toolButton_cp_dots->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        pushButton_cls_input->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        group_location->setTitle(QCoreApplication::translate("MainWindow", "Localiza\303\247\303\243o", nullptr));
        label_number->setText(QCoreApplication::translate("MainWindow", "N\303\272mero:", nullptr));
        lineEdit_output_city->setText(QString());
        lineEdit_output_neighborhood->setText(QString());
        label_city->setText(QCoreApplication::translate("MainWindow", "Munic\303\255pio", nullptr));
        label_complement->setText(QCoreApplication::translate("MainWindow", "Complemento", nullptr));
        lineEdit_output_complement->setText(QString());
        label_street->setText(QCoreApplication::translate("MainWindow", "Logradouro", nullptr));
        label_neighborhood->setText(QCoreApplication::translate("MainWindow", "Bairro", nullptr));
        lineEdit_output_cep->setText(QString());
        label_uf->setText(QCoreApplication::translate("MainWindow", "UF:", nullptr));
        lineEdit_output_street->setText(QString());
        label_cep->setText(QCoreApplication::translate("MainWindow", "CEP", nullptr));
        toolButton_cp_cep->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cp_street->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cp_neighborhood->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cp_city->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        group_contact->setTitle(QCoreApplication::translate("MainWindow", "Contato", nullptr));
        label_phone->setText(QCoreApplication::translate("MainWindow", "Telefone", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        lineEdit_output_email->setText(QString());
        lineEdit_output_phone->setText(QString());
        toolButton_cp_email->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cp_phone->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        company_informations->setTitle(QCoreApplication::translate("MainWindow", "Dados da empresa", nullptr));
        label_status->setText(QCoreApplication::translate("MainWindow", "Situa\303\247\303\243o:", nullptr));
        label_fake_name->setText(QCoreApplication::translate("MainWindow", "Nome fantasia", nullptr));
        label_last_update->setText(QCoreApplication::translate("MainWindow", "\303\232ltima atualiza\303\247\303\243o:", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
        label_social_name->setText(QCoreApplication::translate("MainWindow", "Raz\303\243o social", nullptr));
        label_status_2->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_size->setText(QCoreApplication::translate("MainWindow", "Porte:", nullptr));
        toolButton_cp_social_name->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        toolButton_cp_fake_name->setText(QCoreApplication::translate("MainWindow", "Copiar", nullptr));
        label_qsa->setText(QCoreApplication::translate("MainWindow", "QSA", nullptr));
        menuConfigura_es->setTitle(QCoreApplication::translate("MainWindow", "Arquivo", nullptr));
        menuTema->setTitle(QCoreApplication::translate("MainWindow", "Prefer\303\252ncias", nullptr));
        menuTema_2->setTitle(QCoreApplication::translate("MainWindow", "Tema", nullptr));
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
