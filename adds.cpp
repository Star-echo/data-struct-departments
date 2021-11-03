#include "adds.h"
#include "ui_adds.h"
adds::adds(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adds)
{
    ui->setupUi(this);
    ifok=0;
}

adds::~adds()
{
    delete ui;
}

void adds::on_pushButton_clicked()
{
    if(ifok){
        s=ui->lineEdit->text();
        ui->lineEdit->clear();
        this->close();
    }
    ifok=0;
    ifClose=1;
}

void adds::on_lineEdit_textEdited(const QString &arg1)
{
    ifok=1;
}
