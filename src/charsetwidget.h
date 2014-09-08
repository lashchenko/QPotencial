#ifndef CHARSETWIDGET_H
#define CHARSETWIDGET_H

#include <QtGui>

class CharsetWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CharsetWidget(QWidget *parent = 0);

    void setText(QString text);

signals:
    void updateCharset(QString text);

private:
    QLineEdit charset;
};

#endif // CHARSETWIDGET_H
