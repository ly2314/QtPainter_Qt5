#include <QtGui>
#include <cstdlib>
#include <ctime>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::black;
    myFillColor = Qt::white;
    _tool = 0;
    _scroll = image;
    _isselect = false;
    _right = false;
    mySprayWidth = 10;
    _scaled = false;
    _size_x = 400;
    _size_y = 300;
    emit setSize(_size_x, _size_y);
    emit noRedo();
    emit noUndo();
    srand (time(NULL));
}

// File Operations
bool PaintArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;
    _size_x = loadedImage.width();
    _size_y = loadedImage.height();
    resize(_size_x, _size_y);
    setMinimumSize(_size_x, _size_y);
    setMaximumSize(_size_x, _size_y);
    emit setSize(_size_x, _size_y);
    image = loadedImage;
    modified = false;
    _scaled = false;
    update();
    _history.clear();
    _redo.clear();
    emit noRedo();
    emit noUndo();
    return true;
}

bool PaintArea::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    if (visibleImage.save(fileName, fileFormat))
    {
        modified = false;
        return true;
    }
    else
        return false;
}

// Options

void PaintArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void PaintArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void PaintArea::setBackColor(const QColor newColor)
{
    myFillColor = newColor;
}

void PaintArea::clearImage()
{
    _size_x = 400;
    _size_y = 300;
    resize(_size_x, _size_y);
    setMinimumSize(_size_x, _size_y);
    setMaximumSize(_size_x, _size_y);
    image = QImage(_size_x, _size_y, QImage::Format_ARGB32);
    emit setSize(_size_x, _size_y);
    image.fill(qRgb(255, 255, 255));
    modified = true;
    _scaled = false;
    _before_scale = image;
    update();
}

void PaintArea::setPenFont(const QFont newFont)
{
    myPenFont = newFont;
}

void PaintArea::setSprayWidth(const int w)
{
    mySprayWidth = w;
}

// Tools

void PaintArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    if (!_right)
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    else
        painter.setPen(QPen(myFillColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void PaintArea::setTool(const int i)
{
    _tool = i;
}

void PaintArea::drawStraightLine(const QPoint startPoint, const QPoint endPoint)
{
    QPainter painter(&image);
    if (!_right)
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    else
        painter.setPen(QPen(myFillColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(startPoint, endPoint);
    int rad = (myPenWidth / 2) + 2;
    update(QRect(startPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
    update();
}

void PaintArea::drawRectangle(const QPoint startPoint, const QPoint endPoint)
{
    QPainter painter(&image);
    if (!_right)
    {
        painter.setBrush(myFillColor);
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    }
    else
    {
        painter.setBrush(myPenColor);
        painter.setPen(QPen(myFillColor, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    }
    painter.drawRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
    lastPoint = endPoint;
    update();
}

void PaintArea::drawCopyRect(const QPoint startPoint, const QPoint endPoint)
{
    QPainter painter(&image);
    painter.setBrush(QColor(0, 0, 0, 0));
    painter.setPen(QPen(Qt::black, 1, Qt::DashLine, Qt::SquareCap, Qt::MiterJoin));
    painter.drawRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
    lastPoint = endPoint;
    update();
    _select = QRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
    _isselect = true;
    emit canCopy();
}

void PaintArea::drawEclipse(const QPoint startPoint, const QPoint endPoint)
{
    QRectF area(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
    QPainter painter(&image);
    if (!_right)
    {
        painter.setBrush(myFillColor);
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else
    {
        painter.setBrush(myPenColor);
        painter.setPen(QPen(myFillColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter.drawEllipse(area);
    update();
    lastPoint = endPoint;
}

void PaintArea::drawWord(const QPoint endPoint)
{
    bool isOK;
    QString text = QInputDialog::getText(this, "Input", "Please type some word.", QLineEdit::Normal, "", &isOK);
    if(isOK)
    {
        QPainter painter(&image);
        painter.setFont(myPenFont);
        painter.drawText(endPoint, text);
        update();
        lastPoint = endPoint;
    }
}

void PaintArea::drawEraser(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(Qt::white, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;
    update();
    lastPoint = endPoint;
}

void PaintArea::drawRectRound(const QPoint startPoint, const QPoint endPoint)
{
    int x1 = startPoint.x();
    int x2 = endPoint.x();
    int y1 = startPoint.y();
    int y2 = endPoint.y();
    QRectF area;
    if (x2 >= x1)
    {
        if (y2 >= y1)
            area = QRectF(x1, y1, x2 - x1, y2 - y1);
        else
            area = QRectF(x1, y2, x2 - x1, y1 - y2);
    }
    else
    {
        if (y2 >= y1)
            area = QRectF(x2, y1, x1 - x2, y2 - y1);
        else
            area = QRectF(x2, y2, x1 - x2, y1 - y2);
    }
    QPainter painter(&image);
    if (!_right)
    {
        painter.setBrush(myFillColor);
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else
    {
        painter.setBrush(myPenColor);
        painter.setPen(QPen(myFillColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter.drawRoundedRect(area, 10, 10, Qt::RelativeSize);
    update();
    lastPoint = endPoint;
}

void PaintArea::drawBucket(const QPoint endPoint)
{
    int x = endPoint.x();
    int y = endPoint.y();
    _fill.clear();
    QColor current(image.pixel(x, y));
    if (!_right)
    {
        if (current != myPenColor && myPenColor != QColor(0, 0, 0, 0))
        {
            _fill.push_back(endPoint);
            fillColor(current);
        }
    }
    else
    {
        if (current != myFillColor && myFillColor != QColor(0, 0, 0, 0))
        {
            _fill.push_back(endPoint);
            fillColor(current);
        }
    }
    update();
    lastPoint = endPoint;
}

void PaintArea::fillColor(const QColor oldColor)
{
    while (_fill.size() != 0)
    {
        QPoint point = _fill.back();
        int x = point.x();
        int y = point.y();
        if (!_right)
            image.setPixel(point, myPenColor.rgb());
        else
            image.setPixel(point, myFillColor.rgb());
        _fill.pop_back();
        if (image.valid(x + 1, y))
        {
            if (image.pixel(QPoint(x + 1, y)) == oldColor.rgb())
                _fill.push_back(QPoint(x + 1, y));
        }
        if (image.valid(x - 1, y))
        {
            if (image.pixel(QPoint(x - 1, y)) == oldColor.rgb())
                _fill.push_back(QPoint(x - 1, y));
        }
        if (image.valid(x, y + 1))
        {
            if (image.pixel(QPoint(x, y + 1)) == oldColor.rgb())
                _fill.push_back(QPoint(x, y + 1));
        }
        if (image.valid(x, y - 1))
        {
            if (image.pixel(QPoint(x, y - 1)) == oldColor.rgb())
                _fill.push_back(QPoint(x, y - 1));
        }
    }
}

void PaintArea::Redo()
{
    if (_redo.size() != 0)
    {
        _history.push_back(image);
        emit enableUndo();
        image = _redo.back();
        _redo.pop_back();
        update();
    }
    if (_redo.size() == 0)
        emit noRedo();

}

void PaintArea::Undo()
{
    if (_history.size() != 0)
    {
        _redo.push_back(image);
        emit enableRedo();
        image = _history.back();
        _history.pop_back();
        update();
    }
    if (_history.size() == 0)
        emit noUndo();

}

void PaintArea::Copy()
{
    QRect select(_select.x() + 1, _select.y() + 1, _select.width() - 1, _select.height() - 1);
    _copy = image.copy(select);
    Undo();
    _history.push_back(image);
    emit enableUndo();
    emit canPaste();
    emit noCopy();
}

void PaintArea::Cut()
{
    Copy();
    QPainter painter(&image);
    painter.setBrush(Qt::white);
    painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    painter.drawRect(_select);
    update();
    _history.push_back(image);
    emit enableUndo();
    emit canPaste();
    emit noCopy();
}

void PaintArea::Paste(const QPoint endPoint)
{
    QPainter painter(&image);
    painter.drawImage(endPoint, _copy);
    update();
}

void PaintArea::drawSpray(const QPoint endPoint)
{
    int x = endPoint.x();
    int y = endPoint.y();
    int r = mySprayWidth;
    for (int i = r; i > -r; --i)
    {
        for (int j = r; j > -r; --j)
        {
            if (i * i + j * j > r * r)
                continue;
            if (image.valid(x + i, y + j))
            {
                int _ran = rand() % 100 + 1;
                if (_ran <= 10)
                {
                    if (!_right)
                        image.setPixel(QPoint(x + i, y + j), myPenColor.rgb());
                    else
                        image.setPixel(QPoint(x + i, y + j), myFillColor.rgb());
                }
            }
        }
    }
    update();
}

// Others

void PaintArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        _right = true;
    else
        _right = false;
    if (_tool != 0)
    {
        _redo.clear();
        emit noRedo();
    }
    if (_isselect)
    {
        Undo();
        _isselect = false;
        emit noCopy();
    }
    lastPoint = event->pos();
    if (_tool == 7)
    {
        _history.push_back(image);
        emit enableUndo();
        drawWord(lastPoint);
    }
    else if (_tool == 6)
    {
        _history.push_back(image);
        emit enableUndo();
        drawBucket(event->pos());
    }
    else if (_tool == 10)
    {
        _history.push_back(image);
        emit enableUndo();
        Paste(event->pos());
    }
    else if (_tool == 12)
    {
        if (event->button() == Qt::LeftButton)
            zoomIn();
        else
            zoomOut();
    }
    else
    {
        _history.push_back(image);
        emit enableUndo();
        _scroll = image;
        scribbling = true;
        if (_tool == 1)
            drawLineTo(event->pos());
        else if (_tool == 2)
            drawEraser(event->pos());
        else if (_tool == 11)
            drawSpray(event->pos());
    }
}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if (_tool == 1)
    {
        if (scribbling)
            drawLineTo(event->pos());
    }
    else if (_tool == 2)
    {
        if (scribbling)
            drawEraser(event->pos());
    }
    else if (_tool == 3)
    {
        image = _scroll;
        QPoint This = lastPoint;
        _scroll = image;
        drawStraightLine(lastPoint, event->pos());
        lastPoint = This;
    }
    else if (_tool == 4)
    {
        image = _scroll;
        QPoint This = lastPoint;
        _scroll = image;
        drawRectangle(lastPoint, event->pos());
        lastPoint = This;
    }
    else if (_tool == 5)
    {
        image = _scroll;
        QPoint This = lastPoint;
        _scroll = image;
        drawEclipse(lastPoint, event->pos());
        lastPoint = This;
    }
    else if (_tool == 8)
    {
        image = _scroll;
        QPoint This = lastPoint;
        _scroll = image;
        drawRectRound(lastPoint, event->pos());
        lastPoint = This;
    }
    else if (_tool == 9)
    {
        image = _scroll;
        QPoint This = lastPoint;
        _scroll = image;
        drawCopyRect(lastPoint, event->pos());
        lastPoint = This;
    }
    else if (_tool == 11)
    {
        if (scribbling)
            drawSpray(event->pos());
    }
}

void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (_tool == 1)
    {
        if (event->button() == Qt::LeftButton && scribbling)
        {
            drawLineTo(event->pos());
            scribbling = false;
        }
    }
    else if (_tool == 2)
    {
        if (event->button() == Qt::LeftButton && scribbling)
        {
            drawEraser(event->pos());
            scribbling = false;
        }
    }
    else if (_tool == 3)
    {
        drawStraightLine(lastPoint, event->pos());
    }
    else if (_tool == 4)
    {
        drawRectangle(lastPoint, event->pos());
    }
    else if (_tool == 5)
    {
        drawEclipse(lastPoint, event->pos());
    }
    else if (_tool == 8)
    {
        drawRectRound(lastPoint, event->pos());
    }
    else if (_tool == 11)
    {
        if ((event->buttons() & Qt::LeftButton) && scribbling)
            drawSpray(event->pos());
    }
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void PaintArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void PaintArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void PaintArea::print()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
    if (printDialog->exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_NO_PRINTER
}

void PaintArea::clearHistory()
{
    _history.clear();
    _redo.clear();
    emit noUndo();
    emit noRedo();
}

void PaintArea::zoomIn()
{
    if (!_scaled)
    {
        _before_scale = image;
        _scaled = true;
    }
    else if (_scaled)
    {
        image = _before_scale;
    }
    _size_x *= 1.25;
    _size_y *= 1.25;
    int x = _size_x;
    int y = _size_y;
    QImage temp = image.scaled(x, y);
    setMinimumSize(x, y);
    setMaximumSize(x, y);
    image = temp;
    emit setSize(x, y);
    update();
}

void PaintArea::zoomOut()
{
    if (!_scaled)
    {
        _before_scale = image;
        _scaled = true;
    }
    else if (_scaled)
    {
        image = _before_scale;
    }
    _size_x *= 0.8;
    _size_y *= 0.8;
    int x = _size_x;
    int y = _size_y;
    QImage temp = image.scaled(x, y);
    setMinimumSize(x, y);
    setMaximumSize(x, y);
    image = temp;
    emit setSize(x, y);
    update();
}

void PaintArea::zoomRecover()
{
    image = _before_scale;
    _size_x = image.width();
    _size_y = image.height();
    _scaled = false;
    emit setSize(_size_x, _size_y);
    update();
}

void PaintArea::ReSize(int x, int y)
{
    setMinimumSize(x, y);
    setMaximumSize(x, y);
    emit setSize(x, y);
    _size_x = x;
    _size_y = y;
}
