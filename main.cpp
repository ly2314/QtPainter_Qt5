#include <QtWidgets/QApplication>
#include "painter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Painter w;
    w.show();
    
    return a.exec();
}
