#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Chat; }
QT_END_NAMESPACE

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    Chat(QWidget *parent = nullptr);
    ~Chat();

private:
    Ui::Chat *ui;
};
#endif // CHAT_H
