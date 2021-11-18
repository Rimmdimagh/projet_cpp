#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "formation.h"
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

    void on_pushButtonAjouter_clicked();

  void on_supp_clicked();

  void on_Mod_2_clicked();

  void on_rechercher_button_clicked();

  void on_trier_button_clicked();

  void on_qrcodegen_clicked();

  void on_statsmed_clicked();

  void on_radioButton_croissant_clicked();

  void on_radioButton_dcroissant_clicked();


  void on_rechercher_button_2_clicked();

  void on_ImportPDF_clicked();

  void on_insererphoto_clicked();

 // void on_send_mail_clicked();

 // void mailSent(QString );

  void on_reset_3_clicked();

  void on_send_mail_clicked();


private:
    Ui::MainWindow *ui;
     Formation Etmp;
};

#endif // MAINWINDOW_H
