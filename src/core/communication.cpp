#include <QThread>
#include <QDataStream>
#include <QDebug>
#include "communication.h"
#include "utils.h"
#include "base.h"

Communication::Communication()
{
    // 注册自定义类型用于信号槽
    qRegisterMetaType<std::shared_ptr<QVariant>>("std::shared_ptr<QVariant>");
    qRegisterMetaType<std::shared_ptr<QByteArray>>("std::shared_ptr<QByteArray>");
    qRegisterMetaType<CommuDataType>("CommuDataType");
}
bool Communication::init()
{
    if (isInit){
        return false;
    }

    this->udp = std::unique_ptr<udpSocket>(new udpSocket());

    // 初始化DataProcessor
    dataProcessor = std::unique_ptr<DataProcessor>(new DataProcessor());
    connect(dataProcessor.get(), &DataProcessor::data_processed_signal, this, &Communication::commu_recv_success_signal);

    this->isInit = true;
    qDebug() << "Communication init success";
    return true;
}

udpSocket::udpSocket()
{
    this->socket = std::unique_ptr<QUdpSocket>(new QUdpSocket());
}

void Communication::send_command_slot(std::shared_ptr<QByteArray> command, CommuDataType dataType)
{
    QByteArray packet = thePackageManager.package(*command, dataType);
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
        // 使用 QueuedConnection 确保信号在正确的线程中发送
        dataProcessor->moveToThread(QThread::currentThread());
        QtConcurrent::run([this, datagramPtr]() {
            dataProcessor->processData(datagramPtr);
        });
    }
}

void Communication::commu_start_slot(quint16 bindPort, QString targetIP, quint16 targetPort)
{
    this->udp->bindPort = bindPort;
    this->udp->targetIP = targetIP;
    this->udp->targetHostAddress = QHostAddress(targetIP);
    this->udp->targetPort = targetPort;

    if(this->udp->socket->bind(this->udp->bindPort))
    {
        connect(this->udp->socket.get(), &QUdpSocket::readyRead, this, &Communication::process_commu_data_slot);
        emit this->commu_start_success_signal();
    }
}

void Communication::commu_stop_slot()
{
    /* 主线程解除绑定信号send_Udp_Abort_Port的槽函数 */
    this->udp->socket->close();
    emit this->commu_stop_success_signal();
}
