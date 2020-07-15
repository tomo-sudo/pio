#include "accountcancel.h"
#include "ui_accountcancel.h"

AccountCancel::AccountCancel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AccountCancel)
{
    ui->setupUi(this);
}

AccountCancel::~AccountCancel()
{
    delete ui;
}

