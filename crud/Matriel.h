#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Matriel
{
public:
   Matriel();//constructeur par defauts


   Matriel(int,QString,QString,QString,QString,QString,QString,QDate,QDate);

   //constructeur parametree
   //getters
    int get_id();
    QString get_nom();
    QString get_reference();
    QString get_marque();
    QString get_categorie();
    QString get_etat();
    QString get_mail();
    QDate get_miseFab();
    QDate get_miseFonc();
    //setters
    void  setid(int);
    void  set_nom(QString);
    void  set_reference(QString);
    void  set_marque(QString);
    void set_categorie(QString);
    void  set_etat(QString);
    void  set_mail(QString);
    void  set_miseFab(QDate);
    void  set_miseFonc(QDate);

//les methodes
    bool ajouter();//elle va retourner soit le true soit le false
    QSqlQueryModel* afficher();
    bool supprimer(int);
bool modifier(int,QString,QString,QString,QString,QString,QString,QDate,QDate);


//rechercher
QSqlQueryModel * rechercher(QString ch);
bool modifier_e(int ,int );
QStringList recherche_t();
QStringList recherche_t1();
//les attribus
private:
    QString nom,reference,marque,categorie,etat,mail;
    int id;
    QDate miseFab,miseFonc;
};

#endif // FORMATION_H

