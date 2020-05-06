#ifndef DRAWIMAGE_H
#define DRAWIMAGE_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPalette>      //设置背景颜色等
#include <QDebug>
#include <QImage>
#include <QBuffer>

class DrawImage : public QWidget
{
    Q_OBJECT
public:
    explicit DrawImage(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void PassImage(QImage &imagedata);
signals:

public slots:

private:
    QPixmap  Back_ground;
    QImage   qimage;
    QVector<QRgb> vcolorTable;
};

#endif // DRAWIMAGE_H
