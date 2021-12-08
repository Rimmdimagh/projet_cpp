#include "feedback.h"
#include <QSqlQuery>
#include <QtDebug>

Feedback::Feedback()
{
cin=0; nom=""; domaine=""; avis=0;
}

Feedback::Feedback(int cin,QString nom,QString domaine,int avis)
{
    this->cin=cin; this->nom=nom; this->domaine=domaine; this->avis=avis;
}

int Feedback::getcin(){return cin;}

QString Feedback::getnom(){return nom;}

QString Feedback::getdomaine(){return domaine;}

int Feedback::getavis(){return avis;}

void Feedback::setcin(int cin){this->cin=cin;}

void Feedback::setnom(QString nom){this->nom=nom;}

void Feedback::setdomaine(QString domaine){this->domaine=domaine;}

void Feedback::setavis(int avis){this->avis=avis;}

bool Feedback::ajouter()
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
