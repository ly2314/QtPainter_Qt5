#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QtWidgets>
#include <QFont>
#include <vector>

class PaintArea : public QWidget
{
    Q_OBJECT

public:
    PaintArea(QWidget *parent = 0);

    // File Operation
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);

    // Options
    void setPenColor(const QColor &newColor);
    void setBackColor(const QColor);
    void setPenWidth(int newWidth);
    void setPenFont(const QFont);
    void setSprayWidth(const int);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

    // Tools
    void setTool(const int);
    // Pointer = 0, Pencil = 1, Eraser = 2, Line = 3, Rectangle = 4, Eclipse = 5, Bucket = 6, word = 7, RounRect = 8
    // Copy, Cut = 9, Paste = 10, spray = 11, Glass = 12

    void Undo();
    void Redo();
    void Copy();
    void Cut();
    void Paste(const QPoint);
    void clearHistory();
    int getHeight() { return _size_y; }
    int getWidth()  { return _size_x;  }
    void zoomIn();
    void zoomOut();
    void zoomRecover();
    bool getZoom() { return _scaled; }
    void ReSize(int, int);

public slots:
    void clearImage();
    void print();

signals:
    void PenColor(QColor);
    void FillColor(QColor);
    void setSize(int, int);
    void noRedo();
    void noUndo();
    void enableRedo();
    void enableUndo();
    void canPaste();
    void canCopy();
    void noCopy();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:

    // Tools
    void drawLineTo(const QPoint &endPoint);
    void drawEraser(const QPoint &endPoint);
    void drawStraightLine(const QPoint, const QPoint);
    void drawRectangle(const QPoint, const QPoint);
    void drawEclipse(const QPoint, const QPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    void drawWord(const QPoint);
    void drawRectRound(const QPoint, const QPoint);
    void drawBucket(const QPoint);
    void fillColor(const QColor);
    void clearFillColor();
    void AddHistory() { _history.push_back(image);}
    void drawCopyRect(const QPoint, const QPoint);
    void drawSpray(const QPoint);

    bool modified;
    void setPenColor();
    bool _isselect;
    bool scribbling;
    int myPenWidth;
    int myEraserWidth;
    QColor myPenColor;
    QColor myFillColor;
    QColor myEraseColor;
    QImage image;
    QImage _scroll;
    QImage _copy;
    QPoint lastPoint;
    QFont myPenFont;
    int _tool;
    std::vector<QImage> _history;
    std::vector<QImage> _redo;
    QRect _select;
    std::vector<QPoint> _fill;
    bool _right;
    int mySprayWidth;
    QImage _before_scale;
    bool _scaled;
    double _size_x;
    double _size_y;

};

#endif
