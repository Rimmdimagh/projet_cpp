#ifndef SIGNUP_H
#define SIGNUP_H

#include<QString>
#include<QSqlQueryModel>
#include <QDebug>
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
class signup
{
public:
    signup();
    signup(QString,QString,QString);
    bool Login();
    QString afficherRole();


private:
    int id;
    QString username,password,role;

};


#endif // SIGNUP_H
