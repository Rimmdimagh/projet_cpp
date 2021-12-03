#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <time.h>


class Formation
{public:
    Formation();
    Formation(QString,QString,QString,int,QString);
    QString  get_code_formation();
    QString get_nom_for();
    QString get_nom_encadreur();
    int get_dure_for();
    QString get_type_for();

    void  setcode_formation(QString);

    void  setnom_for(QString);
    void  setnom_encadreur(QString);
    void  setdure_for( int);
    void  settype_for(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString   ,QString  ,QString ,QString ,int );
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();
    QSqlQueryModel * trid();
    // bool modifierv2(QString);
    int Pin_rand();
    bool modifier_2(QString ,QString ,QString ,QString ,int ,int );


private:
    QString code_formation,nom_for,nom_encadreur,type_for;
    int dure_for,pin_for;
};

#endif // FORMATION_H
