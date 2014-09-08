#include "plotwidget.h"
#include <QDebug>

PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(PLOT_WIDTH,PLOT_HEIGHT);
    setMaximumSize(PLOT_WIDTH,PLOT_HEIGHT);

    pen = QPen(Qt::black, PEN_WIDTH);

    image = createImage();
    update();
}

void PlotWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    painter.begin(this);
    painter.drawImage(0,0,image);
    painter.end();
}

void PlotWidget::mousePressEvent(QMouseEvent *event)
{
    // if right click --> clear plotter.
    if( event->button() == Qt::RightButton ) {
        image = createImage();
        update();
        return;
    }

    from = event->posF();
}

void PlotWidget::mouseMoveEvent(QMouseEvent *event)
{
    to = event->posF();
    paint();
    from = to;
}

void PlotWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if( event->button() == Qt::RightButton ) {
        return;
    }

    to = event->posF();
    paint();

    // send pattern image for recognition
    emit( pattern(image) );
    // send signal for starting recognize process
    emit( recogrize() );
}

QImage PlotWidget::createImage()
{
    QPixmap pixmap(size());
    pixmap.fill();
    return pixmap.toImage();
}

void PlotWidget::paint()
{
    painter.begin(&image);
    painter.setPen(pen);
    painter.drawLine(from, to);
    painter.end();
    update();
}
