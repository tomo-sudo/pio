#include "usrinfo.h"
#include "ui_usrinfo.h"

UsrInfo::UsrInfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UsrInfo)
{
    ui->setupUi(this);
}

UsrInfo::~UsrInfo()
{
    delete ui;
}

