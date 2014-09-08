#include "sampleswidget.h"

SamplesWidget::SamplesWidget(QWidget *parent) :
    QWidget(parent)
{
    scrollArea = new QScrollArea;

    layout.addWidget(new QLabel(trUtf8("Examples of samples: ")));
    layout.addWidget(&addFont);
    layout.addWidget(scrollArea);
    setLayout(&layout);

    addFont.setText(trUtf8("add"));
    connect(&addFont, SIGNAL(clicked()), this, SLOT(slotAddFont()));

    fonts.append("Arial");
}


void SamplesWidget::slotAddFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        fonts.append(font.family());
        slotUpdateSamples(charset);
    }
}

void SamplesWidget::slotUpdateSamples(QString aCharset)
{
    charset = aCharset;
    QVector< QVector<QLabel*> > labels;

    QVBoxLayout *l = new QVBoxLayout();
    for( int i=0; i<fonts.size(); ++i ) {
        SamplesItem *item = new SamplesItem(charset, fonts.at(i));
        connect(item, SIGNAL(remove(QString)), this, SLOT(slotRemove(QString)));
        connect(this, SIGNAL(signalRecognizedIndex(int,QVector<double>)),
                item, SLOT(setRecognizedChar(int,QVector<double>)));
        labels.append(item->getSamples());
        l->addWidget(item);
    }
    widget = new QWidget;
    widget->setLayout(l);

    layout.removeWidget(scrollArea);
    scrollArea->close();
    scrollArea = new QScrollArea;
    scrollArea->setWidget(widget);
    layout.addWidget(scrollArea);

    emit( signalSamples(labels) );

}

void SamplesWidget::slotRemove(QString font)
{
    for( int i=0; i<fonts.size(); ++i ) {
        if( fonts.at(i) == font ) {
            fonts.remove(i);
            break;
        }
    }
    slotUpdateSamples(charset);
}
