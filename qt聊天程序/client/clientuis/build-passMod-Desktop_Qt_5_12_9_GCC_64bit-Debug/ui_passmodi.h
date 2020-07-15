/********************************************************************************
** Form generated from reading UI file 'passmodi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSMODI_H
#define UI_PASSMODI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassModi
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PassModi)
    {
        if (PassModi->objectName().isEmpty())
            PassModi->setObjectName(QString::fromUtf8("PassModi"));
        PassModi->resize(461, 504);
        centralwidget = new QWidget(PassModi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(80, 30, 291, 361));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 55, 18));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 55, 18));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 50, 113, 26));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 120, 113, 26));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 290, 80, 26));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 290, 80, 26));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 210, 55, 18));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 200, 113, 26));
        PassModi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PassModi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 461, 23));
        PassModi->setMenuBar(menubar);
        statusbar = new QStatusBar(PassModi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PassModi->setStatusBar(statusbar);

        retranslateUi(PassModi);

        QMetaObject::connectSlotsByName(PassModi);
    } // setupUi

    void retranslateUi(QMainWindow *PassModi)
    {
        PassModi->setWindowTitle(QApplication::translate("PassModi", "PassModi", nullptr));
        label->setText(QApplication::translate("PassModi", "<html><head/><body><p align=\"center\">\345\216\237\345\257\206\347\240\201</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("PassModi", "<html><head/><body><p align=\"center\">\346\226\260\345\257\206\347\240\201</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("PassModi", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QApplication::translate("PassModi", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QApplication::translate("PassModi", "<html><head/><body><p align=\"center\">\345\257\206\347\240\201\347\241\256\350\256\244</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassModi: public Ui_PassModi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSMODI_H
