#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>
#include "plagiarismcheck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void readSocket();

    void on_pushButton_clicked();

    void on_loginButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_loginButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket  _socket;
};
#endif // MAINWINDOW_H
