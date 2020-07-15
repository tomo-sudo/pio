#include "passmodi.h"
#include "ui_passmodi.h"

PassModi::PassModi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PassModi)
{
    ui->setupUi(this);
}

PassModi::~PassModi()
{
    delete ui;
}

