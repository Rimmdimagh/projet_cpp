#include "mainwindow.h"
#include "Matriel.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QDateEdit>
#include <QComboBox>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QTextStream>
#include"smtp.h"
#include <QPixmap>
#include "ui_mainwindow.h"

using namespace QtCharts;

QString rep;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QFile file("C:/Users/HP/Downloads/smart_recrruiting_help_center_2A14-GestionMaintenance/crud/historique.txt");
          if (!file.open(QIODevice::ReadOnly))
          {
              QMessageBox::information(0,"info",file.errorString());
          }
          QTextStream in (&file);
         ui->hist->setText(in.readAll());

    //CONTROLE DE SAISIE
    ui->id->setValidator(new QIntValidator (0, 99999999, this));
  //quantite
    ui->nom->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));//nom
    ui->reference->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));//reference
    ui->id_supp->setValidator(new QIntValidator (0, 99999999, this));

    //COMBO BOX marque
    ui->marque->addItem("choix de marque");
    ui->marque->addItem(QIcon("//ken nheb nhut taswira"),"Brother");
    ui->marque->addItem("HP");
    ui->marque->addItem("MACOS");
    ui->marque->addItem("Asus");
    ui->marque->addItem("Samsung");
//pour le remplir de tableau dans l iterface graphique
    ui->tab_mat->setModel(Mat.afficher());
    //combobox categorie
     ui->categorie->addItem("choix de catégorie");
      ui->categorie->addItem("matériel informatique");
  ui->categorie->addItem("matériel burautique");
  ui->categorie->addItem("matériel d'entretien");
  ui->categorie->addItem("réfrégirateur");



}


//ajouter
void MainWindow::on_pushButtonAjouter_clicked()
{
    QSqlQuery query;
    if(ui->radioButton->isChecked()==true)
        rep="marche";
    else
        if(ui->radioButton_2->isChecked()==true)
            rep="panne";
    query.prepare ("INSERT INTO MATRIEL (promotion) "
                   "VALUES (rep)");

   int id=ui->id->text().toInt();//convertir l id de chaine de car vers un entier w baaed thutha
   QString nom=ui->nom->text();
   QString reference =ui->reference->text();
   QString marque=ui->marque->currentText();
   QString categorie=ui->categorie->currentText();
   QString etat=rep;
   QString mail=ui->mail->text();
   QDate miseFab=ui->miseFab->date();
   QDate miseFonc=ui->miseFonc->date();
    Matriel m(id,nom,reference,marque,categorie,etat,mail,miseFab,miseFonc);

    if (id==NULL)
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id!!!!") ;
             QMessageBox::critical(0, qApp->tr("Ajout"),

                             qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

         }

      else if (nom==NULL)
       {

           QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
           QMessageBox::critical(0, qApp->tr("Ajout"),

                           qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

       }
    else if (reference==NULL)
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP reference!!!!") ;
         QMessageBox::critical(0, qApp->tr("Ajout"),

                         qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

     }




else{
bool test=m.ajouter();//test de ajouter

QFile file("C:/Users/HP/Downloads/smart_recrruiting_help_center_2A14-GestionMaintenance/crud/historique.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="Vous avez ajouté un matériel\n";
        cout << message2;
        QFile file("C:/Users/HP/Downloads/smart_recrruiting_help_center_2A14-GestionMaintenance/crud/historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->hist->setText(in.readAll());
    ui->tab_mat->setModel(Mat.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("matèriel ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("matèriel non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);





    }
ui->id->clear();
ui->nom->clear();
ui->reference->clear();
ui->mail->clear();


}











//supprimer
void MainWindow::on_supp_clicked()
{
    int id=ui->id_supp->text().toInt();//ajout ta3 id f id_supp

bool test =Mat.supprimer(id);//supprimer selon l id
//QMessageBox msgBox;
if (test)
        {


        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Suppression effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);

 //ken tfskht bch ysir refresh de mon tableau
           ui->tab_mat->setModel(Mat.afficher());
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);


ui->id_supp->clear();
}




//modifier

void MainWindow::on_modifier_clicked()
{
   QSqlQuery query;
    if(ui->radioButton->isChecked()==true)
        rep="marche";
    else
        if(ui->radioButton_2->isChecked()==true)
            rep="panne";

    query.prepare ("INSERT INTO matriel (etat) " "VALUES (rep)");

    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString reference=ui->reference->text();
    QString marque=ui->marque->currentText();
    QString categorie=ui->categorie->currentText();
    QString etat=rep;
    QString mail=ui->mail->text();
    QDate miseFab=ui->miseFab->date();
    QDate miseFonc=ui->miseFonc->date();


        Matriel m(id,nom,reference,marque,categorie,etat,mail,miseFab,miseFonc);
        bool test=m.modifier(id,nom,reference,marque,categorie,etat,mail,miseFab,miseFonc);
    if (test)
    {
        //actualiser

        ui->tab_mat->setModel(Mat.afficher());

        QMessageBox::information(nullptr, QObject::tr("modifier matériel"),
                          QObject::tr("Matériel modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }

          else
              QMessageBox::critical(nullptr, QObject::tr("modifier un matériel"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    ui->id->clear();
    ui->nom->clear();
    ui->reference->clear();
    ui->mail->clear();
    }



void MainWindow::on_recherche_clicked()
{

    QString reference =ui->rech->text();
    /*QString mail =ui->rech->text();
    QString marque =ui->rech->text();*/

       ui->tab_mat->setModel(Mat.rechercher(reference));
      /* ui->tab_mat->setModel(Mat.rechercher1(mail));
       ui->tab_mat->setModel(Mat.rechercher2(marque));*/
ui->rech->clear();

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from MATRIEL where MARQUE='Brother' ");
         int number1=model->rowCount();

         model->setQuery("select * from MATRIEL where MARQUE='HP' ");
         int number2=model->rowCount();

         model->setQuery("select * from MATRIEL where MARQUE='Samsung' ");
         int number3=model->rowCount();

         model->setQuery("select * from MATRIEL where MARQUE='MACOS' ");
         int number4=model->rowCount();

         model->setQuery("select * from MATRIEL where MARQUE='Asus' ");
         int number5=model->rowCount();


         int total=number1+number2+number3+number4+number5;

         QString a = QString("brother  "+QString::number((number1*100)/total,'f',2)+"%" );
         QString b = QString("HP  "+QString::number((number2*100)/total,'f',2)+"%" );
         QString c = QString(" samsung "+QString::number((number3*100)/total,'f',2)+"%" );
         QString d = QString(" MACOS "+QString::number((number4*100)/total,'f',2)+"%" );
         QString e = QString(" Asus "+QString::number((number5*100)/total,'f',2)+"%" );

         QPieSeries *series = new QPieSeries();
         series->append(a,number1);
         series->append(b,number2);
         series->append(c,number3);
          series->append(d,number4);
           series->append(e,number5);

         if (number1!= 0)
         {
             QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());
         }
         if (number2!=0)
         {
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
         }
         if(number3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
         if(number4!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice3 = series->slices().at(3);
                  //slice1->setExploded();
                  slice3->setLabelVisible();
         }
         if(number5!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice4 = series->slices().at(4);
                  //slice1->setExploded();
                  slice4->setLabelVisible();
         }


                 // Create the chart widget
                 QChart *chart = new QChart();

                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle("Pourcentage Par MARQUE : Nombre Des quantite de marque "+ QString::number(total));

                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(800,500);
                 chartView->show();

    }




/*
void MainWindow::on_mail_2_clicked()
{

    QItemSelectionModel *select = ui->tab_mat->selectionModel();

    QString email_recipient = select->selectedRows(5).value(0).data().toString();
    QString nom_recipient = select->selectedRows(1).value(0).data().toString();
    QString prenom_recipient = select->selectedRows(2).value(0).data().toString();

    QDialog * d=new Dialog(email_recipient,nom_recipient,prenom_recipient,this);
    d->show();
    d->exec();
}

*/


void MainWindow::on_send_mail_clicked()
{

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());



}


void MainWindow::on_reset_2_clicked()
{


        ui->id->setText("");
        ui->nom->setText("");
        ui->reference->setText("");
        ui->mail->setText("");


}

void MainWindow::on_reaficher_clicked()
{
    ui->rech->setText("");
    ui->tab_mat->setModel(Mat.afficher());

}

void MainWindow::on_reset_3_clicked()
{
    ui->rcpt->setText("");
    ui->subject->setText("");
    ui->msg->setPlainText("");


}
/*
void MainWindow::on_envoi_M_clicked()
{
    QMessageBox msgBox;

       int id=ui->ID->text().toInt();
       QString panne=ui->panne->text();
       QString cause=ui->cause->setPlainText();

       Matriel CC(id,panne,cause);
      int commande1=CC.verifiercolis(colis);//verifier est ce que le colis est affecte a une commande
      int refclient1=CC.verifcommandeidclient(commande1);// si oui return id de ce client
      int refclient=CC.verifcommandeidclient(commande); // return id de client de commande a affecter
      bool test2=CC.verifiercommandeaff(commande);  //si cette commande est deja affecte ou pas
               if(test2==false&&CC.verifiercolis(colis)==0)
              {CC.affecteruncolis();
                 msgBox.setText("Affectation avec succes.");}
              else if(test2==false&&(refclient==refclient1))
              {CC.affecteruncolis();
               msgBox.setText("Affectation avec succes.");}
               else
               { msgBox.setText("Echec de Affectation ");
               }
         msgBox.exec();
}
*/



void MainWindow::on_pushButton_clicked()
{


        int id=ui->id_combo->currentText().toInt();
        int ide=ui->combo_person->currentText().toInt();


        Matriel m1;
        bool test=m1.modifier_e(id,ide);


        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Afecter une matriel"),
                              QObject::tr("matriel Affecte.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
   ui->id_combo->clear();
   ui->id_combo->addItems(Mat.recherche_t());
   ui->combo_person->clear();
   ui->combo_person->addItems(Mat.recherche_t1());
}
/*
void MainWindow::on_pushButton_deconnexio_clicked()
{
      ui->pushButton_deconnexio->hide();
        ui->pushButton_quitter->hide();
        emit clicLoginmatriel();

}

void MainWindow::on_pushButton_quitter_clicked()
{
     emit clicClosematriel();
}
*/
