#ifndef CONDIDATURE_H
#define CONDIDATURE_H
#include <QString>
#include <QSqlQueryModel>
#include<QTextCharFormat>
#include<QCalendarWidget>
#include <QFrame>


#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

class condidature
{
public:

    condidature();
    condidature (int ,QString,QString,QString);
    QString getnomt();
    int  getidentifiant();
    QString getspecialite ();
    QString getniveauc();
    void setnomt(QString);
    void setidentifiant(int);
    void setspecialite(QString);
    void setniveauc(QString);
    bool ajouter ();
QSqlQueryModel *afficher();
bool supprimer(int);
bool modifier(int,QString,QString,QString);
QSqlQueryModel* triparspecialite();
QSqlQueryModel* rechercher_nomt(QString nomt);
QSqlQueryModel* rechercher_identifiant(int  identifiant);
QSqlQueryModel* rechercher_specialite(QString specialite);
QSqlQueryModel* rechercher_nomtspecialite(QString specialite,QString nomt);
QSqlQueryModel* rechercher_nomtidentifiant(int identifiant,QString nomt);

QSqlQueryModel* rechercher_specialiteidentifiant(int identifiant,QString specialite);
QSqlQueryModel* rechercher_specialiteidentifiantnomt(int identifiant,QString specialite,QString nomt);
void statistiques(QWidget * W);



private :
    int identifiant ;
    QString nomt;
    QString specialite;
    QString niveauc;

};


#endif // CONDIDATURE_H
