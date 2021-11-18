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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QGroupBox *reset;
    QLabel *label_11;
    QLabel *label_5;
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
    QPushButton *reset_2;
    QComboBox *marque;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *id;
    QWidget *tab_2;
    QTableView *tab_mat;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *supp;
    QPushButton *modifier;
    QPushButton *stat;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLineEdit *id_supp;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *rech;
    QPushButton *recherche;
    QPushButton *reaficher;
    QWidget *tab_3;
    QTextBrowser *hist;
    QWidget *tab_4;
    QLabel *label_3;
    QLineEdit *ID;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *panne;
    QPushButton *envoi_M;
    QPlainTextEdit *cause;
    QWidget *tab_6;
    QPlainTextEdit *msg;
    QPushButton *send_mail;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QPushButton *reset_3;
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
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
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
        tabWidget->setGeometry(QRect(0, 10, 1031, 771));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        tabWidget->setPalette(palette1);
        QFont font1;
        font1.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font1);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        reset = new QGroupBox(tab);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(0, 20, 971, 541));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        reset->setPalette(palette2);
        QFont font2;
        font2.setFamily(QStringLiteral("Sitka"));
        font2.setPointSize(12);
        font2.setStyleStrategy(QFont::PreferAntialias);
        reset->setFont(font2);
        reset->setFocusPolicy(Qt::NoFocus);
        reset->setContextMenuPolicy(Qt::NoContextMenu);
        reset->setLayoutDirection(Qt::LeftToRight);
        reset->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(reset);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(690, 150, 161, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Sitka"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_11->setFont(font3);
        label_5 = new QLabel(reset);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 101, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Sitka Display"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferDefault);
        label_5->setFont(font4);
        reference = new QLineEdit(reset);
        reference->setObjectName(QStringLiteral("reference"));
        reference->setGeometry(QRect(130, 170, 241, 31));
        mail = new QLineEdit(reset);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(540, 290, 261, 31));
        label_10 = new QLabel(reset);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(680, 50, 271, 16));
        label_10->setFont(font3);
        label_7 = new QLabel(reset);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 220, 81, 51));
        label_7->setFont(font3);
        j = new QLabel(reset);
        j->setObjectName(QStringLiteral("j"));
        j->setGeometry(QRect(10, 280, 141, 51));
        j->setFont(font3);
        label_4 = new QLabel(reset);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 91, 41));
        label_4->setFont(font3);
        label_9 = new QLabel(reset);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 300, 181, 16));
        label_9->setFont(font3);
        nom = new QLineEdit(reset);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(130, 119, 241, 31));
        label_6 = new QLabel(reset);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 111, 31));
        label_6->setFont(font3);
        pushButtonAjouter = new QPushButton(reset);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(720, 400, 221, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush6(QColor(170, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        QBrush brush7(QColor(255, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush7);
        QBrush brush8(QColor(212, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush8);
        QBrush brush9(QColor(85, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(113, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush11(QColor(212, 127, 127, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        QBrush brush12(QColor(170, 170, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButtonAjouter->setPalette(palette3);
        miseFab = new QDateEdit(reset);
        miseFab->setObjectName(QStringLiteral("miseFab"));
        miseFab->setGeometry(QRect(680, 90, 191, 22));
        miseFab->setAlignment(Qt::AlignCenter);
        miseFonc = new QDateEdit(reset);
        miseFonc->setObjectName(QStringLiteral("miseFonc"));
        miseFonc->setGeometry(QRect(670, 190, 201, 22));
        miseFonc->setAlignment(Qt::AlignCenter);
        reset_2 = new QPushButton(reset);
        reset_2->setObjectName(QStringLiteral("reset_2"));
        reset_2->setGeometry(QRect(10, 400, 221, 28));
        marque = new QComboBox(reset);
        marque->setObjectName(QStringLiteral("marque"));
        marque->setGeometry(QRect(130, 220, 241, 41));
        marque->setInputMethodHints(Qt::ImhNone);
        marque->setIconSize(QSize(50, 50));
        marque->setDuplicatesEnabled(false);
        radioButton = new QRadioButton(reset);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(130, 300, 83, 18));
        radioButton_2 = new QRadioButton(reset);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(260, 300, 83, 18));
        id = new QLineEdit(reset);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(127, 70, 241, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_mat = new QTableView(tab_2);
        tab_mat->setObjectName(QStringLiteral("tab_mat"));
        tab_mat->setGeometry(QRect(30, 60, 801, 191));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 290, 281, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        supp = new QPushButton(verticalLayoutWidget);
        supp->setObjectName(QStringLiteral("supp"));

        verticalLayout->addWidget(supp);

        modifier = new QPushButton(verticalLayoutWidget);
        modifier->setObjectName(QStringLiteral("modifier"));

        verticalLayout->addWidget(modifier);

        stat = new QPushButton(verticalLayoutWidget);
        stat->setObjectName(QStringLiteral("stat"));

        verticalLayout->addWidget(stat);

        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(310, 290, 131, 71));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(label_12);

        id_supp = new QLineEdit(verticalLayoutWidget_2);
        id_supp->setObjectName(QStringLiteral("id_supp"));

        verticalLayout_2->addWidget(id_supp);

        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(860, 80, 160, 161));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        rech = new QLineEdit(verticalLayoutWidget_3);
        rech->setObjectName(QStringLiteral("rech"));

        verticalLayout_4->addWidget(rech);

        recherche = new QPushButton(verticalLayoutWidget_3);
        recherche->setObjectName(QStringLiteral("recherche"));

        verticalLayout_4->addWidget(recherche);

        reaficher = new QPushButton(verticalLayoutWidget_3);
        reaficher->setObjectName(QStringLiteral("reaficher"));

        verticalLayout_4->addWidget(reaficher);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        hist = new QTextBrowser(tab_3);
        hist->setObjectName(QStringLiteral("hist"));
        hist->setGeometry(QRect(60, 50, 681, 281));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 80, 56, 16));
        label_3->setFont(font4);
        ID = new QLineEdit(tab_4);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(230, 70, 381, 31));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(180, 150, 61, 16));
        label_13->setFont(font4);
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 240, 71, 16));
        label_14->setFont(font4);
        panne = new QLineEdit(tab_4);
        panne->setObjectName(QStringLiteral("panne"));
        panne->setGeometry(QRect(230, 140, 391, 41));
        envoi_M = new QPushButton(tab_4);
        envoi_M->setObjectName(QStringLiteral("envoi_M"));
        envoi_M->setGeometry(QRect(660, 70, 241, 28));
        cause = new QPlainTextEdit(tab_4);
        cause->setObjectName(QStringLiteral("cause"));
        cause->setGeometry(QRect(260, 230, 371, 121));
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        msg = new QPlainTextEdit(tab_6);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(200, 130, 393, 241));
        msg->setStyleSheet(QLatin1String("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid #000;\n"
"}"));
        send_mail = new QPushButton(tab_6);
        send_mail->setObjectName(QStringLiteral("send_mail"));
        send_mail->setGeometry(QRect(670, 200, 241, 28));
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
        label = new QLabel(tab_6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(116, 30, 61, 20));
        label_2 = new QLabel(tab_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(116, 80, 61, 20));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(116, 130, 61, 20));
        rcpt = new QLineEdit(tab_6);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(190, 30, 411, 20));
        subject = new QLineEdit(tab_6);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(190, 80, 411, 20));
        reset_3 = new QPushButton(tab_6);
        reset_3->setObjectName(QStringLiteral("reset_3"));
        reset_3->setGeometry(QRect(670, 270, 241, 28));
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
        tabWidget->addTab(tab_6, QString());
        tabWidget_2->addTab(tab_5, QString());
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

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        reset->setTitle(QApplication::translate("MainWindow", "Ajouter Matriel", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "MISE_FONCTION", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "MISE_FABRICATION", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "MARQUE", Q_NULLPTR));
        j->setText(QApplication::translate("MainWindow", "ETAT", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "MAIL_FOURNISSEUR", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "REFERENCE", Q_NULLPTR));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        reset_2->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "marche", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "panne", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter mat\303\251riel", Q_NULLPTR));
        supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "tapez Id a suppreimer", Q_NULLPTR));
        recherche->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        reaficher->setText(QApplication::translate("MainWindow", "reafficher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Consulter mat\303\251riel ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Historique", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Panne", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Cause", Q_NULLPTR));
        envoi_M->setText(QApplication::translate("MainWindow", "Envoyer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "affecter \303\240 reparer", Q_NULLPTR));
        send_mail->setText(QApplication::translate("MainWindow", "SEND", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TO", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TITLE", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        reset_3->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Send mail", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Matriel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
