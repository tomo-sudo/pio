#ifndef USRREG_H
#define USRREG_H

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class usrReg; }
QT_END_NAMESPACE

class usrReg : public QMainWindow
{
    Q_OBJECT

public:
    usrReg(QWidget *parent = nullptr);
    ~usrReg();

private:
    Ui::usrReg *ui;

private:
    QVBoxLayout *qv;
};
#endif // USRREG_H
