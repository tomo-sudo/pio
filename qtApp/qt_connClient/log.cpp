#include "log.h"
#include "ui_log.h"
#include "usrreg.h"

#include <QDebug>

log::log(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::log)
{
    ui->setupUi(this);
}

log::~log()
{
    delete ui;
}


void log::on_login_clicked()
{

}
