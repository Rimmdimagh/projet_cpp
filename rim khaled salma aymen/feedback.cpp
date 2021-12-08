#include "feedback.h"
#include <QSqlQuery>
#include <QtDebug>
feedback::feedback()
{
cin=0; nom=""; domaine=""; avis=0;
}

feedback::feedback(int cin,QString nom,QString domaine,int avis)
{
    this->cin=cin; this->nom=nom; this->domaine=domaine; this->avis=avis;
}
int feedback::getcin(){return cin;}

QString feedback::getnom(){return nom;}

QString feedback::getdomaine(){return domaine;}

int feedback::getavis(){return avis;}

void feedback::setcin(int cin){this->cin=cin;}

void feedback::setnom(QString nom){this->nom=nom;}

void feedback::setdomaine(QString domaine){this->domaine=domaine;}

void feedback::setavis(int avis){this->avis=avis;}

bool feedback::ajouter()
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString avis_string=QString::number(avis);
          query.prepare("INSERT INTO FEEDBACK (cin, nom, domaine, avis) "
                        "VALUES (:id, :nom, :domaine, :avis)");
          query.bindValue(":id", cin_string);
          query.bindValue(":nom", nom);
          query.bindValue(":domaine", domaine);
          query.bindValue(":avis", avis_string);
    return query.exec();
}
QSqlQueryModel * feedback::afficher(){

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM FEEDBACK");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("domaine"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("avis"));

return model;
}
