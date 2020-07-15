/********************************************************************************
** Form generated from reading UI file 'usrinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRINFO_H
#define UI_USRINFO_H

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

class Ui_UsrInfo
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UsrInfo)
    {
        if (UsrInfo->objectName().isEmpty())
            UsrInfo->setObjectName(QString::fromUtf8("UsrInfo"));
        UsrInfo->resize(563, 436);
        centralwidget = new QWidget(UsrInfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(50, 40, 451, 321));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 55, 18));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 90, 55, 18));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 140, 55, 18));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 90, 113, 26));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 140, 113, 26));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 270, 60, 25));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 270, 60, 25));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 190, 55, 18));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 190, 113, 26));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 40, 113, 18));
        UsrInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UsrInfo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 563, 23));
        UsrInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(UsrInfo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UsrInfo->setStatusBar(statusbar);

        retranslateUi(UsrInfo);

        QMetaObject::connectSlotsByName(UsrInfo);
    } // setupUi

    void retranslateUi(QMainWindow *UsrInfo)
    {
        UsrInfo->setWindowTitle(QApplication::translate("UsrInfo", "UsrInfo", nullptr));
        label->setText(QApplication::translate("UsrInfo", "\345\270\220\345\217\267", nullptr));
        label_2->setText(QApplication::translate("UsrInfo", "\346\200\247\345\210\253", nullptr));
        label_3->setText(QApplication::translate("UsrInfo", "\347\224\265\350\257\235", nullptr));
        pushButton->setText(QApplication::translate("UsrInfo", "\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QApplication::translate("UsrInfo", "\345\205\263\351\227\255", nullptr));
        label_5->setText(QApplication::translate("UsrInfo", "\346\230\265\347\247\260", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UsrInfo: public Ui_UsrInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRINFO_H
