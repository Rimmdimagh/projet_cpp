#include "entretien.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include <QPrinter>
#include <QSqlTableModel>

/*class entretienData : public QSharedData
{

public:

};
*/
entretien::entretien()
    //: data(new entretienData)
{
    id=""; nom="";prenom="";poste="";
}

entretien::entretien(QString id,QString nom,QString prenom,QDate date,QString poste)
    //: data(rhs.data)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->poste=poste;
}

QString entretien::getid(){return id;}
QString entretien::getnom(){return nom;}
QString entretien::getprenom(){return prenom;}
QDate entretien::getdate(){return date;}
QString entretien::getposte(){return poste;}

void entretien::setid(QString id){this->id=id;}
void entretien::setnom(QString nom){this->nom=nom;}
void entretien::setprenom(QString prenom){this->prenom=prenom;}
void entretien::setdate(QDate date){this->date=date;}
void entretien::setposte(QString poste){this->poste=poste;}

/*entretien &entretien::operator=(const entretien &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}
*/


bool entretien::ajouter()
{

    QSqlQuery query;
  //QString id_string= QString::number(id);
  //QString id_string= QString::number(id);
         query.prepare("INSERT INTO recrutement (cin, nom, prenom,date_entretien,poste_choisi) "
                       "VALUES (:id,:nom, :prenom,:date_entretien,:poste_choisi)");
         query.bindValue(":id",id);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":date_entretien",date);
         query.bindValue(":poste_choisi",poste);
        return query.exec();

}


QSqlQueryModel* entretien::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM recrutement");



  return  model;
}

bool entretien::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare("Delete from recrutement where cin=:id");
         query.bindValue(0, id);

        return query.exec();


}

bool entretien::modifier(QString id,QString nom, QString prenom, QDate date, QString poste )
{
    QSqlQuery query;
    //QString res= QString::number(id);
    //QString id1= QString::number(id);
    //QString numero= QString::number(num);


    query.prepare("update recrutement set nom=:nom,prenom=:prenom,date_entretien=:date ,poste_choisi=:poste where cin=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date);
    query.bindValue(":poste",poste);


    return query.exec();
}


QSqlQueryModel * entretien::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from recrutement where ((cin|| nom|| prenom|| date_entretien|| poste_choisi) LIKE '%"+aux+"%')");


    return model;
}


QSqlQueryModel *  entretien::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from recrutement order by "+critere+" "+mode+"");

    return model;
}
/*entretien::~entretien()
{

}
*/

