#include  <QtGui> //<QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    w.showMaximized();
//    w.showFullScreen();
    QApplication::setStyle(new QPlastiqueStyle());
    return a.exec();
}
