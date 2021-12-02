#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include "condidature.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlTableModel>
#include <QLineSeries>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_condidature ->setModel(Ctmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int identifiant=ui->le_identifiant->text().toInt();
    QString nomt=ui->le_nomt->text();
    QString specialite=ui->la_specialite->text();
    QString niveauc=ui->le_niveauc->text();
    Condidature C(identifiant,nomt,specialite,niveauc);
        bool test=C.ajouter();
  MainWindow w;
 if(test)
  {ui->tab_condidature ->setModel(C.afficher());

      QMessageBox::information(nullptr, QObject::tr("database is open"),
                  QObject::tr("ajout avec succes.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

 }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("echec d ajout.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pb_supprimer_clicked()
{
    Condidature C; C.setidentifiant(ui->leidentifiantsupp->text().toInt());
    bool test=C.supprimer(C.getidentifiant());

    MainWindow w;
    QMessageBox msgBox;
   if(test)
   {
     ui->tab_condidature ->setModel(C.afficher());
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("suppression avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }
   }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("echec de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    Condidature C ;
      int id=ui->lineEdit_id->text().toInt();
     QString nom=ui->lineEdit_nom->text();
     QString specialite=ui->lineEdit_spec->text();
     QString niveau=ui->lineEdit_niveau->text();

    Condidature C1(id,nom,specialite,niveau);
     //bool test= C.modifier(identifiant,nomt,specialite,niveauc);
      bool test;
      test= C1.modifier(id,nom,specialite,niveau);
     if (test)
         //[☺]
        {
         ui->tab_condidature->setModel(C1.afficher());
         QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                       QObject::tr("MODIFICATION avec succes .\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

         }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                       QObject::tr("UPDATE failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_trier_clicked()

{


    QSqlQueryModel* test=C.triparspecialite();
    QMessageBox msgBox;
        if(test){
            msgBox.setText("tri avec succes");
            ui->tab_condidature->setModel(C.triparspecialite());
        }
            else
            msgBox.setText(("echec"));

            msgBox.exec();
}




void MainWindow::on_rechercher_clicked()
{
    /*if(ui->CheckBox_identifiant->isChecked()){
      int identifiant=ui->ln_rechercher_identifiant->text().toInt();
       QSqlQueryModel* test=C.rechercher_identifiant(identifiant);
       QMessageBox msgBox;
           if(test){
               msgBox.setText("recherche avec succes");
               ui->tab_rech->setModel(C.rechercher_identifiant(identifiant));
           }
               else
               msgBox.setText(("condidature introuvable"));

               msgBox.exec();
       }
       else if(ui->checkBox_nomt->isChecked())
       {
          QString nomt=ui->ln_rechercher_nomt->text();
          QSqlQueryModel* test2=C.rechercher_nomt(nomt);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_nomt(nomt));
              }
                  else
                  msgBox.setText((" condidature introuvable"));

                  msgBox.exec();
       }
       else if(ui->checkBox_specialite->isChecked())
       {
          QString specialite=ui->ln_rechercher_specialite->text();
          QSqlQueryModel* test2=C.rechercher_specialite(specialite);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_specialite(specialite));
              }
                  else
                  msgBox.setText((" condidature introuvable"));

                  msgBox.exec();
       }
       else if((ui->checkBox_specialite->isChecked())&&(ui->checkBox_nomt->isChecked()))
       {
           QString nomt=ui->ln_rechercher_nomt->text();
          QString specialite=ui->ln_rechercher_specialite->text();
          QSqlQueryModel* test2=C.rechercher_nomtspecialite(nomt, specialite);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_nomtspecialite(nomt, specialite));
              }
                  else
                  msgBox.setText((" condidature introuvable"));

                  msgBox.exec();
       }
       else if((ui->CheckBox_identifiant->isChecked())&&(ui->checkBox_nomt->isChecked()))
       {
           QString nomt=ui->ln_rechercher_nomt->text();
          int identifiant=ui->ln_rechercher_identifiant->text().toInt();
          QSqlQueryModel* test2=C.rechercher_nomtidentifiant( identifiant,nomt);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_nomtidentifiant(identifiant,nomt));
              }
                  else
                  msgBox.setText(("client introuvable"));

                  msgBox.exec();
       }
       else if((ui->CheckBox_identifiant->isChecked())&&(ui->checkBox_specialite->isChecked()))
       {
           QString specialite=ui->ln_rechercher_specialite->text();
          int identifiant=ui->ln_rechercher_identifiant->text().toInt();
          QSqlQueryModel* test2=C.rechercher_specialiteidentifiant (identifiant,specialite);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_specialiteidentifiant(identifiant,specialite));
              }
                  else
                  msgBox.setText(("condidature introuvable"));

                  msgBox.exec();
       }
       else if((ui->CheckBox_identifiant->isChecked())&&(ui->checkBox_specialite->isChecked())&&(ui->checkBox_nomt->isChecked()))
       {
           QString nomt=ui->ln_rechercher_nomt->text();
           QString specialite=ui->ln_rechercher_specialite->text();
          int identifiant=ui->ln_rechercher_identifiant->text().toInt();
          QSqlQueryModel* test2=C.rechercher_specialiteidentifiantnomt(identifiant,specialite,nomt);
          QMessageBox msgBox;
              if(test2){
                  msgBox.setText("recherche avec succes");
                  ui->tab_rech->setModel(C.rechercher_specialiteidentifiantnomt( identifiant,specialite,nomt));
              }
                  else
                  msgBox.setText(("condidature introuvable"));

                  msgBox.exec();
       }*/

    QString nomt=ui->ln_rechercher_nomt->text();

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * FROM CONDIDATURE where nomt='"+nomt+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nomt"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));


        ui->tab_rech->setModel(model);

        qDebug() <<(model->rowCount());
}




//void MainWindow::on_statistique_currentChanged(int index)
//{
   // C.statistiques(ui->widget_2);
//}

void MainWindow::on_rechercher2_clicked()
{
    QString identifiant=ui->ln_rechercher_identifiant->text();

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * FROM CONDIDATURE where identifiant='"+identifiant+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nomt"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));


        ui->tab_rech->setModel(model);

        qDebug() <<(model->rowCount());
}

void MainWindow::on_rechercher3_clicked()
{
    QString specialite=ui->ln_rechercher_specialite->text();

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * FROM CONDIDATURE where specialite='"+specialite+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nomt"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialite"));


        ui->tab_rech->setModel(model);

        qDebug() <<(model->rowCount());
}



void MainWindow::on_pushButtonQrcode_clicked()
{


        QMessageBox msg;
              QItemSelectionModel * select = ui->tab_condidature->selectionModel();
                   msg.setText("Please select something");

                   msg.setIcon(msg.Critical);
                   msg.exec();
                   return;
              }
        int tabeq=ui->tab_condidature->currentIndex().row();
               //QVariant idd=ui->tab_client->model()->data(ui->tab_condidature->model()->index(tabeq,0));//selectionne le cin exactement
               QString identifiant= idd.toString();//convertir a une chaine
               QSqlQuery qry;//navigating and retrieving data from SQL queries which are executed on a QSqlDatabase.

               qry.prepare("select * from CLIENT where CIN=:id");//Prepares the SQL query  for execution. Returns true or false
               qry.bindValue(":identifiant",identifiant);//prendre valeur id et mettre dans table client
               qry.exec();//Executes a previously prepared SQL query
                  QString  NOMT,IDENTIFIANT,SPECIALITE,NIVEAUC;

               while(qry.next()){//prend des variable de la base de donnes

                   NOMT=qry.value(1).toString();
                  IDENTIFIANT =qry.value(2).toString();
                   SPECIALITE=qry.value(3).toString();
                  NIVEAUC=qry.value(4).toString();

               }
               identifiant=QString(identifiant);
                      identifiant="IDENTIFIANT:"+identifiant+"NOMT:"+NOMT+"SPECIALITE:"+SPECIALITE+"NIVEAUC:"+NIVEAUC+;//pendre la chaine a code
               QrCode qr = QrCode::encodeText(identifiant.toUtf8().constData(), QrCode::Ecc::HIGH);

               // Read the black & white pixels
               QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
               for (int y = 0; y < qr.getSize(); y++) {
                   for (int x = 0; x < qr.getSize(); x++) {
                       int color = qr.getModule(x, y);  // 0 for white, 1 for black

                       // You need to modify this part
                       if(color==0)
                           im.setPixel(x, y,qRgb(254, 254, 254));
                       else
                           im.setPixel(x, y,qRgb(0, 0, 0));
                   }
               }
               im=im.scaled(200,200);
               ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

    }
}
