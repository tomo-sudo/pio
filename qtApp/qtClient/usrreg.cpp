#include "usrreg.h"
#include "ui_usrreg.h"

usrReg::usrReg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::usrReg)
{
    ui->setupUi(this);

}

usrReg::~usrReg()
{
    delete ui;
}

