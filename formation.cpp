#include "formation.h"
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>



Formation::Formation()
{
code_formation="";
nom_for="";
nom_encadreur="";
type_for="";
dure_for=0;


}

Formation::Formation(QString code_formation  ,QString nom_for ,QString nom_encadreur ,int dure_for ,QString type_for  )
{
  this->code_formation=code_formation;
  this->nom_for=nom_for;
    this-> nom_encadreur=nom_encadreur;
    this->dure_for=dure_for;
    this->type_for=type_for;

}

QString Formation::get_code_formation(){return  code_formation;}
QString Formation::get_nom_for(){return  nom_for;}
QString Formation::get_nom_encadreur(){return nom_encadreur;}
QString Formation::get_type_for(){return type_for;}
int Formation::get_dure_for(){return  dure_for;}

void  Formation::setcode_formation(QString code_formation) {this->code_formation=code_formation;}
void  Formation::setdure_for(int dure_for){this->dure_for=dure_for;}
void  Formation::setnom_for(QString nom_for){this->nom_for=nom_for;}
void  Formation::setnom_encadreur(QString nom_encadreur){this->nom_encadreur=nom_encadreur;}
void  Formation::settype_for(QString type_for) {this->type_for=type_for;}

bool Formation::ajouter()
{
QSqlQuery query;
QString DURE_FORstring=QString::number(dure_for);

query.prepare("INSERT INTO FORMATION (CODE_FORMATION,NOM_FOR,NOM_ENCADREUR,TYPE_FOR,DURE_FOR) "
                    "VALUES (:CODE_FORMATION,:NOM_FOR, :NOM_ENCADREUR,:TYPE_FOR,:DURE_FOR)");
query.bindValue(":CODE_FORMATION", code_formation);
query.bindValue(":NOM_FOR",nom_for);
query.bindValue(":NOM_ENCADREUR", nom_encadreur);
query.bindValue(":TYPE_FOR", type_for);
query.bindValue(":DURE_FOR", DURE_FORstring );

  return query.exec();
}

QSqlQueryModel * Formation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Formation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_FORMATION"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_ENCADREUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_FOR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DURE_FOR "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PIN"));

    return model;
}

bool Formation::supprimer(QString code_formation )
{
QSqlQuery query;
query.prepare("Delete from Formation where CODE_FORMATION = :CODE_FORMATION ");
query.bindValue(0,code_formation);
//query.bindValue(":code_supp",code_formation);
return    query.exec();
}

bool Formation::modifier(QString code_formation  ,QString nom_for ,QString nom_encadreur ,QString type_for,int dure_for  )
{
    QSqlQuery query;
    QString DURE_FORstring=QString::number(dure_for);
        query.prepare("UPDATE Formation SET NOM_FOR=:NOM_FOR , NOM_ENCADREUR=:NOM_ENCADREUR,TYPE_FOR=:TYPE_FOR WHERE CODE_FORMATION=:CODE_FORMATION");
        query.bindValue(":CODE_FORMATION", code_formation);
        query.bindValue(":NOM_FOR",nom_for);
        query.bindValue(":NOM_ENCADREUR", nom_encadreur);
        query.bindValue(":TYPE_FOR", type_for);
        query.bindValue(":DURE_FOR", DURE_FORstring );
        return    query.exec();
}

QSqlQueryModel *Formation::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from Formation where code_formation LIKE '"+rech+"%'");
    return model;
}


QSqlQueryModel * Formation::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM Formation ORDER BY NOM_FOR");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *Formation::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM Formation ORDER BY NOM_FOR DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}

int Formation::Pin_rand(){
    int a,b,c,d,pin;
  //  QSqlQuery query;
   srand(time(NULL));

    a =(rand()%10);
    b =(rand()%10)*10;
    c =(rand()%10)*100;
    d =(rand()%10)*1000;
    pin=a+b+c+d;
        QString pin_string=QString::number(pin);
      /*  query.prepare("INSERT INTO FORMATION (PIN) "
                            "VALUES (:PIN)");
        query.bindValue(":PIN", pin_string );

      return query.exec();*/
        return pin ;

}

bool Formation::modifier_2(QString code_formation  ,QString nom_for ,QString nom_encadreur ,QString type_for,int dure_for ,int pin )
{
    QSqlQuery query;
    QString DURE_FORstring=QString::number(dure_for);
    QString pin_string=QString::number(pin);
        query.prepare("UPDATE Formation SET NOM_FOR=:NOM_FOR , NOM_ENCADREUR=:NOM_ENCADREUR,TYPE_FOR=:TYPE_FOR ,DURE_FOR=:DURE_FOR,PIN=:pin WHERE CODE_FORMATION=:CODE_FORMATION");
     //  query.prepare("UPDATE Formation SET PIN=:pin WHERE CODE_FORMATION=:CODE_FORMATION");
        query.bindValue(":CODE_FORMATION", code_formation);
        query.bindValue(":NOM_FOR",nom_for);
        query.bindValue(":NOM_ENCADREUR", nom_encadreur);
        query.bindValue(":TYPE_FOR", type_for);
        query.bindValue(":DURE_FOR", DURE_FORstring );
        query.bindValue(":pin", pin_string );
        return    query.exec();
}
