#ifndef PLAGIARISMCHECK_H
#define PLAGIARISMCHECK_H

#include <QDialog>

namespace Ui {
class plagiarismcheck;
}

class plagiarismcheck : public QDialog
{
    Q_OBJECT

public:
    explicit plagiarismcheck(QWidget *parent = nullptr);
    ~plagiarismcheck();

private:
    Ui::plagiarismcheck *ui;
};

#endif // PLAGIARISMCHECK_H
