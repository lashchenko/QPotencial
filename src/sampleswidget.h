#ifndef SAMPLESWIDGET_H
#define SAMPLESWIDGET_H

#include <QtGui>
#include "samplesitem.h"

class SamplesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SamplesWidget(QWidget *parent = 0);

signals:
    void signalRecognizedIndex(int index, QVector<double> potencials);
    void signalSamples(QVector< QVector<QLabel*> > samples);
public slots:
    void slotUpdateSamples(QString aCharset);
    void slotAddFont();
    void slotRemove(QString font);

private:
    QString charset;
    QVector< QString > fonts;
    QVector< SamplesItem > items;

    QWidget *widget;
    QScrollArea *scrollArea;

    QPushButton addFont;
    QVBoxLayout layout;
};

#endif // SAMPLESWIDGET_H
