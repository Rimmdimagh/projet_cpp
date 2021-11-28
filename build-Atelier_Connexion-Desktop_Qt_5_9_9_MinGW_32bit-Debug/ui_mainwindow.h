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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label_11;
    QLabel *label_5;
    QLineEdit *id;
    QLineEdit *reference;
    QLineEdit *mail;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *j;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *nom;
    QLabel *label_6;
    QPushButton *pushButtonAjouter;
    QDateEdit *miseFab;
    QDateEdit *miseFonc;
    QPushButton *pushButton_3;
    QComboBox *marque;
    QLineEdit *etat;
    QLabel *qnt;
    QLineEdit *quantite_2;
    QWidget *tab_2;
    QTableView *tab_mat;
    QLabel *label_12;
    QLineEdit *id_supp;
    QPushButton *supp;
    QPushButton *modifier;
    QPushButton *recherche;
    QLineEdit *rech;
    QPushButton *stat;
    QWidget *tab_4;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser_2;
    QPushButton *envoi_M;
    QWidget *tab_6;
    QPushButton *sendMail;
    QPushButton *annuler;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label_42;
    QLineEdit *server;
    QLabel *label_43;
    QLineEdit *port;
    QLabel *label_44;
    QLineEdit *uname;
    QLabel *label_45;
    QLineEdit *paswd;
    QLabel *label_46;
    QLineEdit *rcpt;
    QLabel *label_47;
    QLineEdit *subject;
    QLabel *label_48;
    QPlainTextEdit *msg;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1160, 615);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1211, 941));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 212, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 85, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 113, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        tabWidget_2->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        tabWidget_2->setFont(font);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget = new QTabWidget(tab_5);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1031, 771));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        tabWidget->setPalette(palette1);
        QFont font1;
        font1.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font1);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 971, 541));
        QFont font2;
        font2.setFamily(QStringLiteral("Sitka"));
        font2.setPointSize(12);
        font2.setStyleStrategy(QFont::PreferDefault);
        groupBox->setFont(font2);
        groupBox->setFocusPolicy(Qt::NoFocus);
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(690, 150, 161, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Sitka"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_11->setFont(font3);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 101, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Sitka Display"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferDefault);
        label_5->setFont(font4);
        id = new QLineEdit(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(130, 59, 241, 31));
        reference = new QLineEdit(groupBox);
        reference->setObjectName(QStringLiteral("reference"));
        reference->setGeometry(QRect(130, 170, 241, 31));
        mail = new QLineEdit(groupBox);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(460, 390, 261, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(680, 50, 271, 16));
        label_10->setFont(font3);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 220, 81, 51));
        label_7->setFont(font3);
        j = new QLabel(groupBox);
        j->setObjectName(QStringLiteral("j"));
        j->setGeometry(QRect(10, 280, 141, 51));
        j->setFont(font3);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 91, 41));
        label_4->setFont(font3);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(320, 390, 181, 16));
        label_9->setFont(font3);
        nom = new QLineEdit(groupBox);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(130, 119, 241, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 111, 31));
        label_6->setFont(font3);
        pushButtonAjouter = new QPushButton(groupBox);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(720, 430, 221, 28));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(170, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(255, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(212, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(85, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(113, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(212, 127, 127, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        pushButtonAjouter->setPalette(palette2);
        miseFab = new QDateEdit(groupBox);
        miseFab->setObjectName(QStringLiteral("miseFab"));
        miseFab->setGeometry(QRect(680, 90, 191, 22));
        miseFab->setAlignment(Qt::AlignCenter);
        miseFonc = new QDateEdit(groupBox);
        miseFonc->setObjectName(QStringLiteral("miseFonc"));
        miseFonc->setGeometry(QRect(670, 190, 201, 22));
        miseFonc->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 430, 221, 28));
        marque = new QComboBox(groupBox);
        marque->setObjectName(QStringLiteral("marque"));
        marque->setGeometry(QRect(130, 220, 241, 41));
        marque->setInputMethodHints(Qt::ImhNone);
        marque->setIconSize(QSize(50, 50));
        marque->setDuplicatesEnabled(false);
        etat = new QLineEdit(groupBox);
        etat->setObjectName(QStringLiteral("etat"));
        etat->setGeometry(QRect(170, 300, 113, 20));
        qnt = new QLabel(groupBox);
        qnt->setObjectName(QStringLiteral("qnt"));
        qnt->setGeometry(QRect(10, 360, 61, 16));
        quantite_2 = new QLineEdit(groupBox);
        quantite_2->setObjectName(QStringLiteral("quantite_2"));
        quantite_2->setGeometry(QRect(80, 360, 31, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_mat = new QTableView(tab_2);
        tab_mat->setObjectName(QStringLiteral("tab_mat"));
        tab_mat->setGeometry(QRect(0, 60, 1101, 191));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(390, 320, 111, 20));
        id_supp = new QLineEdit(tab_2);
        id_supp->setObjectName(QStringLiteral("id_supp"));
        id_supp->setGeometry(QRect(480, 320, 321, 22));
        supp = new QPushButton(tab_2);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(60, 320, 251, 28));
        modifier = new QPushButton(tab_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(60, 370, 251, 28));
        recherche = new QPushButton(tab_2);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(250, 10, 93, 28));
        rech = new QLineEdit(tab_2);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(360, 10, 221, 31));
        stat = new QPushButton(tab_2);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(60, 420, 251, 23));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 80, 56, 16));
        label_3->setFont(font4);
        lineEdit_2 = new QLineEdit(tab_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 70, 381, 31));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(180, 150, 61, 16));
        label_13->setFont(font4);
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 240, 71, 16));
        label_14->setFont(font4);
        lineEdit_3 = new QLineEdit(tab_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(230, 140, 391, 41));
        textBrowser_2 = new QTextBrowser(tab_4);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(240, 240, 391, 192));
        envoi_M = new QPushButton(tab_4);
        envoi_M->setObjectName(QStringLiteral("envoi_M"));
        envoi_M->setGeometry(QRect(700, 110, 241, 28));
        tabWidget->addTab(tab_4, QString());
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        sendMail = new QPushButton(tab_6);
        sendMail->setObjectName(QStringLiteral("sendMail"));
        sendMail->setGeometry(QRect(640, 60, 181, 51));
        sendMail->setFont(font);
        annuler = new QPushButton(tab_6);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setGeometry(QRect(640, 150, 181, 51));
        annuler->setFont(font);
        layoutWidget_2 = new QWidget(tab_6);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 591, 368));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setVerticalSpacing(9);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_42 = new QLabel(layoutWidget_2);
        label_42->setObjectName(QStringLiteral("label_42"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_42);

        server = new QLineEdit(layoutWidget_2);
        server->setObjectName(QStringLiteral("server"));

        formLayout->setWidget(0, QFormLayout::FieldRole, server);

        label_43 = new QLabel(layoutWidget_2);
        label_43->setObjectName(QStringLiteral("label_43"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_43);

        port = new QLineEdit(layoutWidget_2);
        port->setObjectName(QStringLiteral("port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port);

        label_44 = new QLabel(layoutWidget_2);
        label_44->setObjectName(QStringLiteral("label_44"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_44);

        uname = new QLineEdit(layoutWidget_2);
        uname->setObjectName(QStringLiteral("uname"));

        formLayout->setWidget(2, QFormLayout::FieldRole, uname);

        label_45 = new QLabel(layoutWidget_2);
        label_45->setObjectName(QStringLiteral("label_45"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_45);

        paswd = new QLineEdit(layoutWidget_2);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, paswd);

        label_46 = new QLabel(layoutWidget_2);
        label_46->setObjectName(QStringLiteral("label_46"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_46);

        rcpt = new QLineEdit(layoutWidget_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));

        formLayout->setWidget(4, QFormLayout::FieldRole, rcpt);

        label_47 = new QLabel(layoutWidget_2);
        label_47->setObjectName(QStringLiteral("label_47"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_47);

        subject = new QLineEdit(layoutWidget_2);
        subject->setObjectName(QStringLiteral("subject"));

        formLayout->setWidget(5, QFormLayout::FieldRole, subject);

        label_48 = new QLabel(layoutWidget_2);
        label_48->setObjectName(QStringLiteral("label_48"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_48);

        msg = new QPlainTextEdit(layoutWidget_2);
        msg->setObjectName(QStringLiteral("msg"));

        formLayout->setWidget(6, QFormLayout::FieldRole, msg);

        tabWidget_2->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1160, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter Matriel", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "MISE_FONCTION", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "MISE_FABRICATION", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "MARQUE", Q_NULLPTR));
        j->setText(QApplication::translate("MainWindow", "ETAT", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "MAIL_FOURNISSEUR", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "REFERENCE", Q_NULLPTR));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        qnt->setText(QApplication::translate("MainWindow", "quantite", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter ", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID Mat\303\251riel", Q_NULLPTR));
        supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        recherche->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Panne", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Cause", Q_NULLPTR));
        envoi_M->setText(QApplication::translate("MainWindow", "Envoyer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "affecter \303\240 reparer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Matriel", Q_NULLPTR));
        sendMail->setText(QApplication::translate("MainWindow", "Envoyer", Q_NULLPTR));
        annuler->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "Smtp-server:", Q_NULLPTR));
        server->setText(QApplication::translate("MainWindow", "smtp.gmail.com", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "Server port:", Q_NULLPTR));
        port->setText(QApplication::translate("MainWindow", "465", Q_NULLPTR));
        label_44->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        paswd->setInputMask(QString());
        label_46->setText(QApplication::translate("MainWindow", "Recipant to:", Q_NULLPTR));
        label_47->setText(QApplication::translate("MainWindow", "Subject:", Q_NULLPTR));
        label_48->setText(QApplication::translate("MainWindow", "Message:", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Mailling", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
