#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "condidature.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_rechercher_clicked();


    
    /*void on_checkBox_nomt_stateChanged(int arg1);*/

    void on_trier_clicked();


    //void on_statistique_currentChanged(int index);

    void on_rechercher2_clicked();

    void on_rechercher3_clicked();


    void on_pushButtonQrcode_clicked();

private:
    Ui::MainWindow *ui;
    Condidature Ctmp;
    Condidature C;
};

#endif // MAINWINDOW_H
