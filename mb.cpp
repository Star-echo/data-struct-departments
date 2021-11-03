#include "mb.h"

mb::mb(QWidget *parent)
    : QPushButton(parent)
{
    setContextMenuPolicy(Qt::ActionsContextMenu);

    dele = new QAction(this);

    dele->setText("删除");

    ifDe=0;

    addAction(dele);

    connect(dele, SIGNAL(triggered()), this, SLOT(actionDeleSlot()));
}

mb::~mb()
{

}

void mb::actionDeleSlot()
{
    ifDe=1;
}
