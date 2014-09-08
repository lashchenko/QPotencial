#include "potencial.h"
#include <QDebug>

Potencial::Potencial(QObject *parent) :
    QObject(parent)
{
}

void Potencial::recognize()
{
    int numberOfPatterns = samples.size();
    if( numberOfPatterns == 0 ) {
        return;
    }

    int numberOfChars = samples.first().size();
    if( numberOfChars == 0 ) {
        return;
    }

    QVector<double> potencials;

    for( int i=0; i<numberOfChars; ++i ) {
        potencials.append(0.0);
    }

    for( int i=0; i<numberOfChars; ++i ) {
        for( int j=0; j<numberOfPatterns; ++j ) {
            float R = compare(samples.at(j).at(i), pattern);
            potencials[i] += 1000000.0 / (1.0 + R*R);
        }
    }

    int index = 0;
    for( int i=0; i<potencials.size(); ++i ) {
        if( potencials.at(i) > potencials.at(index) ) {
            index = i;
        }
    }

    emit( signalNumberOfSample(index, potencials) );
}

// Calculating Hamming distance - count of different pixels.
int Potencial::compare(QImage i1, QImage i2)
{
   int count = 0;

   for( int x=0; x<i1.width(); ++x ) {
       for( int y=0; y<i1.height(); ++y ) {
           QColor c1;
           c1.setRgba(i1.pixel(x,y));

           QColor c2;
           c2.setRgba(i2.pixel(x,y));

           if( c1 != c2 ) {
               ++count;
           }
       }
   }
   return (count);
}

void Potencial::slotSetPattern(QImage aPattern)
{
    pattern = aPattern;
}

void Potencial::slotSetSamples(QVector<QVector<QLabel *> > aSamples)
{
    samples.clear();
    for( int i=0; i<aSamples.size(); ++i ) {
        samples.append(QVector<QImage>());
        for( int j=0; j<aSamples.at(i).size(); ++j ) {
            samples.last().append(aSamples.at(i).at(j)->pixmap()->toImage());
        }
    }
}
