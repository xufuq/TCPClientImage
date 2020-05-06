#include "tcpclient.h"

TcpClient::TcpClient()
{
    Client=new QTcpSocket();
    image_receive=new QImage();
    PortString=new QString();
    IpString=new QString();

}

QString TcpClient::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
        for (int i=0;i<addList.count();i++)
        {
            QHostAddress aHost=addList.at(i);
            if (QAbstractSocket::IPv4Protocol==aHost.protocol())
            {
                localIP=aHost.toString();
                break;
            }
        }
        return localIP;
}

//设置服务器端的端口和IP地址
void TcpClient::SocketSet(QString port, QString IP)
{
    &PortString=port;
    &IpString=IP;
}
//启动client连接
void TcpClient::onConnected()
{
    Client->connectToHost(&IpString, &PortString);
}
//断开client连接
void TcpClient::DisConnected()
{
    if(Client->state()==QAbstractSocket::ConnectedState)
        Client->disconnectFromHost();
}
