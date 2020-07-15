#ifndef ACCOUNTCANCEL_H
#define ACCOUNTCANCEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AccountCancel; }
QT_END_NAMESPACE

class AccountCancel : public QMainWindow
{
    Q_OBJECT

public:
    AccountCancel(QWidget *parent = nullptr);
    ~AccountCancel();

private:
    Ui::AccountCancel *ui;
};
#endif // ACCOUNTCANCEL_H
