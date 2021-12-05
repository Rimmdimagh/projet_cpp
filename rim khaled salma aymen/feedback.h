#ifndef FEEDBACK_H
#define FEEDBACK_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class feedback
{
public:
    feedback();
   feedback(int,QString,QString,int);
   int getcin();
   QString getnom();
   QString getdomaine();
   int getavis();
   void setcin(int);
   void setnom(QString);
   void setdomaine(QString);
   void setavis(int);
bool ajouter();
private:
    int cin,avis;
    QString nom,domaine;

};

#endif // FEEDBACK_H

