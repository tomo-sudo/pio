/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QFrame *frame_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(800, 600);
        centralwidget = new QWidget(Chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(70, 30, 601, 481));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-10, -10, 141, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(verticalLayoutWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(129, -10, 351, 341));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QTextBrowser(horizontalLayoutWidget_2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setFrameShape(QFrame::WinPanel);

        horizontalLayout_2->addWidget(textBrowser_2);

        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(479, -1, 121, 451));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(verticalLayoutWidget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_3 = new QWidget(frame);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, -1, 121, 391));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(verticalLayoutWidget_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 121, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        verticalLayoutWidget_4 = new QWidget(frame_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(-1, 39, 121, 351));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        textBrowser_3 = new QTextBrowser(verticalLayoutWidget_4);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));

        verticalLayout_4->addWidget(textBrowser_3);


        verticalLayout_3->addWidget(frame_2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(2, 393, 51, 26));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(2, 421, 51, 26));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(65, 393, 50, 25));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(65, 421, 50, 25));

        verticalLayout_2->addWidget(frame);

        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(129, 329, 351, 132));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setReadOnly(false);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(90, 50, 441, 311));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 50, 55, 18));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 110, 55, 18));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 170, 55, 18));
        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 240, 60, 25));
        pushButton_6 = new QPushButton(frame_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(270, 240, 60, 25));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 50, 81, 18));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 110, 81, 18));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 170, 81, 18));
        tabWidget->addTab(tab_2, QString());
        Chat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Chat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        Chat->setMenuBar(menubar);
        statusbar = new QStatusBar(Chat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chat->setStatusBar(statusbar);

        retranslateUi(Chat);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Chat", nullptr));
        label->setText(QApplication::translate("Chat", "<html><head/><body><p align=\"center\">\345\245\275\345\217\213\344\277\241\346\201\257</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("Chat", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        pushButton_2->setText(QApplication::translate("Chat", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        pushButton_3->setText(QApplication::translate("Chat", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        pushButton_4->setText(QApplication::translate("Chat", "\344\270\213\350\275\275\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Chat", "\345\245\275\345\217\213", nullptr));
        label_2->setText(QApplication::translate("Chat", "<html><head/><body><p align=\"center\">\347\224\250\346\210\267</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Chat", "<html><head/><body><p align=\"center\">\346\230\265\347\247\260</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Chat", "<html><head/><body><p align=\"center\">\346\200\247\345\210\253</p></body></html>", nullptr));
        pushButton_5->setText(QApplication::translate("Chat", "\344\277\256\346\224\271", nullptr));
        pushButton_6->setText(QApplication::translate("Chat", "\346\263\250\351\224\200", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Chat", "\344\270\252\344\272\272\344\277\241\346\201\257 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
