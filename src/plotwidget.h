#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QtGui>

class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);

signals:
    // send pattern image
    void pattern(QImage i);
    // start recognition process
    void recogrize();

protected:
    // processing repaint widget
    void paintEvent(QPaintEvent *event);

    // processing mouse events (click, move and release)
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paint();

    QImage createImage();
protected:
    QPointF from;
    QPointF to;

    QImage image;
    QPainter painter;
    QPen pen;

    static const int PLOT_WIDTH = 70;
    static const int PLOT_HEIGHT = 90;
    static const int PEN_WIDTH = 8;
};

#endif // PLOTWIDGET_H
