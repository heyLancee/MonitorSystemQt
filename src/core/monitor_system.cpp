#include "monitor_system.h"
#include <QDebug>

MonitorSystem::MonitorSystem(QMainWindow *parent)
{
    this->visualWindow = std::unique_ptr<visualWin>(new visualWin(parent));
    this->diagWindow = std::unique_ptr<DiagnosisWin>(new DiagnosisWin(parent));

    this->thread = std::unique_ptr<QThread>(new QThread());
    this->communication = std::unique_ptr<Communication>(new Communication());

    this->visualWindow->show();
    this->diagWindow->hide();

    // 连接线程启动信号到初始化槽
    connect(thread.get(), &QThread::started, communication.get(), &Communication::init);
    this->communication->moveToThread(this->thread.get());

    // 自定义槽函数，用于启动线程并调用commu_start_slot
    connect(this->visualWindow.get(), &visualWin::commu_start_signal, this, &MonitorSystem::startCommunication);
    connect(this->communication.get(), &Communication::commu_start_success_signal, this->visualWindow.get(), &visualWin::commu_start_success_slot, Qt::QueuedConnection);

    // 自定义槽函数，用于停止线程并调用commu_stop_slot
    connect(this->visualWindow.get(), &visualWin::commu_stop_signal, this, &MonitorSystem::stopCommunication);
    connect(this->communication.get(), &Communication::commu_stop_success_signal, this->visualWindow.get(), &visualWin::commu_stop_success_slot, Qt::QueuedConnection);

    // 画图
    connect(this->communication.get(), &Communication::commu_recv_success_signal, this->visualWindow.get(), &visualWin::draw_data, Qt::QueuedConnection);
    connect(this->communication.get(), &Communication::commu_recv_success_signal, this->diagWindow.get(), &DiagnosisWin::draw_data, Qt::QueuedConnection);

    // 故障诊断界面发出命令
    connect(this->diagWindow.get(), &DiagnosisWin::send_command_signal, this->communication.get(), &Communication::send_command_slot, Qt::QueuedConnection);

    // 故障诊断界面显示
    connect(this->visualWindow.get(), &visualWin::show_diag_window_signal, this->diagWindow.get(), [&](){
        this->diagWindow->show();
        this->visualWindow->show();
    });
}

void MonitorSystem::startCommunication(quint16 bindPort, QString targetIP, quint16 targetPort)
{
    if (!thread->isRunning()) {    
        thread->start();    
    }
    QMetaObject::invokeMethod(this->communication.get(), "commu_start_slot", Q_ARG(quint16, bindPort), Q_ARG(QString, targetIP), Q_ARG(quint16, targetPort));
}

void MonitorSystem::stopCommunication()
{
    if (thread->isRunning()) {        
        QMetaObject::invokeMethod(this->communication.get(), "commu_stop_slot");
    }
}

void MonitorSystem::set_comm_params(int localPort, QString remoteIP, int remotePort)
{
    this->visualWindow->set_comm_params(localPort, remoteIP, remotePort);
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
