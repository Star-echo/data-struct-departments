#ifndef MB_H
#define MB_H

#include <QPushButton>
#include <QAction>

class mb : public QPushButton
{
    Q_OBJECT

public:
    mb(QWidget *parent = 0);
    int ifDe;
    ~mb();

protected slots:
    void actionDeleSlot();

private:
    QAction *dele;
};


#endif // MB_H
