#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include "qrcode.hpp"
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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include"smtp.h"
#include "formation.h"
#include "matriel.h"
#include <QPixmap>
#include <QMediaPlayer>
#include<entretien.h>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include "signup.h"
#include<QString>
#include<QStatusBar>
#include "arduino.h"
#include <QSound>
using namespace qrcodegen;
using namespace QtCharts;

QString rep;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /***********************sound**************************/



    QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/welcome.wav");
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(1500);
    timer->start();
    connect(timer, &QTimer::timeout, []() { QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/hello.wav"); });




    /***************************************************/
    ui->tab_personnel->setModel(p.afficher());
    ui->tab_for->setModel(Etmp.afficher());
    ui->tab_mat->setModel(Mat.afficher());
   QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(page2Widget()) );
   QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(page3Widget()) );
   QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT (page8Widget()) );
   QObject::connect(ui->pushButton_12,SIGNAL(clicked()),this, SLOT (page9Widget()) );
   QObject::connect(ui->configuration,SIGNAL(clicked()),this, SLOT (page10Widget()) );
    
    QPixmap pix("C:/Users/HP/Downloads/intg/img");
    //ui->pic->setPixmap(pix.scaled(1000,1000,Qt::KeepAspectRatio));
/*********************************matriel****************************************/
   setFixedSize(1200,1500);



      QFile file("C:/Users/HP/Downloads/intg/historique.txt");
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

      //combobox categorie
       ui->categorie->addItem("choix de catégorie");
        ui->categorie->addItem("matériel informatique");
    ui->categorie->addItem("matériel burautique");
    ui->categorie->addItem("matériel d'entretien");
    ui->categorie->addItem("réfrégirateur");


    //salma
    ui->stackedWidget->setCurrentIndex(0);

/*

    int ret=Ard.connect_arduino();
        switch(ret){
        case(0):qDebug()<<"arduino is available and connected to: "<< Ard.getarduino_port_name();
        break;
        case(1):qDebug()<<"arduino is available but not connected to "<< Ard.getarduino_port_name();
        break;
        case(-1):qDebug()<<"arduino is not available ";
        }
        QObject::connect(Ard.getserial(),SIGNAL(readyRead()),this,SLOT(detect()));
*/

    // PARTIE CITATION ALEATOIRE

    srand(time(NULL)); // Initialisation de la donnée seed
    nombre = rand() % (10);
    if(nombre==0)
    ui->citation->setText("NOTRE VIE VAUT CE QU'ELLE NOUS A COUTE.");
    else if(nombre==1)
        ui->citation->setText("VOUS TROUVEREZ LA CLE DU SUCCES SOUS LE REVEILLE-MATIN.");
    else if(nombre==2)
        ui->citation->setText("Là OU SE TROUVE UNE VOLONTE, IL EXISTE UN CHEMIN.");
    else if(nombre==3)
        ui->citation->setText("LE FRUIT DU TRAVAIL EST LE PLUS DOUX DES PLAISIRS.");
    else if(nombre==4)
        ui->citation->setText("C'EST MAINTENANT LE TEMPS DE TRAVAILLER ENCORE PLUS DUR.");
    else if(nombre==5)
        ui->citation->setText("NE RÊVE PAS, FAIS-LE.");
    else if(nombre==6)
        ui->citation->setText("LES GAGNANTS TROUVENT LES MOYENS, LES PERDANTS DES EXCUSES.");
    else if(nombre==7)
        ui->citation->setText("LA MOTIVATION ET LE TRAVAIL SONT LA CLE DU SUCCES.");
    else if(nombre==8)
        ui->citation->setText("PRENEZ SOINS DE NOS CLIENTS.");
    else if(nombre==9)
        ui->citation->setText("LES PORTES DE L'AVENIR SONT OUVERTES A CEUX QUI SAVENT LES POUSSER.");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*************************************PERSONNEL******************************************/

void MainWindow::on_pb_Ajouter_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    int cin = ui->p_CIN->text().toInt();
    QString prenom =ui->p_PRENOM->text();
    QString nom=ui->p_NOM->text();
    QString adresse= ui->p_ADRESSE->text();
    QString adresseMail=ui->p_MAIL->text();
    int telephone =ui->p_TELEPHONE->text().toInt();
    int dureeTravail=ui->p_DUREE->text().toInt();
    int age= ui->p_age->text().toInt();
    QString message="";


  Personnel P(cin,telephone,dureeTravail,age,nom,prenom,adresse,adresseMail,message);



bool test=P.ajouter();
if (test)
        { //Actualiser

        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_Supprimer_clicked()
{
    Personnel p1;

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    p1.setcin(ui->L_cin_supp->text().toInt());
    bool test=p1.supprimer(p1.getcin());
    if (test)
            { //Actualiser

            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("supression effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            ui->tab_personnel->setModel((p.afficher()));
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("suppression non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_pb_modifier_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

    int cin = ui->line_cin ->text().toInt();
    int telephone = ui->line_telephone ->text().toInt();
    int dureeTravail = ui->line_dureeTravail->text().toInt();
    int age = ui->line_age ->text().toInt();
    QString adresse= ui->line_adresse->text();
    QString adresseMail= ui->line_adresseMail->text();
    QString nom= ui->line_nom->text();
    QString prenom= ui->line_prenom->text();
    QString message ="";


      Personnel p(telephone,dureeTravail,cin,age,adresse,adresseMail,nom,prenom,message);
      bool test=p.modifier(age,cin,telephone,dureeTravail,nom,prenom,adresse,adresseMail,message);
      if(test)
    {

          ui->tab_personnel->setModel(p.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Agence modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_p_trier_clicked()
{
   Personnel *p;
   ui->tab_personnel->setModel(p->tri());

   QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

}





void MainWindow::on_qrcodegen_2_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    int tabeq=ui->tab_personnel->currentIndex().row();
           QVariant idd=ui->tab_personnel->model()->data(ui->tab_personnel->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from PERSON where CIN=:cin");
           qry.bindValue(":CIN",id);
           qry.exec();
              QString  cin,ide,nom,prenom,adresse,adresseMail,telephone,dureeTravail,age,message;

           while(qry.next()){

               id=qry.value(1).toString();
               nom=qry.value(2).toString();
               prenom=qry.value(3).toString();
               adresse=qry.value(4).toString();
               adresseMail=qry.value(5).toString();
               telephone=qry.value(6).toString();
               dureeTravail=qry.value(7).toString();
               age=qry.value(8).toString();
               message=qry.value(9).toString();


           }
           ide=QString(id);
                  ide="CIN:"+cin+"NOM:"+nom+"PRENOM:"+prenom,"ADRESSE:"+adresse,"ADRESSEMail:"+adresseMail,"TELEPHONE:"+telephone,"DUREETRAVAIL:"+dureeTravail,"AGE:"+age,"MESSAGE:"+message;
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

void MainWindow::on_pushButton_encrypt_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

    QString plainText = ui->plainTextEdit_plain->toPlainText();
    QString encryptedText = "to be implemented";

    if(ui->comboBox->currentIndex() == 0)
    {
        int key = ui->lineEdit_CC_key->text().toInt();
        encryptedText = ewCaesarCipher(plainText, key);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        QString secret = ui->lineEdit_PF_Secret->text();
        encryptedText = ewPlayfair(plainText, secret);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        QString key = ui->lineEdit_DES_key->text();
        encryptedText = ewDES(plainText, key.toStdString());
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
        double p = ui->RSA_lineEdit_p->text().toDouble();
        double q = ui->RSA_lineEdit_q->text().toDouble();
        double dbl = ewRSA(plainText.toDouble(), p, q);

        std::ostringstream strs;
        strs << dbl;
        encryptedText = QString::fromStdString(strs.str());

        std::pair<double, double> pair = RSAKeys(p, q);
        std::ostringstream strPrK;
        strPrK << pair.first;
        ui->RSA_lineEdit_prkey->setText(QString::fromStdString(strPrK.str()));
        std::ostringstream strPuK;
        strPuK << pair.second;
        ui->RSA_lineEdit_pukey->setText(QString::fromStdString(strPuK.str()));
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        QString key = ui->lineEdit_rc4_key->text();
        encryptedText = ewRC4(plainText, key);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
        QString key = ui->lineEdit_DES_key->text();
        encryptedText = ewIDES(plainText, key.toStdString());
    }
    ui->plainTextEdit_encrypted->document()->setPlainText(encryptedText);
}

void MainWindow::on_pushButton_decrypt_clicked()
{
    QString encryptedText = ui->plainTextEdit_encrypted->toPlainText();
    QString plainText = "to be implemented";

    if(ui->comboBox->currentIndex() == 0)
    {
        int key = ui->lineEdit_CC_key->text().toInt();
        plainText = dwCaesarCipher(encryptedText, key);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        QString secret = ui->lineEdit_PF_Secret->text();
        plainText = dwPlayfair(encryptedText, secret);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        QString key = ui->lineEdit_DES_key->text();
        plainText = dwDES(encryptedText, key.toStdString());
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
        double p = ui->RSA_lineEdit_p->text().toDouble();
        double q = ui->RSA_lineEdit_q->text().toDouble();

        std::ostringstream pstr;
        pstr << dwRSA(encryptedText.toDouble(), p, q);
        plainText = QString::fromStdString(pstr.str());
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        QString key = ui->lineEdit_rc4_key->text();
        plainText = dwRC4(encryptedText, key);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
        QString key = ui->lineEdit_DES_key->text();
        plainText = dwIDES(encryptedText, key.toStdString());
    }
    ui->plainTextEdit_plain->document()->setPlainText(plainText);
}

void MainWindow::on_actionReset_Fields_triggered()
{
    ui->plainTextEdit_plain->clear();
    ui->plainTextEdit_encrypted->clear();
    ui->lineEdit_CC_key->clear();
}

void MainWindow::on_actionClear_Plain_Text_triggered()
{
    ui->plainTextEdit_plain->clear();
}

void MainWindow::on_actionClear_Encrypted_Text_triggered()
{
    ui->plainTextEdit_encrypted->clear();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Caesar Cipher")
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(arg1 == "Playfair")
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(arg1 == "DES")
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(arg1 == "RSA")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(arg1 == "RC4")
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(arg1 == "DES with Text")
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
}





// Caesar Cipher Methods

QString MainWindow::ewCaesarCipher(QString plainText, int key)
{
    std::string result = "";
    std::string plainStdText = plainText.toStdString();

    for (int i=0;i<plainText.length();i++)
    {
        if(plainStdText[i] == ' ')
        {
            result += ' ';
        }
        else if(std::isalpha(plainStdText[i]))
        {
            if (std::isupper(plainStdText[i]))
                result += char(int(plainStdText[i]+key-65)%26 +65);
            else
                result += char(int(plainStdText[i]+key-97)%26 +97);
        }
    }

    return QString::fromStdString(result);
}

QString MainWindow::dwCaesarCipher(QString encryptedText, int key)
{
    return ewCaesarCipher(encryptedText, 26-key);
}





// playfair Methods

QString MainWindow::ewPlayfair(QString plainText, QString secret)
{
    std::string plainStdText = plainText.toStdString();
    std::string secretStdText = secret.toStdString();

    normalizePFSecret(secretStdText);
    populatePFMatrix(secretStdText);
    normalizePFString(plainStdText);

    std::string encryptedText = encryptPFString(plainStdText);

    return QString::fromStdString(encryptedText);
}

QString MainWindow::dwPlayfair(QString encryptedText, QString secret)
{
    std::string encryptedStdText = encryptedText.toStdString();
    std::string secretStdText = secret.toStdString();

    normalizePFSecret(secretStdText);
    populatePFMatrix(secretStdText);

    std::string plainText = decryptPFString(encryptedStdText);

    return QString::fromStdString(plainText);
}

bool MainWindow::inSameRow(Position p1, Position p2)
{
    if(p1.x == p2.x)
        return true;
    return false;
}

bool MainWindow::inSameColumn(Position p1, Position p2)
{
    if(p1.y == p2.y)
        return true;
    return false;
}

void MainWindow::normalizePFString(std::string &str)
{
    std::string pure_str= "";
    // remove any non-alphabetical characters
    // convert string to lower case
    for(int i=0;i<str.size();++i)
    {
        if(isalpha(str[i]))
        {
            if(std::isupper(str[i]))
                str[i] = std::tolower(str[i]);
            pure_str += str[i];
        }
    }

    // separate duplicate characters
    for(int i=0 ; i<pure_str.size()-1 ; i+=2)
    {
        if(pure_str[i] == pure_str[i+1])
            pure_str.insert(pure_str.begin()+i+1, 'x');
    }

    // make string even
    if(pure_str.size()%2 !=0)
        pure_str += 'x';

    str = pure_str;
}

std::string MainWindow::encryptPFString(std::string plainStdText)
{
    std::string result = "";

    for(int i=0;i<plainStdText.size(); i+=2)
    {
        Position p1 = findPositionByChar(plainStdText[i]);
        Position p2 = findPositionByChar(plainStdText[i+1]);

        if(inSameRow(p1, p2))
        {
            if(p1.y == 4)
                p1.y = 0;
            else
                p1.y +=1;

            if(p2.y == 4)
                p2.y = 0;
            else
                p2.y +=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else if(inSameColumn(p1, p2))
        {
            if(p1.x == 4)
                p1.x = 0;
            else
                p1.x +=1;

            if(p2.x == 4)
                p2.x = 0;
            else
                p2.x +=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else
        {
            Position t1, t2;

            t1.x = p1.x;
            t1.y = p2.y;

            t2.x = p2.x;
            t2.y = p1.y;

            result += findCharByPosition(t1);
            result += findCharByPosition(t2);
        }
    }

    return result;
}

std::string MainWindow::decryptPFString(std::string encryptedStdText)
{
    std::string result = "";

    for(int i=0;i<encryptedStdText.size(); i+=2)
    {
        Position p1 = findPositionByChar(encryptedStdText[i]);
        Position p2 = findPositionByChar(encryptedStdText[i+1]);

        if(inSameRow(p1, p2))
        {
            if(p1.y == 0)
                p1.y = 4;
            else
                p1.y -=1;

            if(p2.y == 0)
                p2.y = 4;
            else
                p2.y -=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else if(inSameColumn(p1, p2))
        {
            if(p1.x == 0)
                p1.x = 4;
            else
                p1.x -=1;

            if(p2.x == 0)
                p2.x = 4;
            else
                p2.x -=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else
        {
            Position t1, t2;

            t1.x = p1.x;
            t1.y = p2.y;

            t2.x = p2.x;
            t2.y = p1.y;

            result += findCharByPosition(t1);
            result += findCharByPosition(t2);
        }
    }

    return result;
}

void MainWindow::normalizePFSecret(std::string &secret)
{
    std::string result = "";
    secret += "abcdefghiklmnopqrstuvwxyz";
    for(int i=0;i<secret.size();++i)
    {
        if(result.find(secret[i]) == std::string::npos)
            result += secret[i];
    }
    secret = result;
}

void MainWindow::populatePFMatrix(std::string secret)
{
    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5 ; ++j)
        {
            pfMatrix[i][j] = secret[j+5*i];
        }
    }
}

Position MainWindow::findPositionByChar(char ch)
{
    Position p;

    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            if(pfMatrix[i][j] == ch)
            {
                p.x = i;
                p.y = j;
            }
        }
    }

    return p;
}

char MainWindow::findCharByPosition(Position p)
{
    return pfMatrix[p.x][p.y];
}





// data 0000000100100011010001010110011110001001101010111100110111101111
// key  0001001100110100010101110111100110011011101111001101111111110001

// DES Methods

QString MainWindow::ewDES(QString plainText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);

    QString encryptedText = DESEncryption(plainText.toStdString(), keys);

    return encryptedText;
}

QString MainWindow::dwDES(QString encryptedText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);

    std::reverse(keys.begin(), keys.end());

    QString plainText = DESEncryption(encryptedText.toStdString(), keys);

    return plainText;
}

std::vector< std::string > MainWindow::keyPreparation(std::string key)
{
    // 0001001100110100010101110111100110011011101111001101111111110001

    std::string permutedKey = "";
    int PC1_permutations[56] = {
        57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
    };

    for(int i=0;i<56; ++i)
    {
        permutedKey += key[PC1_permutations[i]-1];
    }

//    std::cout << key << std::endl;
//    std::cout << permutedKey << std::endl;
//    std::cout << permutedKey.length() << std::endl;


    int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    std::vector< std::pair<std::string, std::string> > keys;

    std::string C0 = permutedKey.substr(0,28);
    std::string D0 = permutedKey.substr(28,56);

//    std::cout << "C0 : " << C0 << std::endl;
//    std::cout << "D0 : " << D0 << std::endl;

    keys.push_back(std::make_pair(C0, D0));

    for(int i=1 ; i<17 ; ++i)
    {
        std::string C = keys[i-1].first;
        std::string D = keys[i-1].second;

        C = C.substr(shifts[i-1], C.length()) + C.substr(0, shifts[i-1]);
        D = D.substr(shifts[i-1], D.length()) + D.substr(0, shifts[i-1]);

        keys.push_back(std::make_pair(C, D));

//        std::cout << "C" << i << " : " << C << std::endl;
//        std::cout << "D" << i << " : " << D << std::endl;
    }


    int PC2_permutations[48] = {
        14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
    };

    std::vector<std::string> finalKeys;

    for(int i=0;i<16;++i)
    {
        std::string k = keys[i+1].first + keys[i+1].second;
        std::string fk = "";

        for(int j=0;j<48;++j)
        {
            fk += k[PC2_permutations[j]-1];
        }
        finalKeys.push_back(fk);
//        std::cout << fk << std::endl;
    }

    std::cout << std::endl << ">[BEGIN] Keys generated Successfully" << std::endl << std:: endl;

    for(int i=0; i<finalKeys.size(); ++i)
    {
        std::cout << "Key " << i+1 << ": " << finalKeys[i] << std::endl;
    }

    std::cout << std::endl << ">[END] Keys generated Successfully" << std::endl << std:: endl;


    return finalKeys;
}

QString MainWindow::DESEncryption(std::string dataBlock, std::vector< std::string > keys)
{
    // 0000000100100011010001010110011110001001101010111100110111101111

    std::string permutedBlock = "";

    int initPermutation[64] = {
        58,    50,   42,    34,    26,   18,    10,    2,
        60,    52,   44,    36,    28,   20,    12,    4,
        62,    54,   46,    38,    30,   22,    14,    6,
        64,    56,   48,    40,    32,   24,    16,    8,
        57,    49,   41,    33,    25,   17,     9,    1,
        59,    51,   43,    35,    27,   19,    11,    3,
        61,    53,   45,    37,    29,   21,    13,    5,
        63,    55,   47,    39,    31,   23,    15,    7
    };

    for(int i=0 ; i<64 ; ++i)
    {
        permutedBlock += dataBlock[initPermutation[i]-1];
    }

    std::string L0 = permutedBlock.substr(0, 32);
    std::string R0 = permutedBlock.substr(32, 64);


    std::cout << "L0 : " << L0 << std::endl;
    std::cout << "R0 : " << R0 << std::endl;

    std::vector< std::pair<std::string, std::string> > data;
    data.push_back(std::make_pair(L0, R0));

    for(int i=1;i<17;++i)
    {
        std::string L = data[i-1].second;

        std::string R = apply_xor(
            data[i-1].first,
            apply_func_F(apply_func_E(data[i-1].second), keys[i-1])
        );

        data.push_back(std::make_pair(L, R));

        std::cout << "L" << i << " : " << L << std::endl;
        std::cout << "R" << i << " : " << R << std::endl;
    }

    std::string encryptedDataReversedKey = "";
    encryptedDataReversedKey += data[data.size()-1].second;
    encryptedDataReversedKey += data[data.size()-1].first;

    std::string finalPermutedBlock = "";

    int finalPermutation[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41,  9, 49, 17, 57, 25
    };

    for(int i=0 ; i<64 ; ++i)
    {
        finalPermutedBlock += encryptedDataReversedKey[finalPermutation[i]-1];
    }

    return QString(finalPermutedBlock.c_str());
}

std::string MainWindow::apply_xor(std::string str1, std::string str2)
{
    if(str1.length() != str2.length())
        std::cout << "Error in XORed Strings, Length Not Equal" << std::endl;

    std::string result = "";
    for(int i=0;i<str1.length();++i)
    {
        if(str1[i] == str2[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

std::string MainWindow::apply_func_F(std::string str1, std::string str2)
{
    // result is 48 bit
    std::string result = apply_xor(str1, str2);

    int sboxes[8][4][16] =
    {
        {
            { 14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7 },
            {  0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8 },
            {  4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0 },
            { 15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13 }
        },
        {
            { 15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10 },
            {  3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5 },
            {  0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15 },
            { 13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9 }
        },
        {
            { 10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8 },
            { 13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1 },
            { 13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7 },
            {  1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12 }
        },
        {
            {  7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15 },
            { 13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9 },
            { 10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4 },
            {  3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14 }
        },
        {
            {  2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9 },
            { 14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6 },
            {  4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14 },
            { 11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3 }
        },
        {
            { 12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11 },
            { 10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8 },
            {  9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6 },
            {  4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13 }
        },
        {
            {  4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1 },
            { 13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6 },
            {  1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2 },
            {  6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12 }
        },
        {
            { 13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7 },
            {  1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2 },
            {  7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8 },
            {  2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11 }
        }
    };

    std::string output = "";
    std::string outerBits = "";
    std::string innerBits = "";

    for(int i=0, s=0 ; i<48 ; i+=6, s++)
    {
        outerBits += result[i];
        outerBits += result[i+5];

        innerBits += result[i+1];
        innerBits += result[i+2];
        innerBits += result[i+3];
        innerBits += result[i+4];

        int row = std::stoi(outerBits, nullptr, 2);
        int column = std::stoi(innerBits, nullptr, 2);

        int valInSBox = sboxes[s][row][column];

        output += std::bitset<4>(valInSBox).to_string();

        outerBits = "";
        innerBits = "";
    }

    std::string permutedOutput = "";

    int permutations[32] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
    };

    for(int i=0; i<32; ++i)
    {
        permutedOutput += output[permutations[i]-1];
    }

    return permutedOutput;
}

std::string MainWindow::apply_func_E(std::string str)
{
    std::string result = "";

    int ePermutations[48] = {
         32,     1,    2,     3,     4,    5,
          4,     5,    6,     7,     8,    9,
          8,     9,   10,    11,    12,   13,
         12,    13,   14,    15,    16,   17,
         16,    17,   18,    19,    20,   21,
         20,    21,   22,    23,    24,   25,
         24,    25,   26,    27,    28,   29,
         28,    29,   30,    31,    32,    1
    };

    for(int i=0;i<48;++i)
    {
        result += str[ePermutations[i]-1];
    }

    return result;
}


// improved DES with text Methods
QString MainWindow::ewIDES(QString plainText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);
    std::vector< std::string > blocks = textToBinaryAscii(plainText.toStdString());

    QString encryptedText;

    for(int i=0; i<blocks.size(); ++i)
        encryptedText += DESEncryption(blocks[i], keys);

//    encryptedText = QString::fromStdString(binaryAsciiToText(encryptedText.toStdString()));

    return encryptedText;
}

QString MainWindow::dwIDES(QString encryptedText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);
    std::reverse(keys.begin(), keys.end());

    std::string stdPlainText = encryptedText.toStdString();
    std::string allPlainText = "";

    for(int i=0; i<encryptedText.size()/64; ++i)
    {
        allPlainText += DESEncryption(stdPlainText.substr(i*64, 64), keys).toStdString();
    }

    return QString::fromStdString(binaryAsciiToText(allPlainText));
}

std::vector< std::string > MainWindow::textToBinaryAscii(std::string str)
{
    std::vector< std::string > blocksOfData;

    for(int i=0; i<str.size()/8; ++i)
    {
        std::string blockStr = str.substr(i*8, 8);
        std::string block = "";

        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);

        blocksOfData.push_back(block);
    }

    if(str.size()%8 != 0)
    {
        int start = ((int)str.size()/8)*8;
        int length = (int)str.size()- start;

        std::string blockStr = str.substr(start, length);
        for(int i=0; i<(8-length); ++i)
            blockStr += " ";

        std::string block = "";
        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);
        blocksOfData.push_back(block);
    }

    return blocksOfData;
}

std::string MainWindow::binaryAsciiToText(std::string str)
{
    std::string blocksOfData = "";

    for(int i=0; i<str.size()/64; ++i)
    {
        std::string blockStr = str.substr(i*64, 64);
        std::string block = "";

        for(int i=0; i<8; ++i)
        {
           std::string ascii = blockStr.substr(i*8, 8);
           block += binaryAsciiToChar(ascii);
        }
        blocksOfData += block;
    }

    return blocksOfData;
}

std::string MainWindow::charToBinaryAscii(char ch)
{
    return std::bitset<8>(int(ch)).to_string();
}

char MainWindow::binaryAsciiToChar(std::string binaryAscii)
{
    return char(std::bitset<8>(binaryAscii).to_ulong());
}





// RSA Methods

double MainWindow::ewRSA(double msg, double p, double q)
{
    // generate public as first, private as second key
    std::pair<double,double> keys = RSAKeys(p, q);

    double n = p*q;
    double e = keys.first;

    return RSAEncryption(msg, n, e);
}

double MainWindow::dwRSA(double msg, double p, double q)
{
    // generate public as first, private as second key
    std::pair<double,double> keys = RSAKeys(p, q);

    int n = p*q;
    int d = keys.second;

    return RSADecryption(msg, n, d);
}

double MainWindow::RSAEncryption(double msg, double n, double e)
{
    // Encryption c = (msg ^ e) % n
    double c = pow(msg, e);
    c = fmod(c, n);
    return c;
}

double MainWindow::RSADecryption(double msg, double n, double d)
{
    // Decryption m = (c ^ d) % n
    double m = pow(msg, d);
    m = fmod(m, n);
    return m;
}

std::pair<double, double> MainWindow::RSAKeys(double p, double q)
{
    // Finding public key; e stands for encrypt.
    double e = 2;
    double phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }

    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient

    int d = e;
    while((int)(d*e)%((int)phi) != 1)
    {
        d++;
    }

    return std::make_pair(e, d);
}

int MainWindow::gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}





// RC4 Methods

QString MainWindow::ewRC4(QString msg, QString key)
{
    std::vector<int> k;

    // initialize key
    std::string stdCppKey = key.toStdString();
    for(int i=0; i<stdCppKey.length(); ++i)
        k.push_back(int(stdCppKey[i] - '0'));

    std::vector<int> s(256);
    std::vector<int> t(256);

    // initialize vector S to [0:255]
    for(int i=0; i<256; ++i)
        s[i] = i;

    // initialize vector T from key K
    for(int i=0; i<256; ++i)
        t[i] = k[i%k.size()];

    // initial Permutation Of S
    int j = 0;
    for(int i=0; i<256; ++i)
    {
        j = (j + s[i] + t[i])%256;
        std::swap(s[i], s[j]);
    }

    // prepare msg
    std::vector< std::bitset<8> > msg_bytes = bytesOfMessage(msg.toStdString());


    // generate a key for each byte of input
    // e.g input: 5 bytes, generates output: 5 bytes
    std::vector< std::bitset<8> > keys = keysGenerator((int)msg_bytes.size(), s);

    return RC4Encryption(msg_bytes, keys);

}

QString MainWindow::dwRC4(QString msg, QString key)
{
    return ewRC4(msg, key);
}

QString MainWindow::RC4Encryption(std::vector< std::bitset<8> > msg_bytes, std::vector< std::bitset<8> > keys)
{
    std::string result = "";
    for (int i = 0; i < msg_bytes.size(); ++i)
    {
        std::bitset<8> temp = std::bitset<8>(msg_bytes[i] ^ keys[i]);
        result += temp.to_string();
    }

    // Debugging output
    std::cout << "> Debugging Statements" << std::endl;

    std::cout << "I/P: " ;
    for(int t=0; t<msg_bytes.size(); ++t)
        std::cout << msg_bytes[t];
    std::cout << std::endl;

    std::cout << "Key: ";
    for(int t=0; t<keys.size(); ++t)
        std::cout << keys[t].to_string();
    std::cout << std::endl;
    std::cout << "O/P: " << result << std::endl;

    return QString::fromStdString(result);
}

std::vector< std::bitset<8> > MainWindow::keysGenerator(int msg_length, std::vector<int> s)
{
    std::vector< std::bitset<8> > keys(msg_length);

    int i=0, j=0, k=0;
    for (int lc = 0; lc < msg_length; ++lc)
    {
        i = (i+1)%256;
        j = (j+s[i])%256;
        std::swap(s[i], s[j]);
        k = s[(s[i]+s[j])%256];
        keys[lc] = std::bitset<8>(k);
    }

    return keys;
}

std::vector< std::bitset<8> > MainWindow::bytesOfMessage(std::string msg)
{
    std::vector< std::bitset<8> > msg_bytes;

    for(int i=0; i<(msg.length()/8); ++i)
    {
        std::string msg_byte = "";
        for(int j=0; j<8; ++j)
        {
            int idx = j + i*8;
            msg_byte += msg[idx];
        }
        msg_bytes.push_back(std::bitset<8>(msg_byte));
    }

    return msg_bytes;
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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());

       ui->rcpt->clear();
       ui->subject->clear();
       ui->msg->clear();

}

void MainWindow::on_pb_envoyer_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    Personnel p;
   p.setnom(ui->le_id_chat->text());
    p.setmessage(ui->le_message->text());
    QMessageBox msgbox;
    bool test=p.ajouterMessage(p.getnom());
    if(test)
    {
        msgbox.setText("un nouveau message");
        ui->tab_message->setModel(p.afficherMessage());
    }
    else
        msgbox.setText("probleme d'envoie de message");
    msgbox.exec();

}

void MainWindow::on_trier_age_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    Personnel *p;
    ui->tab_personnel->setModel(p->triAge());

}

void MainWindow::on_trie_dureeTravail_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
    Personnel *p;
    ui->tab_personnel->setModel(p->triDureeTravail());

}
void MainWindow::on_pushButton_7_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

            ui->line_cin->setText("");
            ui->line_age->setText("");
            ui->line_nom->setText("");
            ui->line_prenom->setText("");
            ui->line_telephone->setText("");
            ui->line_adresseMail->setText("");
            ui->line_dureeTravail->setText("");
            ui->line_adresse->setText("");

}
/**********************************FORMATION****************************************/
void MainWindow::on_pushButtonAjouter_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

ui->CODE_FORMATION->clear();
ui->NOM_FOR->clear();
ui->NOM_ENCADREUR->clear();
ui->TYPE_FOR->clear();
ui->DURE_FOR->clear();
}


void MainWindow::on_supp_clicked()
{
    Formation f1;

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

                ui->code_supp->clear();

}

void MainWindow::on_Mod_2_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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

/*void MainWindow::on_send_mail_clicked()
{

    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());
}


*/

void MainWindow::on_reset_3_clicked()
{
    ui->rcpt->setText("");
    ui->subject->setText("");
    ui->msg->setPlainText("");


}
void MainWindow::on_pushButton_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

            ui->CODE_FORMATION->setText("");
            ui->NOM_FOR->setText("");
            ui->NOM_ENCADREUR->setText("");
            ui->TYPE_FOR->setText("");
            ui->DURE_FOR->setText("");
}
/***************************************Aller vers********************************/
void MainWindow::page1Widget()
{
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(page2Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::page2Widget()
{
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(page1Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void MainWindow::page3Widget()
{
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(page1Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void MainWindow::page8Widget()
{
    QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(page1Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page_8);
}
void MainWindow::page9Widget()
{
    QObject::connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(page1Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page_9);
}
void MainWindow::page10Widget()
{
    QObject::connect(ui->configuration,SIGNAL(clicked()),this,SLOT(page1Widget()) );
    ui->stackedWidget->setCurrentWidget(ui->page_10);
}
/**************************************MAINTENANCE***********************************/

void MainWindow::on_pushButtonAjouter_2_clicked()
{
    QSqlQuery query;

        QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
               ui->pushButtonAjouter->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

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

    QFile file("C:/Users/HP/Downloads/intg/historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez ajouté un matériel\n";
            cout << message2;
            QFile file("C:/Users/HP/Downloads/intg/historique.txt");
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

void MainWindow::on_reset_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

            ui->id->setText("");
            ui->nom->setText("");
            ui->reference->setText("");
            ui->mail->setText("");


}

void MainWindow::on_supp_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

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

void MainWindow::on_modifier_clicked()
{
    QSqlQuery query;
       QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();
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

void MainWindow::on_stat_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

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


void MainWindow::on_recherche_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

        QString reference =ui->rech->text();
        /*QString mail =ui->rech->text();
        QString marque =ui->rech->text();*/

           ui->tab_mat->setModel(Mat.rechercher(reference));
          /* ui->tab_mat->setModel(Mat.rechercher1(mail));
           ui->tab_mat->setModel(Mat.rechercher2(marque));*/
    ui->rech->clear();

}

void MainWindow::on_reaficher_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
              player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
              player->setVolume(2000);
              player->play();

       ui->rech->setText("");
       ui->tab_mat->setModel(Mat.afficher());
}

void MainWindow::on_send_mail_3_clicked()
{
    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());

}

void MainWindow::on_reset_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();

        ui->rcpt->setText("");
        ui->subject->setText("");
        ui->msg->setPlainText("");


}
void MainWindow::on_pushButton_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();


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

void MainWindow::on_tabWidget_currentChanged(int index){


    ui->id_combo->clear();
    ui->id_combo->addItems(Mat.recherche_t());
    ui->combo_person->clear();
    ui->combo_person->addItems(Mat.recherche_t1());
}




/*

void MainWindow::on_send_mail_2_clicked()
{
    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a","smtp.gmail.com",465);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           smtp->sendMail("aura.forgetPass@gmail.com",ui->rcpt_2->text(),ui->subject_2->text(),ui->msg_2->toPlainText());

}
*/
/***************************************CLOSE********************************************/
void MainWindow::on_close_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
     this->close();
}

void MainWindow::on_close_2_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
   this->close();
}

void MainWindow::on_close_3_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
  this->close();
}


void MainWindow::on_close_4_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Downloads/intg/button.wav"));
               player->setVolume(2000);
               player->play();
  this->close();
}



/*****************************CANDIDATS****************************************************/
/*
void MainWindow::detect(){
   data=Ard.read_from_arduino();
   if (data=="1"){
       QMessageBox::information(nullptr, QObject::tr("Mouvement"),
                                QObject::tr("employe graphisme Arrivé."), QMessageBox::Ok);

   }
}
*/
void MainWindow::on_pb_valider_clicked()
{
    QString id=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
     QDate date=ui->de_date->date();
     QString poste=ui->le_poste->text();
 entretien e(id,nom,prenom,date,poste);
 bool test=e.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView->setModel(e.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_afficher_clicked()
{
    ui->tableView->setModel(e.afficher());

}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString id = ui->le_id->text();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QDate date = ui->de_date->date();
    QString poste = ui->le_poste->text();

    entretien p(id,nom,prenom,date,poste) ;
    bool test =e.modifier(id,nom,prenom,date,poste);
    if(test)
    {ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier une candidature"),
                                 QObject::tr("candidature modifiée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une candidature"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_annuler_clicked()
{
    QDate d=QDate::currentDate();
    ui->le_id->setText("");
    ui->le_nom->setText("");
    ui->le_prenom->setText("");
    ui->de_date->setDate(d);
    ui->le_poste->setText("");
}

void MainWindow::on_pb_supprimer_clicked()
{
    entretien e1; e1.setid(ui->le_recherche->text());
    bool test=e1.supprimer(e1.getid());
    QMessageBox msgBox;

    if(test)
        {msgBox.setText("Suppression avec succes.");
         ui->tableView->setModel(e.afficher());

        }
    else{
        msgBox.setText("Echec de suppression");
        msgBox.exec();
        }
}

void MainWindow::on_pb_ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pb_select_clicked()
{

    int row=ui->tableView->selectionModel()->currentIndex().row();
    QString id=ui->tableView->model()->index(row,0).data().toString();
    QString nom=ui->tableView->model()->index(row,1).data().toString();
    QString prenom=ui->tableView->model()->index(row,2).data().toString();

    QDate date=ui->tableView->model()->index(row,3).data().toDate();
    QString poste=ui->tableView->model()->index(row,4).data().toString();
    if(row==-1)
    {
        QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                          QObject::tr("aucune selection.\n"
                                              "click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        ui->le_id->setText(id);
        ui->le_nom->setText(nom);
        ui->le_prenom->setText(prenom);
        ui->de_date->setDate(date);
        ui->le_poste->setText(poste);
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_trier_clicked()
{
    QString critere=ui->cb_tri->currentText();
        QString mode;
         if (ui->rb_asc->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->rb_desc->isChecked()==true)
         {
             mode="DESC";
         }
      ui->tableView->setModel(e.trier(critere,mode));
}

void MainWindow::on_pb_imprimer_clicked()
{
    /* QPrinter printer;
     printer.setPrinterName ("le nom de l'imprimante");
     QPrintDialog dialog(&printer,this);
     if (dialog.exec()== QDialog::Rejected)return;
     ui->tableView->render(&printer);*/

         QString strStream;
         QTextStream out(&strStream);
         const int rowCount = ui->tableView->model()->rowCount();
         const int columnCount = ui->tableView->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"

                            //     "<align='right'> " << datefich << "</align>"



                             "<center> <H1>Liste des Candidats "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableView->isColumnHidden(column)) {
                                     QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n";
     out << "<tr>\n"

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

void MainWindow::on_pb_acceuil_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);



}

//aller a formation

void MainWindow::on_pb_formation_clicked()
{
ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void MainWindow::on_le_recherche_textChanged(const QString &arg1)
{
    if(ui->le_recherche->text() =="")
    {
        ui->tableView->setModel(e.afficher());
    }
    else
    {
        ui->tableView->setModel(e.rechercher(ui->le_recherche->text()));
    }
}

void MainWindow::on_pb_acceuil_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);//prob
}


//configuration mode nuit ou jour
void MainWindow::on_pushButton_13_clicked()
{
    if(ui->mode->currentText()=="JOUR")
    {


            ui->page_10->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");
            ui->page->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");
            ui->page_2->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");
            ui->page_3->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");
            ui->page_8->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");
            ui->page_9->setStyleSheet("background-color: rgb(245,172,162);color: rgb(121, 79, 29);");


    }
    else if(ui->mode->currentText()=="NUIT")
    {
            ui->page_10->setStyleSheet("background-color: rgb(40,40,40)");

            ui->page->setStyleSheet("background-color: rgb(40,40,40)");

            ui->page_2->setStyleSheet("background-color: rgb(40,40,40)");

            ui->page_3->setStyleSheet("background-color: rgb(40,40,40)");

            ui->page_8->setStyleSheet("background-color: rgb(40,40,40)");

            ui->page_9->setStyleSheet("background-color: rgb(40,40,40)");
}

}
//aller a la page facebook
void MainWindow::on_pushButton_14_clicked()
{

        QDesktopServices::openUrl(QUrl("https://www.facebook.com/", QUrl::TolerantMode));

}
//se connecter
void MainWindow::on_seconnecter_clicked()
{
    QString id_connexion=ui->id_con->text();
    QString password_connexion=ui->pass_con->text();

    ui->id_con->setStyleSheet("color: black");
    ui->pass_con->setStyleSheet("color: black");

    if(id_connexion == "admin" && password_connexion == "admin")
    {
        QMessageBox::information(this," Connexion ","Le nom d'utilisateur et le mot de passe sont corrects ") ;

        QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/accepted.wav");

       ui->stackedWidget->setCurrentWidget(ui->page);


    }

    else if(id_connexion != "admin" && password_connexion == "admin")
    {
        ui->id_con->setStyleSheet("color: red");
        QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/voice-access-denied.wav");

    }
    else if(id_connexion == "admin" && password_connexion != "admin")
    {
        ui->id_con->setStyleSheet("color: red");
        QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/voice-access-denied.wav");

    }
    else
    {
         ui->id_con->setStyleSheet("color: red");
         ui->pass_con->setStyleSheet("color: red");
         QSound::play("C:/Users/HP/Desktop/integration/rim khaled salma aymen/voice-access-denied.wav");

    }
}
//se diconnecter
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_11);
    ui->id_con->setText("");
    ui->pass_con->setText("");
}

void MainWindow::on_pushButton_16_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->page);
}
