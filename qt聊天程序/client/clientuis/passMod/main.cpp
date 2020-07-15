#include "passmodi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PassModi w;
    w.show();
    return a.exec();
}
