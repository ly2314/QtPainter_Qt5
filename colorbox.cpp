#include <QtGui>
#include "colorbox.h"

ColorBox::ColorBox(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}

void ColorBox::mousePressEvent(QMouseEvent *event)
{
    QColor color = QColorDialog::getColor(QColor(0, 255, 0));
    if(color.isValid())
    {
        if (_tool == 1)
            emit PenColor(color);
        else if (_tool == 2)
            emit BrushColor(color);
    }
}
