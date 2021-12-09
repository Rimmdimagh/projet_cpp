#ifndef ENTRETIEN_H
#define ENTRETIEN_H

#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include"QDate"
#include"QDebug"
#include<QObject>

class entretienData;

class entretien
{

public:
    entretien();
    entretien(QString id,QString nom, QString prenom,QDate date,QString poste );
    /*entretien(const entretien &);
    entretien &operator=(const entretien &);
    ~entretien();
    */
    QString getid();
    QString getnom();
    QString getprenom();
    QDate getdate();
    QString getposte();
    void setid(QString);
    void setnom(QString);
    void setprenom(QString);
    void setdate(QDate);
    void setposte(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString ,QString, QString  , QDate , QString );

    QSqlQueryModel * rechercher (const QString &aux);
    //QSqlQueryModel* trie();
    QSqlQueryModel *  trier(const QString &critere, const QString &mode );

private:
    //QSharedDataPointer<entretienData> data;
    QString id,nom,prenom,poste;
    QDate date;
};

#endif // ENTRETIEN_H
