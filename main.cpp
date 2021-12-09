#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //-----------------------------------------TRADUCTION-----------------------------------------//

    QTranslator t;
    QStringList languages;
    languages << "Français" << "Anglais"  ;
    QString lang = QInputDialog::getItem(NULL,"Veuillez choisir la langue", "Langue", languages);

    if (lang != "Français")
    {
        a.installTranslator(&t);
    }

    else if  (lang == "Anglais")
    {
        t.load(":/english.qm");
    }


    //--------------------------------------------------------------------------------------------//

    Connection c;
    bool test=c.createconnect();
     MainWindow w;

     w.setWindowTitle("Space Recruiting ");
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
