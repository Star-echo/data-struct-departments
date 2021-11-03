#include "addp.h"
#include "ui_addp.h"

addp::addp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addp)
{
    ui->setupUi(this);
    ifok=0;
}

addp::~addp()
{
    delete ui;
}

void addp::on_pushButton_clicked()
{
    if(ifok){
        s=ui->lineEdit->text();
        gra=ui->gra->currentIndex();
        ifno=ui->ifNew->currentIndex();
        ifNew=ui->ifNew->currentIndex();
        ui->lineEdit->clear();
        this->close();
    }
    ifok=0;
    ifClose=1;
}

void addp::on_lineEdit_textEdited(const QString &arg1)
{
    ifok=1;
}
