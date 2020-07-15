#include "accountcancel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccountCancel w;
    w.show();
    return a.exec();
}
