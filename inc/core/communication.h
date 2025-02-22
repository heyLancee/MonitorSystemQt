#ifndef UDPTHREAD_H
#define UDPTHREAD_H

#include <QObject>
#include <QUdpSocket>
#include <QThread>
#include <QtConcurrent>
#include <memory>
#include "utils/config_manager.h"
#include "data_processor.h"

class udpSocket : public QObject
{
public:
    udpSocket();

    std::unique_ptr<QUdpSocket> socket;
    quint16 bindPort;
    QString targetIP;
    quint16 targetPort;
    QHostAddress targetHostAddress;

    QString recvIP;
    quint16 recvPort;
    QHostAddress recvHostAddress;
};

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication();
    ~Communication() = default;

    bool init();

signals:
    void commu_start_success_signal();
    void commu_stop_success_signal();
    void commu_recv_success_signal(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType);

public slots:
    void send_command_slot(std::shared_ptr<QByteArray> command, CommuDataType dataType);
    void process_commu_data_slot();
    void commu_start_slot(quint16 bindPort, QString targetIP, quint16 targetPort);
    void commu_stop_slot();

private:
    std::unique_ptr<udpSocket> udp;
    
    std::unique_ptr<DataProcessor> dataProcessor;

    bool isInit = false;
};

#endif // UDPTHREAD_H
