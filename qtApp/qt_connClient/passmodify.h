#ifndef PASSMODI_H
#define PASSMODI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PassModi; }
QT_END_NAMESPACE

class PassModi : public QMainWindow
{
    Q_OBJECT

public:
    PassModi(QWidget *parent = nullptr);
    ~PassModi();

private:
    Ui::PassModi *ui;
};
#endif // PASSMODI_H
