#include "personnel.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>

Personnel::Personnel()
{
               //initialisation des variables //
    cin=0;telephone=0;age=0;dureeTravail=0;
       nom="";prenom="";adresse="";adresseMail="";
       message="";

}

Personnel::Personnel(int cin,int telephone ,int age,int dureeTravail ,QString nom,QString prenom ,QString adresse ,QString adresseMail,QString message)
     {
         this->cin=cin ;
         this->telephone=telephone;
         this->age=age ;
         this->dureeTravail=dureeTravail ;

         this->nom=nom ;
         this-> prenom=prenom ;
         this ->adresse=adresse;
         this ->adresseMail=adresseMail ;
         this->message=message;

     }

     int  Personnel ::getcin()
     {
         return cin ;
     }
     int  Personnel ::gettelephone()
     {
         return telephone ;
     }
     int Personnel ::getage()
     {
         return age;
     }
     int Personnel ::getdureeTravail()
     {
         return dureeTravail ;
     }
     QString Personnel :: getnom()
     {
         return nom ;
     }
     QString Personnel ::getprenom()
     {
         return prenom ;

     }
     QString Personnel ::getadresse()
     {
         return adresse ;
     }
     QString Personnel :: getadresseMail()
     {
         return adresseMail ;
     }

    QString Personnel::getmessage()
    {
        return message;
    }


     void Personnel :: setcin(int cin)
     {
         this ->cin=cin;
     }
     void Personnel :: settelephone(int telephone)
    {
        this ->telephone=telephone;
    }
     void Personnel ::setage(int age)
     {
         this->age = age;
     }
     void Personnel ::setdureeTravail(int dureeTravail)
     {
         this-> dureeTravail=dureeTravail;
     }
     void Personnel ::setnom(QString nom)
     {
         this ->nom=nom;
     }
     void Personnel ::setprenom(QString prenom)
     {
         this -> prenom=prenom;
     }
     void Personnel ::setadresse(QString adresse)
     {
         this ->adresse=adresse;
     }
     void Personnel ::setadresseMail(QString adresseMail)
     {
         this -> adresseMail=adresseMail ;
     }

     void Personnel::setmessage(QString message)
     {
         this->message=message;
     }

     bool Personnel::ajouter()
     {

         QSqlQuery query;
               query.prepare("INSERT INTO person (CIN,NOM,PRENOM,ADRESSE,ADRESSEMAIL,TELEPHONE,DUREETRAVAIL,AGE,MESSAGE)"
                             "VALUES (:CIN, :NOM, :PRENOM, :ADRESSE ,:ADRESSEMAIL,:TELEPHONE,:DUREETRAVAIL,:AGE,:MESSAGE )");
               QString  cin_string= QString::number(cin);
               QString  age_string= QString::number(age);
               QString  telephone_string= QString::number(telephone);
               QString  dureeTravail_string= QString::number(dureeTravail);


               query.bindValue(":cin", cin);
               query.bindValue(":nom", nom);
               query.bindValue(":prenom", prenom);
               query.bindValue(":adresse", adresse);
               query.bindValue(":adresseMail", adresseMail);
               query.bindValue(":telephone", telephone);
               query.bindValue(":dureeTravail", dureeTravail);
               query.bindValue(":age",age);
               query.bindValue(":message",message);









              return query.exec();




     }
     QSqlQueryModel * Personnel::afficher()
     {

         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT* FROM PERSON");
         model->setHeaderData(0, Qt::Horizontal, QObject:: tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresseMail"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("dureeTravail"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("age"));

        return model;
    }

     bool Personnel::supprimer(int cin)
     {
         QSqlQuery query;
               query.prepare("delete from PERSON where cin=:cin");
               query.bindValue(0, cin);
               return query.exec();
     }

     bool Personnel::modifier(int age ,int cin ,int telephone,int dureeTravail,QString nom, QString prenom ,QString adresse,QString adresseMail,QString message)
     {
     QSqlQuery query;
      QString res0= QString::number(cin);
     QString res= QString::number(telephone);
      QString res1= QString::number(dureeTravail);
      QString res2= QString::number(age);

     query.prepare("Update PERSON set ADRESSE = :adresse , ADRESSEMAIL = :adresseMail , TELEPHONE=:telephone , DUREETRAVAIl=:dureeTravail   where CIN = :cin");
     query.bindValue(":cin", res0);
     query.bindValue(":telephone", res);
     query.bindValue(":adresse", adresse);
     query.bindValue(":adresseMail",adresseMail);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":age", age);
     query.bindValue(":dureeTravail", dureeTravail);





     return    query.exec();
     }

     QSqlQueryModel * Personnel::tri(){

         QSqlQuery *q = new QSqlQuery();
         QSqlQueryModel *model = new QSqlQueryModel();
         q->prepare("SELECT * FROM PERSON ORDER BY CIN ");
         q->exec();
         model->setQuery(*q);

         return model;
     }


     QSqlQueryModel * Personnel::triAge()
     {
         QSqlQuery *q = new QSqlQuery();
         QSqlQueryModel *model = new QSqlQueryModel();
         q->prepare("SELECT * FROM PERSON ORDER BY AGE ");
         q->exec();
         model->setQuery(*q);

         return model;

     }

     QSqlQueryModel * Personnel::triDureeTravail()
     {
         QSqlQuery *q = new QSqlQuery();
         QSqlQueryModel *model = new QSqlQueryModel();
         q->prepare("SELECT * FROM PERSON ORDER BY  DUREETRAVAIL");
         q->exec();
         model->setQuery(*q);

         return model;

     }
     bool Personnel::ajouterMessage(QString nom )
     {
         QSqlQuery query;
         query.prepare("UPDATE PERSON SET MESSAGE=:MESSAGE WHERE NOM LIKE :nom");
         query.bindValue(":nom",nom);
         query.bindValue(":MESSAGE",message);
         return query.exec();
     }

     QSqlQueryModel * Personnel::afficherMessage(){
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT PRENOM,MESSAGE FROM PERSON where MESSAGE IS NOT NULL ");


         return model;

     }
