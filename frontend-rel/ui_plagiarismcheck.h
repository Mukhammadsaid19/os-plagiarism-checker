/********************************************************************************
** Form generated from reading UI file 'plagiarismcheck.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAGIARISMCHECK_H
#define UI_PLAGIARISMCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plagiarismcheck
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout_2;
    QLabel *loginLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *signButt;
    QPushButton *loginButt;
    QWidget *signUpPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *signUpLabel;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *loginButt2;
    QPushButton *signButt2;
    QWidget *homePage;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QPushButton *submitButt;
    QLabel *label_8;
    QPushButton *logOutButt;
    QLabel *label_9;
    QTextEdit *textEdit;

    void setupUi(QWidget *plagiarismcheck)
    {
        if (plagiarismcheck->objectName().isEmpty())
            plagiarismcheck->setObjectName(QString::fromUtf8("plagiarismcheck"));
        plagiarismcheck->resize(567, 397);
        centralwidget = new QWidget(plagiarismcheck);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 395, 275));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginPage->sizePolicy().hasHeightForWidth());
        loginPage->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(loginPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        loginLabel = new QLabel(loginPage);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        QFont font;
        font.setPointSize(26);
        loginLabel->setFont(font);
        loginLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(loginLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(loginPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(loginPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(loginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(loginPage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        signButt = new QPushButton(loginPage);
        signButt->setObjectName(QString::fromUtf8("signButt"));
        signButt->setFont(font1);

        horizontalLayout_3->addWidget(signButt);

        loginButt = new QPushButton(loginPage);
        loginButt->setObjectName(QString::fromUtf8("loginButt"));
        loginButt->setFont(font1);

        horizontalLayout_3->addWidget(loginButt);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(loginPage);
        signUpPage = new QWidget();
        signUpPage->setObjectName(QString::fromUtf8("signUpPage"));
        verticalLayout_3 = new QVBoxLayout(signUpPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        signUpLabel = new QLabel(signUpPage);
        signUpLabel->setObjectName(QString::fromUtf8("signUpLabel"));
        signUpLabel->setFont(font);
        signUpLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(signUpLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4 = new QLineEdit(signUpPage);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 1, 1, 1);

        lineEdit_5 = new QLineEdit(signUpPage);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 1, 1, 1);

        label_6 = new QLabel(signUpPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_6 = new QLineEdit(signUpPage);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 3, 1, 1, 1);

        label_5 = new QLabel(signUpPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(signUpPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label = new QLabel(signUpPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(signUpPage);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        loginButt2 = new QPushButton(signUpPage);
        loginButt2->setObjectName(QString::fromUtf8("loginButt2"));
        loginButt2->setFont(font1);

        horizontalLayout_5->addWidget(loginButt2);

        signButt2 = new QPushButton(signUpPage);
        signButt2->setObjectName(QString::fromUtf8("signButt2"));
        signButt2->setFont(font1);

        horizontalLayout_5->addWidget(signButt2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(signUpPage);
        homePage = new QWidget();
        homePage->setObjectName(QString::fromUtf8("homePage"));
        gridLayout_2 = new QGridLayout(homePage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(homePage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font2;
        font2.setPointSize(16);
        label_7->setFont(font2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        submitButt = new QPushButton(homePage);
        submitButt->setObjectName(QString::fromUtf8("submitButt"));
        submitButt->setFont(font1);

        gridLayout_2->addWidget(submitButt, 2, 0, 1, 1);

        label_8 = new QLabel(homePage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        logOutButt = new QPushButton(homePage);
        logOutButt->setObjectName(QString::fromUtf8("logOutButt"));
        logOutButt->setFont(font1);

        gridLayout_2->addWidget(logOutButt, 2, 1, 1, 1);

        label_9 = new QLabel(homePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font3;
        font3.setPointSize(11);
        label_9->setFont(font3);

        gridLayout_2->addWidget(label_9, 1, 1, 1, 1);

        textEdit = new QTextEdit(homePage);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);

        stackedWidget->addWidget(homePage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(plagiarismcheck);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(plagiarismcheck);
    } // setupUi

    void retranslateUi(QWidget *plagiarismcheck)
    {
        plagiarismcheck->setWindowTitle(QApplication::translate("plagiarismcheck", "MainWindow", nullptr));
        loginLabel->setText(QApplication::translate("plagiarismcheck", "Log In", nullptr));
        label_2->setText(QApplication::translate("plagiarismcheck", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("plagiarismcheck", "TextLabel", nullptr));
        signButt->setText(QApplication::translate("plagiarismcheck", "Sign Up", nullptr));
        loginButt->setText(QApplication::translate("plagiarismcheck", "Log In", nullptr));
        signUpLabel->setText(QApplication::translate("plagiarismcheck", "Sign Up", nullptr));
        label_6->setText(QApplication::translate("plagiarismcheck", "Password", nullptr));
        label_5->setText(QApplication::translate("plagiarismcheck", "Email", nullptr));
        label_4->setText(QApplication::translate("plagiarismcheck", "Last Name", nullptr));
        label->setText(QApplication::translate("plagiarismcheck", "First Name", nullptr));
        loginButt2->setText(QApplication::translate("plagiarismcheck", "Log In", nullptr));
        signButt2->setText(QApplication::translate("plagiarismcheck", "Sign Up", nullptr));
        label_7->setText(QApplication::translate("plagiarismcheck", "Input", nullptr));
        submitButt->setText(QApplication::translate("plagiarismcheck", "Submit", nullptr));
        label_8->setText(QApplication::translate("plagiarismcheck", "Output", nullptr));
        logOutButt->setText(QApplication::translate("plagiarismcheck", "Log Out", nullptr));
        label_9->setText(QApplication::translate("plagiarismcheck", "Output Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plagiarismcheck: public Ui_plagiarismcheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAGIARISMCHECK_H
