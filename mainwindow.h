#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include <QImage>
#include <QPainter>
#include <QTextEdit>  //用来接收设定的服务器IP
#include <QPushButton>//IP设定按钮，数据发送按钮
#include <QLabel>     //标识设定按钮
#include <QHostInfo>
#include <QSpinBox>
#include <QComboBox>
#include <QKeyEvent>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QBuffer>
#include <QPixmap>
#include <QIODevice>
#include <QImageReader>
#include "drawimage.h"

#define IMAGESIZE 921600

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getLocalIP(); //获取本机IP地址
protected:
    void closeEvent(QCloseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    int imagewidth, imageheight;
    QTcpSocket *Client;
    QImage *image_receive;  //注意这里是指针形式
    uchar imagebuffer[IMAGESIZE];
    int imagecount;
//    控件类都放到主窗口类中，通过槽函数设定
    QLabel *IpLabel;
    QLabel *PortLabel;
    QLabel *TextOutLabel;
    QLabel *ReceiveLabel;
    QTextEdit *ReceiveCount;
    QTextEdit *TextOutWord;
    QTextEdit *IpText;
    QSpinBox  *PortText;
    DrawImage *DrawPainter;
    QPushButton *IfConnect;
    QVBoxLayout *AllScreen;
    QHBoxLayout *BottomSrc;
private slots:
    void On_Dis_Connected();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onSocketReadyRead(); //读取socket传入的数据
};

#endif // MAINWINDOW_H
