#include "resizedialog.h"
#include "painter.h"
#include "ui_resizedialog.h"

extern int painter_w;
extern int painter_h;
extern bool painter_resized;

ResizeDialog::ResizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResizeDialog)
{
    ui->setupUi(this);
}

ResizeDialog::~ResizeDialog()
{
    delete ui;
}

void ResizeDialog::on_buttonBox_accepted()
{
    int w = ui->string_width->text().toInt();
    int h = ui->string_height->text().toInt();
    if (w == 0 || h == 0)
        return;
    else
    {
        painter_resized = true;
        painter_w = w;
        painter_h = h;
    }
}
