#ifndef WIDGET_H
#define WIDGET_H
#include "speci.h"
#include "school.h"
#include <adds.h>
#include <mb.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Speci *s;
    Speci *s1;
    School sc;
    QFrame *myf;
    QFrame *spcf;
    adds* a;
    QMenu* menu;



    int ifTop;
    int curr,curr2;

    void setTable(QFrame*f,int x,int y,int color);

    void newTable(QFrame*f,int which,int cou);

    void IFTable(QFrame*f,int cou);

    void IFTable1(QFrame*f,int cou);

    void newIFTable(int cur);

void find();

    //构造函数调用，创建菜单
    void initMenu();

    ~Widget();

private slots:

    void on_a1_clicked();

    void on_a2_clicked();

    void addNew();

    void Del();

    //


    void on_find_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
