#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"

#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>

#include "QrCode.hpp"
#include <QSqlQueryModel>

#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>

#include"smtp.h"


using namespace QtCharts;


using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tab_for->setModel(Etmp.afficher()); // UPDATE ECRAN D'AFFICHAGEE

    ui->CODE_FORMATION->setMaxLength(12); //FORMATAGE D'AFFICHAGE
    ui->NOM_ENCADREUR->setMaxLength(20);
    ui->NOM_FOR->setMaxLength(20);
    ui->TYPE_FOR->setMaxLength(12);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAjouter_clicked()
{
    QString  code_formation=ui->CODE_FORMATION->text();
    int dure_for=ui->DURE_FOR->text().toInt();
    QString nom_for=ui->NOM_FOR->text();
   QString nom_encadreur=ui->NOM_ENCADREUR->text();
   QString type_for=ui->TYPE_FOR->text();



    Formation f(code_formation,nom_for,nom_encadreur,dure_for,type_for);
bool test=f.ajouter();
if (test)
        { //Actualiser
     ui->tab_for->setModel(Etmp.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_supp_clicked()
{
    Formation f1;
   // f1.setcode_formation(ui->code_supp->text());
     //bool test=Etmp.supprimer(f1.get_code_formation());

    QString code_for=ui->code_supp->text();
    bool test=Etmp.supprimer(code_for);

    QMessageBox msgBox;
        if (test)
                {
            //actualiser
             ui->tab_for->setModel(Etmp.afficher());
                QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                   QObject::tr("Suppression effectué\n"
                                                               "click cancel to exit."),QMessageBox::Cancel);
                }
            else
            ui->tab_for->setModel(Etmp.afficher());
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectué.\n"
                                                  "click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_Mod_2_clicked()
{
    QString  code_formation=ui->CODE_FORMATION->text();
    int dure_for=ui->DURE_FOR->text().toInt();
    QString nom_for=ui->NOM_FOR->text();
   QString nom_encadreur=ui->NOM_ENCADREUR->text();
   QString type_for=ui->TYPE_FOR->text();
          Formation f(code_formation,nom_for,nom_encadreur,dure_for,type_for);
          bool test=f.modifier(code_formation,nom_for,nom_encadreur,type_for,dure_for);
          if (test)
                  { //Actualiser
               ui->tab_for->setModel(Etmp.afficher());
                  QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                     QObject::tr("modification effectué\n"
                                                                 "click cancel to exit."),QMessageBox::Cancel);
                  }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                        QObject::tr("modification non effectué.\n"
                                                    "click Cancel to exit."),QMessageBox::Cancel);
 }


void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->code_supp->text();
        ui->tab_for->setModel(Etmp.rechercher(rech));
}

void MainWindow::on_trier_button_clicked()
{

        Formation *f = new Formation();
        ui->tab_for->setModel(f->tri());

}


void MainWindow::on_qrcodegen_clicked()
{
    int tabeq=ui->tab_for->currentIndex().row();
           QVariant idd=ui->tab_for->model()->data(ui->tab_for->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from Formation where CODE_FORMATION=:id");
           qry.bindValue(":CODE_FORMATION",id);
           qry.exec();
              QString  iden,nom_for,nom_encadreur,type_for,dure_for,ide;

           while(qry.next()){

               id=qry.value(1).toString();
               nom_for=qry.value(2).toString();
               nom_encadreur=qry.value(3).toString();
               type_for=qry.value(4).toString();
               dure_for=qry.value(5).toString();


           }
           ide=QString(id);
                  ide="CODE_FORMATION:"+ide+"NOM_FOR:"+iden+"NOM_ENCADREUR:"+nom_encadreur+"TYPE_FOR:"+type_for,"DURE_FOR:"+dure_for;
           QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

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


// stat sur les destinations
void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from Formation where TYPE_FOR='info' ");
     int number1=model->rowCount();
     model->setQuery("select * from Formation where TYPE_FOR='maths' ");
     int number2=model->rowCount();
     model->setQuery("select * from Formation where TYPE_FOR='electrique' ");
     int number3=model->rowCount(); // calculer le nombre de voyage pour hammem lif
     model->setQuery("select * from Formation where TYPE_FOR='Autre' ");
     int number4=model->rowCount();
     int total=number1+number2+number3+number4;
     QString a = QString("info  "+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("maths "+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("electrique    "+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("autre "+QString::number((number4*100)/total,'f',2)+"%" );
     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
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
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("pourcentage sur les types "+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}




void MainWindow::on_radioButton_croissant_clicked()
{
       ui->tab_for->setModel(Etmp.tri());
}

void MainWindow::on_radioButton_dcroissant_clicked()
{ 
       ui->tab_for->setModel(Etmp.trid());
}



void MainWindow::on_rechercher_button_2_clicked()
{
    QString  code_formation=ui->CODE_FORMATION->text();
    int dure_for=ui->DURE_FOR->text().toInt();
    QString nom_for=ui->NOM_FOR->text();
   QString nom_encadreur=ui->NOM_ENCADREUR->text();
   QString type_for=ui->TYPE_FOR->text();

          Formation f(code_formation,nom_for,nom_encadreur,dure_for,type_for);
          int pin_for = f.Pin_rand();
          bool test=f.modifier_2(code_formation,nom_for,nom_encadreur,type_for,dure_for,pin_for);
          if (test)
                  { //Actualiser
               ui->tab_for->setModel(Etmp.afficher());
                  QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                     QObject::tr("Pin effectué\n"
                                                                 "click cancel to exit."),QMessageBox::Cancel);
                  }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                        QObject::tr("modification non effectué.\n"
                                                    "click Cancel to exit."),QMessageBox::Cancel);

}

/////////////////////////////////////////////////////////

void MainWindow::on_ImportPDF_clicked()
{
    QString strStream;
     QTextStream out(&strStream);

     const int rowCount = ui->tab_for->model()->rowCount();
     const int columnCount = ui->tab_for->model()->columnCount();

     out <<  "<html>\n"
             "<head>\n"
             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("Title")
           <<  "</head>\n"
            <<"<body bgcolor=#ffffff link=#5000A0>\n"

            //     "<align='right'> " << datefich << "</align>"
            <<"<center> <H1>Liste des animaux </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


     // headers
     out << "<thead><tr bgcolor=#f0f0f0>";
     for (int column = 0; column < columnCount; column++)
         if (!ui->tab_for->isColumnHidden(column))
             out << QString("<th>%1</th>").arg(ui->tab_for->model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     // data table
     for (int row = 0; row < rowCount; row++) {
         out << "<tr>";
         for (int column = 0; column < columnCount; column++) {
             if (!ui->tab_for->isColumnHidden(column)) {
                 QString data = ui->tab_for->model()->data(ui->tab_for->model()->index(row, column)).toString().simplified();
                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
             }
         }
         out << "</tr>\n";
     }
     out <<  "</table>\n"
             "</body>\n"
             "</html>\n";



         QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
         if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
         QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
         printer->setOutputFormat(QPrinter::PdfFormat);
         printer->setPaperSize(QPrinter::A4);
         printer->setOutputFileName(fileName);

         QTextDocument doc;
         doc.setHtml(strStream);
         doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
         doc.print(printer);

         QPrinter *p=new QPrinter();
         QPrintDialog dialog(p,this);
         if(dialog.exec()== QDialog::Rejected)
         {
             return;
         }
}


void MainWindow::on_insererphoto_clicked()
{
   QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
   if (QString::compare(filename,QString()) !=0)
   {
       QImage image;
       bool valid = image.load(filename);
       if(valid)
       {
           image=image.scaledToWidth(ui->lbl_image->width(), Qt::SmoothTransformation);
                   ui->lbl_image->setPixmap(QPixmap::fromImage(image));
       }
       else
       {
           //ERROR HANDLING
       }
   }
}

void MainWindow::on_send_mail_clicked()
{

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());
}




void MainWindow::on_reset_3_clicked()
{
    ui->rcpt->setText("");
    ui->subject->setText("");
    ui->msg->setPlainText("");


}
