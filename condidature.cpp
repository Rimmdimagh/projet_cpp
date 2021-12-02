#include "condidature.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Condidature::Condidature()
{
identifiant=0;nomt="";specialite="";niveauc="";
}

 Condidature::Condidature (int identifiant ,QString nomt,QString specialite ,QString niveauc )
 {this->nomt=nomt;this->identifiant=identifiant;this->specialite=specialite;this->niveauc=niveauc;}


QString Condidature:: getnomt(){return nomt;}
int Condidature:: getidentifiant (){return identifiant ;}
QString Condidature::getspecialite (){return specialite;}
QString Condidature:: getniveauc(){return niveauc ;}
 void Condidature:: setnomt(QString nomt){this->nomt=nomt;}
 void Condidature::setidentifiant(int identifiant){this->identifiant=identifiant;}
 void Condidature::setspecialite(QString specialite){this->specialite=specialite;}
 void Condidature::setniveauc(QString niveauc){this->niveauc=niveauc;}
 bool Condidature::ajouter()
 {


  QSqlQuery query;
  QString identifiant_string= QString::number(identifiant);
       query.prepare("INSERT INTO condidature  (IDENTIFIANT, NOMT, SPECIALITE,NIVEAUC) "
                     "VALUES (:identifiant, :name, :speciality, :level)");
       query.bindValue(":identifiant",identifiant_string);
       query.bindValue(":name",nomt);
      query.bindValue(":speciality",specialite);
       query.bindValue(":level",niveauc);


       return   query.exec();
 }
 QSqlQueryModel *Condidature:: afficher()
 {
   QSqlQueryModel * model =new QSqlQueryModel ();
   model->setQuery("SELECT identifiant,nomt,specialite,niveauc FROM condidature");
   model ->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
   model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nomt"));
   model ->setHeaderData(2,Qt::Horizontal,QObject::tr("specialite"));
   model ->setHeaderData(3,Qt::Horizontal,QObject::tr("niveauc"));
     return model;
 }
 bool Condidature :: supprimer(int identifiant)
 {

 QSqlQuery query;
 query .prepare ("Delete from condidature where identifiant=:identifiant");
     query.bindValue(0,identifiant);
 return query.exec();


 }

 bool Condidature:: modifier(int identifiant ,QString nomt,QString specialite,QString niveauc)
  {
      QSqlQuery query ;
      QString id_string = QString::number(identifiant );
      query.prepare("update CONDIDATURE set nomt=:nomt,specialite=:specialite,niveauc=:niveauc where identifiant=:identifiant");
      query.bindValue(":identifiant",identifiant);
        query.bindValue(":nomt",nomt);
      query.bindValue(":specialite",specialite);
      query.bindValue(":niveauc",niveauc);


      return query.exec();
 }

 QSqlQueryModel* Condidature::triparspecialite()
 {
 QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM condidature order by specialite ASC");
                  q->exec();
                  model->setQuery(*q);
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
                  model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));

                  return model;


 }
 QSqlQueryModel* Condidature::rechercher_nomt(QString nomt)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where nomt=:nomt");
                      q->bindValue(":nomt",nomt );
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }
 QSqlQueryModel* Condidature::rechercher_identifiant(int identifiant)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where identifiant=:identifiant");
                      q->bindValue(":identifiant",identifiant );
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }
 QSqlQueryModel* Condidature::rechercher_specialite(QString specialite)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where specialite=:specialite");
                      q->bindValue(":specialite",specialite );
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }
 QSqlQueryModel* Condidature::rechercher_nomtspecialite(QString specialite, QString nomt)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where specialite=:specialite and nomt=:nomt");
                      q->bindValue(":specialite",specialite);
                       q->bindValue(":nomt",nomt);
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }
 QSqlQueryModel* Condidature::rechercher_nomtidentifiant(int identifiant, QString nomt)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where  nomt=:nomt and identifiant=:identifiant ");
                      q->bindValue(":identifiant",identifiant);
                       q->bindValue(":nomt",nomt);
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }

 QSqlQueryModel* Condidature::rechercher_specialiteidentifiant(int identifiant, QString specialite)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where specialite=:specialite and identifiant=:identifiant");
                      q->bindValue(":specialite",specialite );
                      q->bindValue(":identifiant",identifiant );

                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }
 QSqlQueryModel* Condidature::rechercher_specialiteidentifiantnomt(int identifiant, QString specialite,QString nomt)
 {
     QSqlQuery * q = new  QSqlQuery ();

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("select * from Gestion_condidature where specialite=:specialite and identifiant=:identifiant and nomt=:nomt");
                      q->bindValue(":specialite",specialite );
                      q->bindValue(":identifiant",identifiant );
                       q->bindValue(":nomt",nomt );
                      q->exec();

          model->setQuery(*q);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomt"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("niveauc"));



         return model;

 }






  void Condidature::statistiques(QWidget * w)
  {
          int nb1 = 0,nb2=0,nb3=0,nb4=0;
              QSqlQuery query("SELECT COUNT(*) FROM condidature WHERE specialite='Technicien'");
              while(query.next())
              {
                  nb1 = query.value(0).toInt();
              }
              QSqlQuery query2("SELECT COUNT(*) FROM Condidature WHERE fonction='Ingenieur'");
              while(query2.next())
              {
                 nb2= query2.value(0).toInt();
              }
              QSqlQuery query3("SELECT COUNT(*) FROM Condidature WHERE fonction='entrepreneur'");
              while(query3.next())
              {
                 nb3= query3.value(0).toInt();
              }
              QSqlQuery query4("SELECT COUNT(*) FROM Condidature WHERE fonction='Condidature'");
              while(query4.next())
              {
                 nb4= query4.value(0).toInt();
              }

         QPieSeries *series = new QPieSeries();

          series->append("Technicien",nb1);
          series->append("Ingenieur",nb2);
          series->append("entrepreneur",nb3);
          series->append("Condidature",nb4);

          series->setHoleSize(0.0);
          series->setPieSize(1.0);
          QPieSlice * T = series->slices().at(0);
          QPieSlice * I = series->slices().at(1);
          QPieSlice * E = series->slices().at(2);
          QPieSlice * C = series->slices().at(3);

          T->setLabelVisible(true);
          I->setLabelVisible(true);
          E->setLabelVisible(true);
          C->setLabelVisible(true);

          T->setBrush(QColor::fromRgb(255, 0, 0));
          I->setBrush(QColor::fromRgb(0, 255, 0));
          E->setBrush(QColor::fromRgb(0, 0, 255));
          C->setBrush(QColor::fromRgb(255, 255, 0));

          QChart *chart = new QChart();
          chart->addSeries(series);
          chart->setTitle("CONDIDATURE");
          chart->legend()->setVisible(true);
          chart->legend()->setAlignment(Qt::AlignBottom);
          chart->setAnimationOptions(QChart::AllAnimations);

          QChartView * chartview = new QChartView(chart);
          chartview->resize(w->width(),w->height());
          chartview->setParent(w);
  }
