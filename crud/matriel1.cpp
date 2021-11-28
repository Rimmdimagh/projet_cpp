#include "matriel1.h"
#include "ui_matriel1.h"
#include "QMessageBox"
#include<QSqlQueryModel>//pour les models
#include<QtDebug>//
#include<QObject>//pour les objets


matriel1::matriel1()
{
id=0;
nom="";
reference="";
marque="";
categorie="";
etat="";

mail="";
/*miseFab="";
miseFonc="";*/
}
matriel1::matriel1(int id_m,QString nom_m,QString reference_m,QString marque_m,QString categorie_m,QString etat_m,QString mail_m ,QDate miseFab_m,QDate miseFonc_m)
{
    this->id=id_m;
    this->nom=nom_m;
    this->reference=reference_m;
    this->marque=marque_m;
    this->categorie=categorie_m;
    this->etat=etat_m;

    this->mail=mail_m;
    this->miseFab=miseFab_m;
    this->miseFonc=miseFonc_m;

}

int matriel1::get_id(){return id;}
QString matriel1::get_nom(){return  nom;}
QString matriel1::get_reference(){return reference;}
QString matriel1::get_marque(){return marque;}
QString matriel1::get_categorie(){return categorie;}
QString matriel1::get_etat(){return etat;}

QString matriel1::get_mail(){return mail;}
QDate matriel1::get_miseFab(){return miseFab;}
QDate matriel1::get_miseFonc(){return miseFonc;}

void  matriel1::setid(int id) {this->id=id;}
void  matriel1::set_nom(QString nom ){this->nom=nom;}
void  matriel1::set_reference(QString reference){this->reference=reference;}
void  matriel1::set_marque(QString marque){this->marque=marque;}
void  matriel1::set_categorie(QString categorie){this->categorie=categorie;}
void  matriel1::set_etat(QString etat) {this->etat=etat;}
void  matriel1::set_mail(QString mail) {this->mail=mail;}
void  matriel1::set_miseFab(QDate miseFab) {this->miseFab=miseFab;}
void  matriel1::set_miseFonc(QDate miseFonc) {this->miseFab=miseFonc;}



bool matriel1::ajouter()
{
QSqlQuery query;//requette c est query de type sql (bd)

QString IDstring=QString::number(id);

query.prepare("INSERT INTO MATRIEL (ID,NOM,REFERENCE,MARQUE,CATEGORIE,ETAT,MAIL,MISE_FAB,MISE_FONC) "
                    "VALUES (:ID, :NOM, :REFERENCE,:MARQUE,:CATEGORIE,:ETAT,:MAIL,:MISE_FAB,:MISE_FONC)");

query.bindValue(":ID",IDstring);//bindvalue thez mn interface graphique w thutha f variable
query.bindValue(":NOM",nom);
query.bindValue(":REFERENCE",reference);
query.bindValue(":MARQUE",marque);
query.bindValue(":CATEGORIE",categorie);
query.bindValue(":ETAT",etat );
query.bindValue(":MAIL",mail );
query.bindValue(":MISE_FAB",miseFab);
query.bindValue(":MISE_FONC",miseFonc);
  return query.exec();//exec heya lbch trja3 le true wala false est ce que il est ajouter ou non
}








QSqlQueryModel* matriel1::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select* from MATRIEL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CATEGORIE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MAIL "));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FAB"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("MISE_FONC"));
    return model;
}



//supprimer dans la base de donne
bool matriel1::supprimer(int id )
{

QSqlQuery query;
query.prepare("Delete from MATRIEL where ID =:ID ");
query.bindValue(0, id);



return    query.exec();
}


//modifier

bool matriel1::modifier(int id ,QString nom ,QString reference,QString marque,QString categorie,QString etat,QString mail ,QDate miseFab,QDate miseFonc)
{
QSqlQuery query;
 QString IDString= QString::number(id);



query.prepare("Update MATRIEL set NOM=:NOM,REFERENCE = :REFERENCE ,MARQUE= :MARQUE,CATEGORIE= :CATEGORIE , ETAT= :ETAT ,MAIL= :MAIL,MISE_FAB= :MISE_FAB,MISE_FONC= :MISE_FONC  where ID = :ID ");
query.bindValue(":ID", IDString);
query.bindValue(":NOM", nom);
query.bindValue(":REFERENCE", reference);
query.bindValue(":MARQUE", marque);
query.bindValue(":CATEGORIE", categorie);
query.bindValue(":ETAT", etat);
query.bindValue(":MAIL", mail);
query.bindValue(":MISE_FAB", miseFab);
query.bindValue(":MISE_FONC",miseFonc );

return    query.exec();
}




QSqlQueryModel * matriel1::rechercher(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from MATRIEL where REFERENCE LIKE '"+txt+"'" );


      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));//setheader yaani je suis entrain d ajouter le nom de coulone de mon tableau
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("MARQUE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("CATEGORIE"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT "));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("MAIL "));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("MISE_FAB"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("MISE_FONC"));


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
bool matriel1::modifier_e(int id,int ide)
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString ide_string= QString::number(ide);
    query.prepare("UPDATE PERSON SET  ID_MATRIEL=:ID WHERE CIN=:IDE ");

    query.bindValue(":ID", id_string);
    query.bindValue(":IDE",ide_string);
    return    query.exec();

}

QStringList matriel1::recherche_t(){
    QSqlQuery query;
    query.prepare("select ID from MATRIEL Where ETAT= 'panne' ");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList matriel1::recherche_t1(){
    QSqlQuery query;
    query.prepare("select CIN from PERSON ");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}

matriel1::~matriel1()
{
    delete ui;
}
