/********************************************************************************
** Form generated from reading UI file 'accountcancel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTCANCEL_H
#define UI_ACCOUNTCANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountCancel
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountCancel)
    {
        if (AccountCancel->objectName().isEmpty())
            AccountCancel->setObjectName(QString::fromUtf8("AccountCancel"));
        AccountCancel->resize(480, 600);
        centralwidget = new QWidget(AccountCancel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(85, 40, 310, 460));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(59, 350, 201, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 130, 55, 18));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 240, 55, 26));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 130, 130, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 240, 130, 26));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 270, 104, 70));
        AccountCancel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountCancel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 23));
        AccountCancel->setMenuBar(menubar);
        statusbar = new QStatusBar(AccountCancel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AccountCancel->setStatusBar(statusbar);

        retranslateUi(AccountCancel);

        QMetaObject::connectSlotsByName(AccountCancel);
    } // setupUi

    void retranslateUi(QMainWindow *AccountCancel)
    {
        AccountCancel->setWindowTitle(QApplication::translate("AccountCancel", "AccountCancel", nullptr));
        pushButton_2->setText(QApplication::translate("AccountCancel", "\345\217\226\346\266\210", nullptr));
        pushButton->setText(QApplication::translate("AccountCancel", "\351\224\200\346\210\267", nullptr));
        label->setText(QApplication::translate("AccountCancel", "\347\224\250\346\210\267", nullptr));
        label_2->setText(QApplication::translate("AccountCancel", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountCancel: public Ui_AccountCancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTCANCEL_H
