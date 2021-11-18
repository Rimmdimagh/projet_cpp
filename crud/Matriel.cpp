#include "Matriel.h"
#include<QSqlQueryModel>//pour les models
#include<QtDebug>//
#include<QObject>//pour les objets
//constructeur par defaut
Matriel::Matriel()
{
id=0;
nom="";
reference="";
marque="";
etat="";

mail="";
/*miseFab="";
miseFonc="";*/
}

//parametree
Matriel::Matriel(int id_m,QString nom_m,QString reference_m,QString marque_m,QString etat_m,QString mail_m ,QDate miseFab_m,QDate miseFonc_m)
{
    this->id=id_m;
    this->nom=nom_m;
    this->reference=reference_m;
    this->marque=marque_m;
    this->etat=etat_m;

    this->mail=mail_m;
    this->miseFab=miseFab_m;
    this->miseFonc=miseFonc_m;

}

int Matriel::get_id(){return id;}
QString Matriel::get_nom(){return  nom;}
QString Matriel::get_reference(){return reference;}
QString Matriel::get_marque(){return marque;}
QString Matriel::get_etat(){return etat;}

QString Matriel::get_mail(){return mail;}
QDate Matriel::get_miseFab(){return miseFab;}
QDate Matriel::get_miseFonc(){return miseFonc;}

void  Matriel::setid(int id) {this->id=id;}
void  Matriel::set_nom(QString nom ){this->nom=nom;}
void  Matriel::set_reference(QString reference){this->reference=reference;}
void  Matriel::set_marque(QString marque){this->marque=marque;}
void  Matriel::set_etat(QString etat) {this->etat=etat;}

void  Matriel::set_mail(QString mail) {this->mail=mail;}
void  Matriel::set_miseFab(QDate miseFab) {this->miseFab=miseFab;}
void  Matriel::set_miseFonc(QDate miseFonc) {this->miseFab=miseFonc;}



bool Matriel::ajouter()
{
QSqlQuery query;//requette c est query de type sql (bd)

QString IDstring=QString::number(id);

query.prepare("INSERT INTO MATRIEL (ID,NOM,REFERENCE,MARQUE,ETAT,MAIL,MISE_FAB,MISE_FONC) "
                    "VALUES (:ID, :NOM, :REFERENCE,:MARQUE,:ETAT,:MAIL,:MISE_FAB,:MISE_FONC)");

query.bindValue(":ID",IDstring);//bindvalue thez mn interface graphique w thutha f variable
query.bindValue(":NOM",nom);
query.bindValue(":REFERENCE",reference);
query.bindValue(":MARQUE",marque);
query.bindValue(":ETAT",etat );

query.bindValue(":MAIL",mail );
query.bindValue(":MISE_FAB",miseFab);
query.bindValue(":MISE_FONC",miseFonc);
  return query.exec();//exec heya lbch trja3 le true wala false est ce que il est ajouter ou non
}








QSqlQueryModel* Matriel::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select* from MATRIEL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT "));

model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MISE_FAB"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FONC"));
    return model;
}



//supprimer dans la base de donne
bool Matriel::supprimer(int id )
{

QSqlQuery query;
query.prepare("Delete from MATRIEL where ID =:ID ");
query.bindValue(0, id);



return    query.exec();
}


//modifier

bool Matriel::modifier(int id ,QString nom ,QString reference,QString marque,QString etat,QString mail ,QDate miseFab,QDate miseFonc)
{
QSqlQuery query;
 QString IDString= QString::number(id);



query.prepare("Update MATRIEL set NOM=:NOM,REFERENCE = :REFERENCE , MARQUE= :MARQUE , ETAT= :ETAT ,MAIL= :MAIL,MISE_FAB= :MISE_FAB,MISE_FONC= :MISE_FONC  where ID = :ID ");
query.bindValue(":ID", IDString);
query.bindValue(":NOM", nom);
query.bindValue(":REFERENCE", reference);
query.bindValue(":MARQUE", marque);
query.bindValue(":ETAT", etat);
query.bindValue(":MAIL", mail);
query.bindValue(":MISE_FAB", miseFab);
query.bindValue(":MISE_FONC",miseFonc );

return    query.exec();
}




QSqlQueryModel * Matriel::rechercher(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from MATRIEL where REFERENCE LIKE '"+txt+"'" );


      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT "));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL "));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("MISE_FAB"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FONC"));


      return model;
  }
/*
QSqlQueryModel *Matriel::rechercher1(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from MATRIEL where MAIL LIKE '"+txt+"'" );

      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT "));

      model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL "));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("MISE_FAB"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FONC"));

      return model;
  }
QSqlQueryModel *Matriel::rechercher2(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from MATRIEL where MARQUE LIKE '"+txt+"'" );

      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT "));

      model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL "));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("MISE_FAB"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FONC"));




      return  model;
}

*/
