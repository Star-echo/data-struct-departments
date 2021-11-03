#ifndef SPECI_H
#define SPECI_H
#include <addp.h>
namespace Ui {
    class Speci;
}

class Speci : public QTableView
{
    Q_OBJECT

public:
    explicit Speci(QWidget *parent = 0);
    addp* p;
    QStandardItemModel* model;
    void addNew();
    ~Speci();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Speci *ui;
};

#endif // SPECI_H
