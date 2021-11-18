/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *CODE_FORMATION;
    QLineEdit *NOM_FOR;
    QLineEdit *NOM_ENCADREUR;
    QLineEdit *TYPE_FOR;
    QLineEdit *DURE_FOR;
    QPushButton *pushButtonAjouter;
    QPushButton *Mod_2;
    QPushButton *rechercher_button_2;
    QPushButton *ImportPDF;
    QPushButton *insererphoto;
    QLabel *lbl_image;
    QWidget *tab_4;
    QTableView *tab_for;
    QLabel *label_18;
    QLineEdit *code_supp;
    QPushButton *supp;
    QPushButton *Mod_4;
    QPushButton *rechercher_button;
    QPushButton *qrcodegen;
    QLabel *qrcodecommande;
    QGroupBox *groupBox;
    QRadioButton *radioButton_croissant;
    QRadioButton *radioButton_dcroissant;
    QPushButton *rechercher_button_22;
    QWidget *tab;
    QPushButton *statsmed;
    QWidget *tab_2;
    QLineEdit *subject;
    QPushButton *reset_3;
    QLineEdit *rcpt;
    QLabel *label;
    QLabel *label_8;
    QPushButton *send_mail;
    QPlainTextEdit *msg;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1047, 603);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1141, 531));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(100, 140, 131, 41));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 100, 131, 21));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(100, 200, 131, 31));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(100, 270, 61, 16));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(100, 330, 141, 16));
        CODE_FORMATION = new QLineEdit(tab_3);
        CODE_FORMATION->setObjectName(QStringLiteral("CODE_FORMATION"));
        CODE_FORMATION->setGeometry(QRect(280, 100, 113, 20));
        NOM_FOR = new QLineEdit(tab_3);
        NOM_FOR->setObjectName(QStringLiteral("NOM_FOR"));
        NOM_FOR->setGeometry(QRect(280, 150, 113, 20));
        NOM_ENCADREUR = new QLineEdit(tab_3);
        NOM_ENCADREUR->setObjectName(QStringLiteral("NOM_ENCADREUR"));
        NOM_ENCADREUR->setGeometry(QRect(280, 210, 113, 20));
        TYPE_FOR = new QLineEdit(tab_3);
        TYPE_FOR->setObjectName(QStringLiteral("TYPE_FOR"));
        TYPE_FOR->setGeometry(QRect(280, 270, 113, 20));
        DURE_FOR = new QLineEdit(tab_3);
        DURE_FOR->setObjectName(QStringLiteral("DURE_FOR"));
        DURE_FOR->setGeometry(QRect(280, 330, 113, 20));
        pushButtonAjouter = new QPushButton(tab_3);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(540, 190, 75, 23));
        Mod_2 = new QPushButton(tab_3);
        Mod_2->setObjectName(QStringLiteral("Mod_2"));
        Mod_2->setGeometry(QRect(540, 150, 75, 23));
        rechercher_button_2 = new QPushButton(tab_3);
        rechercher_button_2->setObjectName(QStringLiteral("rechercher_button_2"));
        rechercher_button_2->setGeometry(QRect(480, 230, 181, 28));
        ImportPDF = new QPushButton(tab_3);
        ImportPDF->setObjectName(QStringLiteral("ImportPDF"));
        ImportPDF->setGeometry(QRect(820, 70, 93, 28));
        ImportPDF->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #dcdcdc;\n"
"background:#535353;\n"
"border: none;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"border: 2px solid ;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"	background-color: rgb(0, 0, 127);\n"
"border: none;\n"
"}\n"
""));
        insererphoto = new QPushButton(tab_3);
        insererphoto->setObjectName(QStringLiteral("insererphoto"));
        insererphoto->setGeometry(QRect(770, 140, 191, 28));
        insererphoto->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #dcdcdc;\n"
"background:#535353;\n"
"border: none;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"border: 2px solid ;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"	background-color: rgb(0, 0, 127);\n"
"border: none;\n"
"}"));
        lbl_image = new QLabel(tab_3);
        lbl_image->setObjectName(QStringLiteral("lbl_image"));
        lbl_image->setGeometry(QRect(770, 230, 181, 181));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_for = new QTableView(tab_4);
        tab_for->setObjectName(QStringLiteral("tab_for"));
        tab_for->setGeometry(QRect(10, 30, 761, 271));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(60, 390, 111, 20));
        code_supp = new QLineEdit(tab_4);
        code_supp->setObjectName(QStringLiteral("code_supp"));
        code_supp->setGeometry(QRect(180, 390, 113, 22));
        supp = new QPushButton(tab_4);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(410, 400, 93, 28));
        Mod_4 = new QPushButton(tab_4);
        Mod_4->setObjectName(QStringLiteral("Mod_4"));
        Mod_4->setGeometry(QRect(410, 360, 93, 28));
        rechercher_button = new QPushButton(tab_4);
        rechercher_button->setObjectName(QStringLiteral("rechercher_button"));
        rechercher_button->setGeometry(QRect(410, 440, 93, 28));
        qrcodegen = new QPushButton(tab_4);
        qrcodegen->setObjectName(QStringLiteral("qrcodegen"));
        qrcodegen->setGeometry(QRect(830, 260, 200, 28));
        qrcodegen->setStyleSheet(QStringLiteral(""));
        qrcodecommande = new QLabel(tab_4);
        qrcodecommande->setObjectName(QStringLiteral("qrcodecommande"));
        qrcodecommande->setEnabled(true);
        qrcodecommande->setGeometry(QRect(830, 60, 200, 200));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qrcodecommande->sizePolicy().hasHeightForWidth());
        qrcodecommande->setSizePolicy(sizePolicy);
        qrcodecommande->setMinimumSize(QSize(200, 200));
        qrcodecommande->setMaximumSize(QSize(200, 200));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(810, 350, 191, 111));
        radioButton_croissant = new QRadioButton(groupBox);
        radioButton_croissant->setObjectName(QStringLiteral("radioButton_croissant"));
        radioButton_croissant->setGeometry(QRect(10, 40, 161, 20));
        radioButton_dcroissant = new QRadioButton(groupBox);
        radioButton_dcroissant->setObjectName(QStringLiteral("radioButton_dcroissant"));
        radioButton_dcroissant->setGeometry(QRect(10, 80, 171, 20));
        rechercher_button_22 = new QPushButton(tab_4);
        rechercher_button_22->setObjectName(QStringLiteral("rechercher_button_22"));
        rechercher_button_22->setGeometry(QRect(110, 440, 181, 28));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        statsmed = new QPushButton(tab);
        statsmed->setObjectName(QStringLiteral("statsmed"));
        statsmed->setGeometry(QRect(770, 430, 181, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        subject = new QLineEdit(tab_2);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(214, 120, 411, 20));
        reset_3 = new QPushButton(tab_2);
        reset_3->setObjectName(QStringLiteral("reset_3"));
        reset_3->setGeometry(QRect(694, 310, 241, 28));
        reset_3->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"background-color: rgb(143, 143, 143);\n"
"border:2px solid #000;\n"
"}\n"
"QPushButton {\n"
"     color: #fff !important;\n"
"text-transform: uppercase;\n"
"text-decoration: none;\n"
"background: #151B54;\n"
"\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }"));
        rcpt = new QLineEdit(tab_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(214, 70, 411, 20));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 70, 61, 20));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 170, 61, 20));
        send_mail = new QPushButton(tab_2);
        send_mail->setObjectName(QStringLiteral("send_mail"));
        send_mail->setGeometry(QRect(694, 240, 241, 28));
        send_mail->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"background-color: rgb(143, 143, 143);\n"
"border:2px solid #000;\n"
"}\n"
"QPushButton {\n"
"     color: #fff !important;\n"
"text-transform: uppercase;\n"
"text-decoration: none;\n"
"background: #151B54;\n"
"\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }"));
        msg = new QPlainTextEdit(tab_2);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(224, 170, 393, 241));
        msg->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid #000;\n"
"}"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 120, 61, 20));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1047, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "nom formation", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "code formation", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "nom encadreur", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "type formation", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "dure formation", Q_NULLPTR));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Mod_2->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        rechercher_button_2->setText(QApplication::translate("MainWindow", "ajouter un code pin ", Q_NULLPTR));
        ImportPDF->setText(QApplication::translate("MainWindow", "Import PDF", Q_NULLPTR));
        insererphoto->setText(QApplication::translate("MainWindow", "inserer photo de formation", Q_NULLPTR));
        lbl_image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Ajouter formation", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "code formation", Q_NULLPTR));
        supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        Mod_4->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        rechercher_button->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        qrcodegen->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer QR Code", Q_NULLPTR));
        qrcodecommande->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Trier  NOM par ordre:", Q_NULLPTR));
        radioButton_croissant->setText(QApplication::translate("MainWindow", "Alphab\303\251tique Croissant", Q_NULLPTR));
        radioButton_dcroissant->setText(QApplication::translate("MainWindow", "Alphab\303\251tique D\303\251croissant", Q_NULLPTR));
        rechercher_button_22->setText(QApplication::translate("MainWindow", "ajouter un code pin ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Afficher formation", Q_NULLPTR));
        statsmed->setText(QApplication::translate("MainWindow", "Appliquer la statistique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        reset_3->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TO", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        send_mail->setText(QApplication::translate("MainWindow", "SEND", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TITLE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "notification", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
