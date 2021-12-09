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
    _socket.connectToHost(QHostAddress::LocalHost, 8080);
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
            this->hide();
            plagiarismcheck plagiarismCheckWindow;
            plagiarismCheckWindow.setModal(true);
            plagiarismCheckWindow.exec();
//            QMessageBox::information(this, "Logged In!", status);
        }
        // If login failed
        else if (status == "403") {
            QMessageBox::information(this, "Incorrect login or password.", status);
        }
    }
}

void MainWindow::on_loginButton_clicked() {

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    QByteArray header;
    header.prepend(QString("route:api").toUtf8());
    header.resize(32);

    // Request format: <route> <arg1> <arg2> ... <argn>

    QByteArray byteArray = (QString("%1 %2 %3").arg(QString("login")).arg(login).arg(password)).toUtf8();

    // Send request to the server
    if(_socket.waitForConnected()) {
        _socket.write(byteArray);
    }

}
