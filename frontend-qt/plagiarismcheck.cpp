#include "plagiarismcheck.h"
#include "ui_plagiarismcheck.h"

plagiarismcheck::plagiarismcheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plagiarismcheck)
{
    ui->setupUi(this);
}

plagiarismcheck::~plagiarismcheck()
{
    delete ui;
}
