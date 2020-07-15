#include "usrreg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    usrReg w;
    w.show();
    return a.exec();
}
