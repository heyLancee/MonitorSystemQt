#include "monitor_system.h"
#include <QDebug>

MonitorSystem::MonitorSystem(QMainWindow *parent)
{
    this->visualWindow = std::make_unique<visualWin>(parent);
    this->diagWindow = std::make_unique<diagnosisWin>(parent);

    this->thread = std::make_unique<QThread>();
    this->communication = std::make_unique<Communication>();
    this->communication->moveToThread(this->thread.get());

    this->visualWindow->show();
    this->diagWindow->hide();

    // 发送控制命令
    connect(this->visualWindow.get(), &visualWin::send_command_signal, this->communication.get(), &Communication::send_command_slot);

    // 自定义槽函数，用于启动线程并调用commu_start_slot
    connect(this->visualWindow.get(), &visualWin::commu_start_signal, this, &MonitorSystem::startCommunication);
    connect(this->communication.get(), &Communication::commu_start_success_signal, this->visualWindow.get(), &visualWin::commu_start_success_slot);

    // 自定义槽函数，用于停止线程并调用commu_stop_slot
    connect(this->visualWindow.get(), &visualWin::commu_stop_signal, this, &MonitorSystem::stopCommunication);
    connect(this->communication.get(), &Communication::commu_stop_success_signal, this->visualWindow.get(), &visualWin::commu_stop_success_slot);

    // 画图
    connect(this->communication.get(), &Communication::commu_recv_success_signal, this->visualWindow.get(), &visualWin::draw_data);

    // 故障诊断界面发出命令
    connect(this->diagWindow.get(), &diagnosisWin::send_command_signal, this->communication.get(), &Communication::send_command_slot);
}

void MonitorSystem::startCommunication(quint16 bindPort, QString targetIP, quint16 targetPort)
{
    if (!thread->isRunning()) {
        thread->start();
        this->visualWindow->ui->plainUdpClientTextEdit->appendPlainText("Thread Start");
        
        QMetaObject::invokeMethod(this->communication.get(), "commu_start_slot", Q_ARG(quint16, bindPort), Q_ARG(QString, targetIP), Q_ARG(quint16, targetPort));
        qDebug() << "Thread started";
    }
}

void MonitorSystem::stopCommunication()
{
    if (thread->isRunning()) {
        thread->quit();
        thread->wait();
        this->visualWindow->ui->plainUdpClientTextEdit->appendPlainText("Thread Stopped");
        
        QMetaObject::invokeMethod(this->communication.get(), "commu_stop_slot");
        qDebug() << "Thread stopped";
    }
}

MonitorSystem::~MonitorSystem()
{
    /* 界面关闭事件槽函数 */
    if(this->thread->isRunning())
    {
        this->thread->exit();
        this->thread->wait();
        this->thread->deleteLater();
    }
}
