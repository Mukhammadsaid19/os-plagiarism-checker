/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLog_out;
    QAction *actionExit;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_password;
    QPushButton *loginButton;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QLabel *label_13;
    QWidget *page_2;
    QLineEdit *lineEdit_login_2;
    QPushButton *loginButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_fn;
    QLabel *label_6;
    QLineEdit *lineEdit_password_2;
    QLabel *label_8;
    QLineEdit *lineEdit_ln;
    QLabel *label_11;
    QLineEdit *lineEdit_password_2_re;
    QLabel *label_9;
    QPushButton *loginButton_3;
    QLabel *label_7;
    QLineEdit *lineEdit_email;
    QLabel *label_18;
    QWidget *page_3;
    QLabel *label_15;
    QTextEdit *textEdit_1;
    QLabel *label_12;
    QTextEdit *textEdit_2;
    QLabel *label_16;
    QPushButton *pushButton_2;
    QLabel *label_14;
    QLabel *label_17;
    QMenuBar *menubar;
    QMenu *menuPlagiarism_Checker;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName(QString::fromUtf8("actionLog_out"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 571));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(240, 270, 281, 41));
        QFont font;
        font.setPointSize(14);
        lineEdit_password->setFont(font);
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: #fff;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(page);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(360, 330, 161, 41));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 130, 111, 41));
        label->setFont(font);
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 410, 89, 25));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 415, 181, 16));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 230, 111, 41));
        label_2->setFont(font);
        lineEdit_login = new QLineEdit(page);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(240, 170, 281, 41));
        lineEdit_login->setFont(font);
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: #fff;"));
        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(330, 50, 81, 51));
        QFont font1;
        font1.setPointSize(24);
        label_13->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        lineEdit_login_2 = new QLineEdit(page_2);
        lineEdit_login_2->setObjectName(QString::fromUtf8("lineEdit_login_2"));
        lineEdit_login_2->setGeometry(QRect(160, 140, 221, 41));
        lineEdit_login_2->setFont(font);
        loginButton_2 = new QPushButton(page_2);
        loginButton_2->setObjectName(QString::fromUtf8("loginButton_2"));
        loginButton_2->setGeometry(QRect(460, 410, 161, 41));
        QFont font2;
        font2.setPointSize(13);
        loginButton_2->setFont(font2);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 100, 111, 41));
        label_4->setFont(font);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 190, 111, 41));
        label_5->setFont(font);
        lineEdit_fn = new QLineEdit(page_2);
        lineEdit_fn->setObjectName(QString::fromUtf8("lineEdit_fn"));
        lineEdit_fn->setGeometry(QRect(160, 230, 221, 41));
        lineEdit_fn->setFont(font);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 480, 181, 16));
        lineEdit_password_2 = new QLineEdit(page_2);
        lineEdit_password_2->setObjectName(QString::fromUtf8("lineEdit_password_2"));
        lineEdit_password_2->setGeometry(QRect(160, 320, 221, 41));
        lineEdit_password_2->setFont(font);
        lineEdit_password_2->setEchoMode(QLineEdit::Password);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 280, 111, 41));
        label_8->setFont(font);
        lineEdit_ln = new QLineEdit(page_2);
        lineEdit_ln->setObjectName(QString::fromUtf8("lineEdit_ln"));
        lineEdit_ln->setGeometry(QRect(400, 230, 221, 41));
        lineEdit_ln->setFont(font);
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(400, 190, 111, 41));
        label_11->setFont(font);
        lineEdit_password_2_re = new QLineEdit(page_2);
        lineEdit_password_2_re->setObjectName(QString::fromUtf8("lineEdit_password_2_re"));
        lineEdit_password_2_re->setGeometry(QRect(400, 320, 221, 41));
        lineEdit_password_2_re->setFont(font);
        lineEdit_password_2_re->setEchoMode(QLineEdit::Password);
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(400, 280, 171, 41));
        label_9->setFont(font);
        loginButton_3 = new QPushButton(page_2);
        loginButton_3->setObjectName(QString::fromUtf8("loginButton_3"));
        loginButton_3->setGeometry(QRect(330, 470, 91, 31));
        QFont font3;
        font3.setPointSize(11);
        loginButton_3->setFont(font3);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(320, 40, 131, 51));
        label_7->setFont(font1);
        lineEdit_email = new QLineEdit(page_2);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(400, 140, 221, 41));
        lineEdit_email->setFont(font);
        lineEdit_email->setEchoMode(QLineEdit::Normal);
        label_18 = new QLabel(page_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(400, 100, 111, 41));
        label_18->setFont(font);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_15 = new QLabel(page_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(70, 92, 256, 24));
        QFont font4;
        font4.setPointSize(16);
        label_15->setFont(font4);
        textEdit_1 = new QTextEdit(page_3);
        textEdit_1->setObjectName(QString::fromUtf8("textEdit_1"));
        textEdit_1->setGeometry(QRect(70, 122, 301, 291));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(180, 20, 421, 51));
        label_12->setFont(font1);
        textEdit_2 = new QTextEdit(page_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(420, 120, 301, 291));
        label_16 = new QLabel(page_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(420, 90, 256, 24));
        label_16->setFont(font4);
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(610, 440, 111, 41));
        QFont font5;
        font5.setPointSize(18);
        pushButton_2->setFont(font5);
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 440, 121, 41));
        QFont font6;
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setWeight(75);
        label_14->setFont(font6);
        label_17 = new QLabel(page_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(420, 440, 101, 41));
        label_17->setMinimumSize(QSize(100, 0));
        label_17->setFont(font5);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPlagiarism_Checker = new QMenu(menubar);
        menuPlagiarism_Checker->setObjectName(QString::fromUtf8("menuPlagiarism_Checker"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPlagiarism_Checker->menuAction());
        menuPlagiarism_Checker->addSeparator();
        menuPlagiarism_Checker->addSeparator();
        menuPlagiarism_Checker->addAction(actionLog_out);
        menuPlagiarism_Checker->addSeparator();
        menuPlagiarism_Checker->addAction(actionExit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plagiarism Checker", nullptr));
        actionLog_out->setText(QApplication::translate("MainWindow", "Log out", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "Log in", nullptr));
        label->setText(QApplication::translate("MainWindow", "ID", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Register", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Don't have account yet?", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Password", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Login", nullptr));
        loginButton_2->setText(QApplication::translate("MainWindow", "Sign up", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "ID", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "First Name", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Already have account? ", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Password", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Last Name", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Reenter password", nullptr));
        loginButton_3->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Sign Up", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Email", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Text 1", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Content Similarity Detection", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Text 2", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Check", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Similarity", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "0.00 %", nullptr));
        menuPlagiarism_Checker->setTitle(QApplication::translate("MainWindow", "Plagiarism Checker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
