#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QString>
#include <QDataStream>
#include <QByteArray>
#include <malloc.h>


QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

    struct t
    {
        char name[20];
        char sex[10];
    }*t1, t2;

private slots:
    void on_btnConServer_clicked();

    void on_btnDiscon_clicked();

    void on_btnSend_clicked();

    void readyread();
    void slotConnect();

private:
    Ui::TcpClient *ui;

private:
    QTcpSocket *tcpSocket;
};
#endif // TCPCLIENT_H
