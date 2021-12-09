#ifndef MATRIEL_H
#define MATRIEL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Matriel
{
public:
    Matriel();
    Matriel(int,QString,QString,QString,QString,QString,QString,QDate,QDate);
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



        bool ajouter();//elle va retourner soit le true soit le false
            QSqlQueryModel* afficher();
            bool supprimer(int);
        bool modifier(int,QString,QString,QString,QString,QString,QString,QDate,QDate);


        //rechercher
        QSqlQueryModel * rechercher(QString ch);
        QSqlQueryModel * rechercher_1(QString txt);
        bool modifier_e(int ,int );
        QStringList recherche_t();
        QStringList recherche_t1();
        //les attribus
        private:
            QString nom,reference,marque,categorie,etat,mail;
            int id;
            QDate miseFab,miseFonc;















};

#endif // MATRIEL_H
