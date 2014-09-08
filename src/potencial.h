#ifndef POTENCIAL_H
#define POTENCIAL_H

#include <QtGui>

class Potencial : public QObject
{
    Q_OBJECT
public:
    explicit Potencial(QObject *parent = 0);

signals:
    void signalNumberOfSample(int index, QVector<double> potencials);

public slots:
    void recognize();
    void slotSetSamples(QVector< QVector< QLabel* > > aSamples);
    void slotSetPattern(QImage aPattern);

protected:
    int compare(QImage i1, QImage i2);

private:
    QVector< QVector<QImage> > samples;
    QImage pattern;
    QWidget w;
};

#endif // POTENCIAL_H
