#include "dialog.h"
#include "ui_dialog.h"

#include <QGridLayout>
#include <QPushButton>

const static double PI = 3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    //ui->setupUi(this);

    label1 = new QLabel(this);
    label1->setText(tr("please input radius: "));

    lineEdit = new QLineEdit(this);


    label2 = new QLabel(this);
   // label2 = new QLabel("&A", this);
  //  label2->setText(tr("this is label2 "));
    //label2->setBuddy(lineEdit);

    button = new QPushButton(this);
    button->setText(tr("show area of round"));


    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label1, 0, 0);
    mainLayout->addWidget(lineEdit, 0, 1);
    mainLayout->addWidget(label2, 1, 0);
    mainLayout->addWidget(button, 1, 1);

    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(showArea()));
    connect(button, SIGNAL(clicked()), this, SLOT(showArea()));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    label2->setText(tempStr.setNum(area));
}

QString Dialog::count()
{
    bool ok;
    QString result;
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    result = area;
    return result;

}

void Dialog::on_pushButton_clicked()
{
    QString area = count();

    ui->areaLabel1_2->setText(area);
}

void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    QString area = count();

    ui->areaLabel2->setText(area);
}
