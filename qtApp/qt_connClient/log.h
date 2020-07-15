#ifndef LOG_H
#define LOG_H

#include <QMainWindow>
#include "usrreg.h"
#include <string>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class log; }
QT_END_NAMESPACE

class log : public QMainWindow
{
    Q_OBJECT

public:
    log(QWidget *parent = nullptr);
    ~log();

private slots:
    void on_login_clicked();

private:
    Ui::log *ui;
};


#endif // LOG_H
