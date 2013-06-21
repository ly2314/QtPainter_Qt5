#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QtWidgets>

namespace Ui {
class ResizeDialog;
}

class ResizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    ResizeDialog(QWidget *parent = 0);
    ~ResizeDialog();
    
signals:
    void setResize(int, int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ResizeDialog *ui;
};

#endif // RESIZEDIALOG_H
