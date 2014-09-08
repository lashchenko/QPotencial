#ifndef SAMPLESITEM_H
#define SAMPLESITEM_H

#include <QtGui>

class SamplesItem : public QWidget
{
    Q_OBJECT
public:
    explicit SamplesItem(QString aCharset, QString aFont, QWidget *parent = 0);

    QVector< QLabel* > getSamples();
signals:
    void remove(QString fontName);

private slots:
    void remove();
    void setRecognizedChar(int index, QVector<double> potencials);

private:
    QLabel font;
    QVector< QLabel* > samples;

    QString charset;

    static const int ITEM_WIDTH = 70;
    static const int ITEM_HEIGHT = 90;
    static const int FONT_SIZE = 80;
};

#endif // SAMPLESITEM_H
