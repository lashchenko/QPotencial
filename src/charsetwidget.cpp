#include "charsetwidget.h"

CharsetWidget::CharsetWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *l = new QHBoxLayout();
    l->addWidget(new QLabel(trUtf8("Chars to recognition: ")));
    l->addWidget(&charset);
    setLayout(l);

    connect(&charset, SIGNAL(textChanged(QString)), this, SIGNAL(updateCharset(QString)));
}

void CharsetWidget::setText(QString text)
{
    charset.setText(text);
}
