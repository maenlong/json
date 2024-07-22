#include <QApplication>

#include "jsontestwgt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    JsonTestWgt *pWgt = new JsonTestWgt;
    pWgt->show();

    return a.exec();
}
