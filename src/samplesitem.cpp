#include "samplesitem.h"

SamplesItem::SamplesItem(QString aCharset, QString aFont, QWidget *parent) :
    QWidget(parent)
{
    charset = aCharset;
    font.setText(aFont);

    QHBoxLayout *l = new QHBoxLayout();
    l->addWidget(&font);

    for( int i=0; i<charset.size(); ++i ) {
        QLabel *label = new QLabel();
        l->addWidget(label);
        samples.append(label);
    }

    setRecognizedChar(-1,QVector<double>());

    QPushButton *removeButton = new QPushButton(trUtf8("Remove"));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(remove()));
    l->addWidget(removeButton);

    setLayout(l);
}

void SamplesItem::setRecognizedChar(int index, QVector<double> potencials)
{
    Q_ASSERT(charset.size() == samples.size());

    for( int i=0; i<charset.size(); ++i ) {
        QPixmap *pixmap = new QPixmap(ITEM_WIDTH,ITEM_HEIGHT);
        pixmap->fill(); // fill default color = WHITE;

        QPainter painter;
        painter.begin(pixmap);
        painter.setFont(QFont(font.text(), FONT_SIZE));
        if( index == i ) {
            painter.setPen(Qt::white);
            pixmap->fill(Qt::black);
        } else {
            painter.setPen(Qt::black);
        }
        painter.drawText(10, ITEM_HEIGHT-10, tr("%1").arg(charset.at(i)));
        painter.end();

        samples.at(i)->setPixmap(*pixmap);
        if( potencials.size() == charset.size() ) {
            samples.at(i)->setToolTip( tr("%1").arg(potencials.at(i)) );
        }
    }
}

QVector< QLabel* > SamplesItem::getSamples()
{
    return samples;
}

void SamplesItem::remove()
{
    emit(remove(font.text()));
}
