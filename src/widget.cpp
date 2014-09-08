#include "widget.h"

#include "potencial.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Potencial *potencial = new Potencial();
    connect(potencial, SIGNAL(signalNumberOfSample(int,QVector<double>)),
            &samples, SIGNAL(signalRecognizedIndex(int,QVector<double>)));
    connect(&samples, SIGNAL(signalSamples(QVector<QVector<QLabel*> >)),
            potencial,SLOT(slotSetSamples(QVector<QVector<QLabel*> >)));

    connect(&plot, SIGNAL(pattern(QImage)), potencial, SLOT(slotSetPattern(QImage)));
    connect(&plot, SIGNAL(recogrize()), potencial, SLOT(recognize()));

    QHBoxLayout *hl = new QHBoxLayout;
    hl->addStretch();
    hl->addWidget(&plot);
    hl->addStretch();

    QVBoxLayout *l = new QVBoxLayout;
    l->addLayout(hl);
    l->addWidget(&charset);
    l->addWidget(&samples);
    setLayout(l);

    connect(&charset, SIGNAL(updateCharset(QString)), &samples, SLOT(slotUpdateSamples(QString)));

    setMinimumSize(800,600);

    charset.setText("iDKfA");
}

Widget::~Widget()
{

}
