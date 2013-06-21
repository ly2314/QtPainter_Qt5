#ifndef COLORBOX_H
#define COLORBOX_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QtWidgets>

class ColorBox : public QWidget
{
    Q_OBJECT

public:
    ColorBox(QWidget *parent = 0);
    void setTool(int i) { _tool = i; }

public slots:
    void mousePressEvent(QMouseEvent *event);

signals:
    void PenColor(QColor);
    void BrushColor(QColor);

protected:

private:
    int _tool; //Pen : 1, Brush : 2
};

#endif
