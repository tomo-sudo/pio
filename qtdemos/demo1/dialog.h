#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_radiusLineEdit_textChanged(const QString &arg1);
    void showArea();

private:
    Ui::Dialog *ui;
    QLabel*label1, *label2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QPushButton *button;

    QString count();

};
#endif // DIALOG_H
