#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "feedback.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cin->setMaxLength(8);
    ui->le_cin_2->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cin_2->setMaxLength(8);
    ui->cin_supp->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin_supp->setMaxLength(8);
    ui->le_avis->setValidator(new QIntValidator(0, 5, this));
    ui->le_avis->setMaxLength(1);
    ui->le_avis_2->setValidator(new QIntValidator(0, 5, this));
    ui->le_avis_2->setMaxLength(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString domaine=ui->le_domaine->text();
    int avis=ui->le_avis->text().toInt();
    Feedback F(cin,nom,domaine,avis);

    bool test=F.ajouter();

    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    int cin,avis;
    QString nom,domaine;
    cin=ui->le_cin_2->text().toInt();
    nom=ui->le_nom_2->text();
    domaine=ui->le_domaine_2->text();
    avis=ui->le_avis_2->text().toInt();

    QSqlQuery qry;
    QString cin_string=QString::number(cin);
    QString avis_string=QString::number(avis);
          qry.prepare("update FEEDBACK set cin='"+cin_string+"', nom='"+nom+"', domaine='"+domaine+"', avis='"+avis_string+"' where cin='"+cin_string+"'");

    if(qry.exec())
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectué.\n"
                                          "Click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    int cin;
    cin=ui->cin_supp->text().toInt();

    QSqlQuery qry;
    QString cin_string=QString::number(cin);
          qry.prepare("Delete from FEEDBACK where cin='"+cin_string+"'");

    if(qry.exec())
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Supression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Supression non effectué.\n"
                                          "Click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_afficher_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlDatabase db;
    QSqlQuery* qry=new QSqlQuery(db);

    qry->prepare("select * from FEEDBACK");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() <<(modal->rowCount());
}
