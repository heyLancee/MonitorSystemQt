#include <QThread>
#include <QDataStream>
#include <QDebug>
#include "communication.h"
#include "utils.h"
#include "base.h"

Communication::Communication(QObject *parent) : QObject(parent)
{
    /* UDP类构造函数 */
    this->udp = std::unique_ptr<udpSocket>(new udpSocket());
    this->udp_config = theConfigManager.getConfig("commu_config");
    if(this->udp_config.isEmpty())
    {
        qDebug() << "commu_config is empty";
        return;
    }

    QJsonObject platformCommands = this->udp_config["PlatformCommands"].toObject();
    this->frameHeadArray = platformCommands["FrameHead"].toString().toUtf8();
    this->frameTailArray = platformCommands["FrameTail"].toString().toUtf8();

    // 初始化DataProcessor
    dataProcessor = std::unique_ptr<DataProcessor>(new DataProcessor());
    connect(dataProcessor.get(), &DataProcessor::data_processed_signal, this, &Communication::commu_recv_success_signal);
}

Communication::~Communication() {
    // std::unique_ptr will automatically handle deletion
}

udpSocket::udpSocket()
{
    this->socket = std::unique_ptr<QUdpSocket>(new QUdpSocket());
}

void Communication::send_command_slot(std::shared_ptr<QByteArray> command, CommuDataType dataType)
{
    // 创建封装后的数据包
    QByteArray packet;
    packet.append(this->frameHeadArray); // 添加帧头

    // 添加类型标识符
    packet.append(static_cast<char>(dataType));

    packet.append(*command);        // 添加数据
    packet.append(this->frameTailArray); // 添加帧尾

    // 通过UDP发送数据包
    this->udp->socket->writeDatagram(packet, this->udp->targetHostAddress, this->udp->targetPort);
}

void Communication::process_commu_data_slot()
{
    /* 处理UDP收到的数据，被动触发 */
    qint64 recvSize;

    while(this->udp->socket->hasPendingDatagrams()) // 有数据
    {
        QByteArray datagram;
        datagram.resize(this->udp->socket->pendingDatagramSize()); // 申请临时内存

        recvSize = this->udp->socket->readDatagram(datagram.data(), datagram.size(), 
                    &this->udp->recvHostAddress, &this->udp->recvPort);
        if (recvSize == -1)
            break;
        this->udp->recvIP = this->udp->recvHostAddress.toString();

        // 异步处理数据包
        std::shared_ptr<QByteArray> datagramPtr = std::make_shared<QByteArray>(datagram);
        QtConcurrent::run(dataProcessor.get(), &DataProcessor::processData, datagramPtr, this->frameHeadArray, this->frameTailArray);
    }
}

void Communication::commu_start_slot(quint16 bindPort, QString targetIP, quint16 targetPort)
{
    /* 主线程绑定端口信号send_Udp_Bind_Port的槽函数 */
    qDebug()<<"udp_tid:"<< QThread::currentThread();

    this->udp->bindPort = bindPort;
    this->udp->targetIP = targetIP;
    this->udp->targetHostAddress = QHostAddress(targetIP);
    this->udp->targetPort = targetPort;

    if(this->udp->socket->bind(this->udp->bindPort)) // 监听所有IP，等同于QHostAddress::Any绑定任意地址
    {
        connect(this->udp->socket.get(), SIGNAL(readyRead()), this, SLOT(process_commu_data_slot()));
        emit this->commu_start_success_signal();
    }
}

void Communication::commu_stop_slot()
{
    /* 主线程解除绑定信号send_Udp_Abort_Port的槽函数 */
    this->udp->socket->abort();
    emit this->commu_stop_success_signal();
}
