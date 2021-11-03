#ifndef ADDS_H
#define ADDS_H

#include <QWidget>

namespace Ui {
class adds;
}

class adds : public QWidget
{
    Q_OBJECT

public:
    explicit adds(QWidget *parent = 0);
    QString s;  //部门名称
    int ifok;   //是否提交
    int ifClose;//是否关闭
    ~adds();

private slots:

    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::adds *ui;
};

#endif // ADDS_H
