#include "matriel.h"
#include<QSqlQueryModel>//pour les models
#include<QtDebug>//
#include<QObject>//pour les objetss
Matriel::Matriel()
{
    id=0;
    nom="";
    reference="";
    marque="";
    categorie="";
    etat="";

    mail="";
}
Matriel::Matriel(int id_m,QString nom_m,QString reference_m,QString marque_m,QString categorie_m,QString etat_m,QString mail_m ,QDate miseFab_m,QDate miseFonc_m)
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
int Matriel::get_id(){return id;}
QString Matriel::get_nom(){return  nom;}
QString Matriel::get_reference(){return reference;}
QString Matriel::get_marque(){return marque;}
QString Matriel::get_categorie(){return categorie;}
QString Matriel::get_etat(){return etat;}

QString Matriel::get_mail(){return mail;}
QDate Matriel::get_miseFab(){return miseFab;}
QDate Matriel::get_miseFonc(){return miseFonc;}
void Matriel::setid(int id) {this->id=id;}
void Matriel::set_nom(QString nom ){this->nom=nom;}
void Matriel::set_reference(QString reference){this->reference=reference;}
void Matriel::set_marque(QString marque){this->marque=marque;}
void Matriel::set_categorie(QString categorie){this->categorie=categorie;}
void Matriel::set_etat(QString etat) {this->etat=etat;}
void Matriel::set_mail(QString mail) {this->mail=mail;}
void Matriel::set_miseFab(QDate miseFab) {this->miseFab=miseFab;}
void Matriel::set_miseFonc(QDate miseFonc) {this->miseFab=miseFonc;}
bool Matriel::ajouter(){
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
      return query.exec();
}
QSqlQueryModel * Matriel::afficher(){
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
bool Matriel::supprimer(int id){

    QSqlQuery query;
    query.prepare("Delete from MATRIEL where ID =:ID ");
    query.bindValue(0, id);



    return    query.exec();
}
bool Matriel::modifier(int id ,QString nom ,QString reference,QString marque,QString categorie,QString etat,QString mail ,QDate miseFab,QDate miseFonc)
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



QSqlQueryModel * Matriel::rechercher(QString ch)

{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from MATRIEL where REFERENCE LIKE '"+ch+"'" );


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
bool Matriel::modifier_e(int id , int ide)
{

    QSqlQuery query;
    QString id_string= QString::number(id);
    QString ide_string= QString::number(ide);
    query.prepare("UPDATE PERSON SET  ID_MATRIEL=:ID WHERE CIN=:IDE ");

    query.bindValue(":ID", id_string);
    query.bindValue(":IDE",ide_string);
    return    query.exec();
}
QStringList Matriel::recherche_t(){

    QSqlQuery query;
       query.prepare("select ID from MATRIEL Where ETAT= 'panne' ");
       query.exec();
       QStringList list;
       while(query.next()){
           list.append(query.value(0).toString());
       }

       return list;
}
QStringList Matriel::recherche_t1(){
    QSqlQuery query;
        query.prepare("select CIN from PERSON ");
        query.exec();
        QStringList list;
        while(query.next()){
            list.append(query.value(0).toString());
        }

        return list;
}
