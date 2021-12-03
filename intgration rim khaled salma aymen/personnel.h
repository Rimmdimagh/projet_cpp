#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Personnel
{
public:
    Personnel();
    Personnel(int,int,int,int,QString,QString,QString ,QString,QString);
    int getcin();
    int gettelephone();
    int getage();
    int getdureeTravail();

    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getadresseMail();
    QString getmessage();


   void setcin(int);
   void settelephone(int);
   void setage(int);
   void setdureeTravail(int);
   void setnom(QString);
   void setprenom(QString);
   void setadresse(QString);
   void setadresseMail(QString);
   void setmessage(QString);

   bool ajouter();
   QSqlQueryModel *afficher();
   bool supprimer(int);
   bool modifier(int,int,int,int,QString,QString,QString,QString,QString);
     QSqlQueryModel *tri();
     QSqlQueryModel *triAge();
     QSqlQueryModel *triDureeTravail();
   bool ajouterMessage(QString);
   QSqlQueryModel * afficherMessage();







 private :

   int cin,telephone,age,dureeTravail;
   QString nom,prenom,adresse,adresseMail,message;



};

#endif // PERSONNEL_H




