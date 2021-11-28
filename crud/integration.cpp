#include "integration.h"
#include "ui_integration.h"

integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
}

integration::~integration()
{
    delete ui;
}
