#ifndef USRINFO_H
#define USRINFO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UsrInfo; }
QT_END_NAMESPACE

class UsrInfo : public QMainWindow
{
    Q_OBJECT

public:
    UsrInfo(QWidget *parent = nullptr);
    ~UsrInfo();

private:
    Ui::UsrInfo *ui;
};
#endif // USRINFO_H
