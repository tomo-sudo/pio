#include "tcpclient.h"
#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
}

TcpClient::~TcpClient()
{
    delete ui;
}


void TcpClient::on_btnConServer_clicked()
{
    tcpSocket->connectToHost("127.0.0.1", 8888, QTcpSocket::ReadWrite);
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnect()));
}

void TcpClient::on_btnDiscon_clicked()
{
    tcpSocket->close();
}

void TcpClient::on_btnSend_clicked()
{
    tcpSocket->connectToHost("127.0.0.1", 8888, QTcpSocket::ReadWrite);
    // slotConnect();

    QString str = ui->lineEdit->text();
    char *tmp;

    QByteArray ba = str.toUtf8();
    tmp = ba.data();


    char *tmp2 = (char*)"hello";
    QString str2(tmp2);
    //  ui->plainTextEdit->insertPlainText(tmp2);
    //  ui->plainTextEdit->insertPlainText(tmp2);
    ui->plainTextEdit->setText(tmp2);
    ui->plainTextEdit->textCursor().insertText(str2);
    ui->plainTextEdit->textCursor().insertText(str2);

    //QByteArray arr;
    //  QDataStream dst(&arr, QIODevice::ReadWrite);  //QDataStream是继承于QIODevice的所以 必须要 设置读写权限
    //dst << /*QString::fromUtf8("来自于客户端：")*/ "hi";  //这里一定要设置好数据类型

    t1 = (struct t*)malloc(sizeof(t));
    //    strcpy(t1->name, "wang");
    //    strcpy(t1->sex, "male");
    //    memcpy(t1->name, "wang", sizeof("wang"));
    //    memcpy(t1->sex, "male", sizeof("male"));

    strncpy(t1->name, tmp, strlen(tmp) + 1);
    strncpy(t1->sex, "male", strlen("male") + 1);
    tcpSocket->write((char*)t1, sizeof(t));
    readyread();

    tcpSocket->close();

}



void TcpClient::readyread()
{

    //    tcpSocket->read((char *)&t2, sizeof(t));
    //    //   QDataStream* dst = new QDataStream(&arr, QIODevice::ReadOnly);
    //    QString str1;
    //    QString str2;

    //    // (*dst) >> str1 >> str2;

    //    qDebug() << t2.name << t2.sex;

    //    append换行
    //    ui->plainTextEdit->append(t2.name);
    //    ui->plainTextEdit->append(t2.sex);
    //    ui->plainTextEdit->append("");
    while(tcpSocket->waitForReadyRead() != true);
    while(tcpSocket->bytesAvailable() > 0)
    {
        //    QByteArray datagram;
        //  datagram.resize((tcpSocket->bytesAvailable()));
        tcpSocket->read((char*)&t2, sizeof(t2));
        //   QString msg = datagram.data();
        //  QByteArray ba  = msg.toUtf8();
        //  char *tm1 = ba.data();
        // qDebug() << tm1 << "hi hello";

        t3 = (struct t*)malloc(sizeof(struct t));
        // t3 = (struct t*)tm1;

        qDebug() << t2.name << t2.sex << "t2";
        ui->plainTextEdit->append(t2.name);
        ui->plainTextEdit->append(t2.sex);
    }
}


void TcpClient::slotConnect()
{
    ui->statusbar->showMessage(QString::fromLocal8Bit("连接服务器成功"));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyread()));
}




