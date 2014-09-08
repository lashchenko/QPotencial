#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

#include "charsetwidget.h"
#include "sampleswidget.h"
#include "plotwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    CharsetWidget charset;
    SamplesWidget samples;
    PlotWidget plot;
};

#endif // WIDGET_H
