#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _socket(this)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
//    _socket.connectToHost(QHostAddress::LocalHost, 8080);

    _socket.connectToHost(QHostAddress("192.168.17.58"), 8080);
    connect(&_socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);

//    if(socket->waitForConnected())
//            ui->statusBar->showMessage("Connected to Server");
//    else {
//        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
//        exit(EXIT_FAILURE);
//    }
}

MainWindow::~MainWindow() {
    if(_socket.isOpen())
        _socket.close();
    delete ui;
}

// Response format: <route> <status_code>
void MainWindow::readSocket() {
    QByteArray datas = _socket.readAll();
    QString response = QString(datas);
    QStringList r_tokens = response.split(' ');

    QString route = r_tokens[0];
    QString status = r_tokens[1];

    if (route == "login") {
        // If login was successfull
        if (status == "201") {
            ui->stackedWidget->setCurrentIndex(2);
        }
        // If login failed
        else if (status == "403") {
            QMessageBox::information(this, status, "Incorrect login or password.");
        }
    } else if (route == "signup") {
        // If signup was successfull
        if (status == "201") {
            ui->stackedWidget->setCurrentIndex(2);
        }
        // If login failed
        else if (status == "500") {
            QMessageBox::information(this, status, "User with ID already exists.");
        }
    } else if (route == "check") {
            ui->label_17->setText(status.trimmed() + " %");
    }
}

void MainWindow::on_loginButton_clicked() {

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    ui->lineEdit_login->clear();
    ui->lineEdit_password->clear();

    // Request format: <route> <arg1> <arg2> ... <argn>
    QByteArray byteArray = (QString("%1 %2 %3").arg(QString("login")).arg(login).arg(password)).toUtf8();

    // Send request to the server
    if(_socket.waitForConnected()) {
        _socket.write(byteArray);
    }

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString text1 = ui->textEdit_1->toPlainText();
    QString text2 = ui->textEdit_2->toPlainText();

    // Request format: check <string1> <string2>
    QByteArray byteArray = (QString("%1 %2<<<%3").arg(QString("check")).arg(text1).arg(text2)).toUtf8();

    // Send request to the server
    if(_socket.waitForConnected()) {
        _socket.write(byteArray);
    }
}

void MainWindow::on_loginButton_2_clicked()
{
          QString id = ui->lineEdit_login_2->text();
          QString first_name = ui->lineEdit_fn->text();
          QString last_name = ui->lineEdit_ln->text();
          QString password = ui->lineEdit_password_2->text();
          QString repassword = ui->lineEdit_password_2_re->text();
          QString email = ui->lineEdit_email->text();

          ui->lineEdit_login_2->clear();
          ui->lineEdit_fn->clear();
          ui->lineEdit_ln->clear();
          ui->lineEdit_password_2->clear();
          ui->lineEdit_password_2_re->clear();
          ui->lineEdit_email->clear();

          QByteArray byteArray = (QString("%1 %2 %3 %4 %5 %6 %7").arg(QString("signup")).arg(id).arg(first_name).arg(last_name).arg(password).arg(email)).toUtf8();

          // Send request to the server
          if(_socket.waitForConnected()) {
              _socket.write(byteArray);
          }
}
