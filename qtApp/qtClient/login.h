#ifndef LOG_H
#define LOG_H

#include <QMainWindow>
#include "usrreg.h"
#include <string>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_clicked();

private:
    Ui::login *ui;
};


#endif // LOG_H
