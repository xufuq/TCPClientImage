#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QTcpSocket>
#include <QString>
#include <QImage>
#include <QTextEdit>  //用来接收设定的服务器IP
#include <QPushButton>//IP设定按钮，数据发送按钮
#include <QLabel>     //标识设定按钮
#include <QHostInfo>

class TcpClient
{
public:
    TcpClient();
    QString getLocalIP(); //获取本机IP地址
    void SocketSet(QString port, QString IP);     //用来设置服务器端的IP等信息
private:
    QTcpSocket *Client;
    QImage *image_receive;  //注意这里是指针形式
    QString *PortString;
    QString *IpString;
//    控件类都放到主窗口类中，通过槽函数设定
//    QLabel *IpLabel;
//    QLabel *PortLabel;
//    QPushButton *ForwardButton;
//    QPushButton *BackButton;
//    QPushButton *LeftButton;
//    QPushButton *RightButton;

private slots:
    void onConnected();
    void DisConnected();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onSocketReadyRead(); //读取socket传入的数据
};

#endif // TCPCLIENT_H
