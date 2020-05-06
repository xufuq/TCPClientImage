#include "drawimage.h"

DrawImage::DrawImage(QWidget *parent) : QWidget(parent)
{
    QPalette pal(palette());
    Back_ground=QPixmap(":/img/JLUlogo.jpg");
    Back_ground=Back_ground.scaled(640,480);
    pal.setBrush(backgroundRole(),Back_ground);

    setAutoFillBackground(true);
    setPalette(pal);

    for(int i=0;i<256;i++)
    {
        vcolorTable.append(qRgb(i,i,i));
    }
    setFixedSize(640,480);
}


void DrawImage::paintEvent(QPaintEvent *event)
{
    QPainter *p=new QPainter(this);
    p->drawImage(0,0,qimage);
}


void DrawImage::PassImage(QImage &imagedata)
{
    qimage=imagedata;
}
