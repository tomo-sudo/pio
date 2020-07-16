#include "login.h"
#include "ui_log.h"
#include "usrreg.h"

#include <QDebug>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_clicked()
{

}
