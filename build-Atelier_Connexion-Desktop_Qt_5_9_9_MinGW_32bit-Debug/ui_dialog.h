/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *uname;
    QLineEdit *passwd;
    QLineEdit *recipient;
    QLabel *label_4;
    QLineEdit *subjectLineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *recipient_n;
    QLineEdit *recipient_s;
    QHBoxLayout *horizontalLayout;
    QTextEdit *message;
    QPushButton *annuler_mail;
    QPushButton *envoyer_dialog;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 380, 280));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        uname = new QLineEdit(layoutWidget);
        uname->setObjectName(QStringLiteral("uname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, uname);

        passwd = new QLineEdit(layoutWidget);
        passwd->setObjectName(QStringLiteral("passwd"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwd);

        recipient = new QLineEdit(layoutWidget);
        recipient->setObjectName(QStringLiteral("recipient"));

        formLayout->setWidget(4, QFormLayout::FieldRole, recipient);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        subjectLineEdit = new QLineEdit(layoutWidget);
        subjectLineEdit->setObjectName(QStringLiteral("subjectLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, subjectLineEdit);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        recipient_n = new QLineEdit(layoutWidget);
        recipient_n->setObjectName(QStringLiteral("recipient_n"));

        formLayout->setWidget(2, QFormLayout::FieldRole, recipient_n);

        recipient_s = new QLineEdit(layoutWidget);
        recipient_s->setObjectName(QStringLiteral("recipient_s"));

        formLayout->setWidget(3, QFormLayout::FieldRole, recipient_s);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        message = new QTextEdit(layoutWidget);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout->addWidget(message);

        annuler_mail = new QPushButton(layoutWidget);
        annuler_mail->setObjectName(QStringLiteral("annuler_mail"));

        horizontalLayout->addWidget(annuler_mail);

        envoyer_dialog = new QPushButton(layoutWidget);
        envoyer_dialog->setObjectName(QStringLiteral("envoyer_dialog"));

        horizontalLayout->addWidget(envoyer_dialog);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Email destinaire : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Password :", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Username :", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Sujet :", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Prenom destinaire :", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "Nom destinaire :", Q_NULLPTR));
        message->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", Q_NULLPTR));
        annuler_mail->setText(QApplication::translate("Dialog", "Annuler", Q_NULLPTR));
        envoyer_dialog->setText(QApplication::translate("Dialog", "Envoyer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
