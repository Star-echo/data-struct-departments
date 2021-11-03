#ifndef ADDP_H
#define ADDP_H
#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>
#include <QMenu>
#include <QFrame>
#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
#include <cstdlib>
#include <QMessageBox>
namespace Ui {
class addp;
}

class addp : public QWidget
{
    Q_OBJECT

public:
    explicit addp(QWidget *parent = 0);
    int ifno;   //是否是新人
    QString s;  //姓名
    int gra;    //级别（主管只能有1名）
    int ifok;   //是否提交
    int ifClose;//是否关闭
    int ifNew;
    ~addp();

private slots:

    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::addp *ui;
};

#endif // ADDP_H
