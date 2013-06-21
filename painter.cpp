#include "painter.h"
#include "ui_painter.h"
#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QColorDialog>
#include <QCursor>
#include <QFontDialog>
#include <QPalette>

int painter_w;
int painter_h;
bool painter_resized = false;

Painter::Painter(QWidget *parent) : QMainWindow(parent), ui(new Ui::Painter)
{
    ui->setupUi(this);
    ui->color_pen->setTool(1);
    ui->color_back->setTool(2);
    New_File();
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(Open_File()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(Save_File()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(Save_As()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(New_File()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(About()));
    connect(ui->actionRecover, SIGNAL(triggered()), this, SLOT(Undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(Redo()));
    connect(ui->actionCopy, SIGNAL(triggered()), this, SLOT(Copy()));
    connect(ui->actionCut, SIGNAL(triggered()), this, SLOT(Cut()));
    connect(ui->actionPaste, SIGNAL(triggered()), this, SLOT(Paste()));
    connect(ui->paint_area, SIGNAL(setSize(int,int)), this, SLOT(setSize(int,int)));
    connect(ui->color_pen, SIGNAL(PenColor(QColor)), this, SLOT(PenColor(QColor)));
    connect(ui->color_back, SIGNAL(BrushColor(QColor)), this, SLOT(FillColor(QColor)));
    connect(ui->paint_area, SIGNAL(setSize(int,int)), this, SLOT(setSize(int,int)));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), this, SLOT(AboutQt()));
    connect(ui->paint_area, SIGNAL(noUndo()), this, SLOT(noUndo()));
    connect(ui->paint_area, SIGNAL(noRedo()), this, SLOT(noRedo()));
    connect(ui->paint_area, SIGNAL(enableRedo()), this, SLOT(enableRedo()));
    connect(ui->paint_area, SIGNAL(enableUndo()), this, SLOT(enableUndo()));
    connect(ui->paint_area, SIGNAL(noCopy()), this, SLOT(noCopy()));
    connect(ui->paint_area, SIGNAL(canCopy()), this, SLOT(canCopy()));
    connect(ui->paint_area, SIGNAL(canPaste()), this, SLOT(canPaste()));
    connect(ui->actionResize, SIGNAL(triggered()), this, SLOT(showReisize()));
    ui->width_string->installEventFilter(this);
    ui->spray_string->installEventFilter(this);
}

Painter::~Painter()
{
    delete ui;
}

void Painter::on_setwidth_clicked()
{
    int w = ui->width_string->text().toInt();
    if (w != 0)
        ui->paint_area->setPenWidth(w);
}

void Painter::on_tool_pencil_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(1);
    QPixmap mouseCursor = QPixmap(":/img/cursor_pencil.gif");
    QCursor _Cur(mouseCursor, 5, 18);
    ui->paint_area->setCursor(_Cur);
}

void Painter::on_tool_eraser_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(2);
    QPixmap mouseCursor = QPixmap(":/img/tool_eraser.gif");
    QCursor _Cur(mouseCursor, 5, 18);
    ui->paint_area->setCursor(_Cur);
}

void Painter::Open_File()
{
    QString filename =  QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.xpm *.jpg)"));
    ui->paint_area->openImage(filename);
    _filename = filename;
    _opened = true;
    Resize();
}

void Painter::Save_File()
{
    if (_opened == true || _saved == true)
        ui->paint_area->saveImage(_filename, "png");
    else
        Painter::Save_As();
}

void Painter::Save_As()
{
    QString filename =  QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Images (*.png)"));
    ui->paint_area->saveImage(filename, "png");
    _filename = filename;
    _saved = true;
}

void Painter::on_tool_line_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(3);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::on_tool_rectangle_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(4);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::About()
{
    QMessageBox::about(this, "About", "NTUEE Ting-Yuan Hsia");
}

void Painter::New_File()
{
    ui->paint_area->clearImage();
    _opened = false;
    _saved = false;
    _filename = "";
    _font = QFont("Consolas", 10, QFont::Normal);
    ui->paint_area->setPenColor(Qt::black);
    ui->paint_area->setBackColor(QColor(0, 0, 0, 0));
    ui->paint_area->setPenWidth(1);
    ui->paint_area->setFont(_font);
    ui->label_Font->setFont(_font);
    QPalette _pen = ui->color_pen->palette();
    QPalette _back = ui->color_back->palette();
    QPalette _fill_back = ui->color_back_frame->palette();
    QPalette _fill_pen = ui->color_pen_frame->palette();
    _fill_pen.setColor(QPalette::Background, Qt::black);
    _fill_back.setColor(QPalette::Background, Qt::white);
    _pen.setColor(QPalette::Background, QColor(0, 0, 0, 0));
    _back.setColor(QPalette::Background, QColor(0, 0, 0, 0));
    ui->color_back->autoFillBackground();
    ui->color_pen->autoFillBackground();
    ui->color_pen->setPalette(_pen);
    ui->color_back->setPalette(_back);
    ui->paint_area->clearHistory();
    ui->color_back_frame->autoFillBackground();
    ui->color_pen_frame->autoFillBackground();
    ui->color_pen_frame->setPalette(_fill_pen);
    ui->color_back_frame->setPalette(_fill_back);
    ui->paint_area->setGeometry(9, 9, 400, 300);
    ui->scrollAreaWidgetContents->setGeometry(0, 0, 418, 318);
    Resize();
}

void Painter::on_tool_eclipse_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(5);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::on_tool_word_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(7);
    ui->paint_area->setCursor(Qt::IBeamCursor);
}

void Painter::on_tool_RoundRect_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(8);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::on_tool_Cursor_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(0);
    ui->paint_area->setCursor(Qt::ArrowCursor);
}

void Painter::on_set_Font_clicked()
{
    bool isOk;
    QFont font = QFontDialog::getFont(&isOk, QFont("Consolas", 18));
    if (isOk)
    {
        ui->paint_area->setPenFont(font);
        _font = font;
        ui->label_Font->setFont(font);
    }
}

void Painter::on_tool_Bucket_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(6);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::Undo()
{
    ui->paint_area->Undo();
}

void Painter::Redo()
{
    ui->paint_area->Redo();
}

void Painter::on_tool_Select_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(9);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::Cut()
{
    ui->paint_area->Cut();
}

void Painter::Copy()
{
    ui->paint_area->Copy();
}

void Painter::Paste()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(10);
    ui->paint_area->setCursor(Qt::CrossCursor);
}

void Painter::on_tool_spray_clicked()
{
    if (ui->paint_area->getZoom())
        ui->paint_area->zoomRecover();
    ui->paint_area->setTool(11);
    QPixmap mouseCursor = QPixmap(":/img/cursor_spray.png");
    QCursor _Cur(mouseCursor, 30, 0);
    ui->paint_area->setCursor(_Cur);
}

void Painter::on_setSpray_clicked()
{
    int w = ui->spray_string->text().toInt();
    if (w != 0)
        ui->paint_area->setSprayWidth(w);
}

void Painter::Resize()
{
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollAreaWidgetContents->setMinimumSize(ui->paint_area->getWidth() + 20, ui->paint_area->getHeight() + 20);
    ui->scrollAreaWidgetContents->setMaximumSize(ui->paint_area->getWidth() + 20, ui->paint_area->getHeight() + 20);
}

void Painter::on_tool_glass_clicked()
{
    ui->paint_area->setTool(12);
    QPixmap mouseCursor = QPixmap(":/img/cursor_glass.png");
    QCursor _Cur(mouseCursor, 30, 0);
    ui->paint_area->setCursor(_Cur);
}

void Painter::PenColor(QColor color)
{
    QPalette _pen = ui->color_pen->palette();
    _pen.setColor(QPalette::Background, color);
    ui->color_pen_frame->setPalette(_pen);
    ui->paint_area->setPenColor(color);
}

void Painter::FillColor(QColor color)
{
    QPalette _pen = ui->color_pen->palette();
    _pen.setColor(QPalette::Background, color);
    ui->color_back_frame->setPalette(_pen);
    ui->paint_area->setBackColor(color);
}

void Painter::setSize(int x, int y)
{
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollAreaWidgetContents->setMinimumSize(x, y);
    ui->scrollAreaWidgetContents->setMaximumSize(x, y);
}

void Painter::AboutQt()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void Painter::noRedo()
{
    ui->actionRedo->setEnabled(false);
}

void Painter::noUndo()
{
    ui->actionRecover->setEnabled(false);
}

void Painter::enableRedo()
{
    ui->actionRedo->setEnabled(true);
}

void Painter::canPaste()
{
    ui->actionPaste->setEnabled(true);
}

void Painter::enableUndo()
{
    ui->actionRecover->setEnabled(true);
}

void Painter::noCopy()
{
    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
}

void Painter::canCopy()
{
    ui->actionCopy->setEnabled(true);
    ui->actionCut->setEnabled(true);
}

void Painter::showReisize()
{
    ResizeDialog a;
    a.exec();
    if (painter_resized)
    {
        ui->paint_area->ReSize(painter_w, painter_h);
        painter_resized = false;
    }
}

bool Painter::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->width_string && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
        {
            int w = ui->width_string->text().toInt();
            if (w != 0)
            {
                ui->paint_area->setPenWidth(w);
                return true;
            }
            else
                return QMainWindow::eventFilter(object, event);
        }
        else
        {
            return QMainWindow::eventFilter(object, event);
        }
    }
    else if (object == ui->spray_string && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
        {
            int w = ui->spray_string->text().toInt();
            if (w != 0)
            {
                ui->paint_area->setSprayWidth(w);
                return true;
            }
            else
                return QMainWindow::eventFilter(object, event);
        }
        else
        {
            return QMainWindow::eventFilter(object, event);
        }
    }
    else
    {
        return QMainWindow::eventFilter(object, event);
    }
}
