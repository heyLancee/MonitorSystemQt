﻿#include "visualization_window.h"
#include "utils.h"
#include "base.h"

visualWin::visualWin(QMainWindow *parent): QMainWindow(parent), ui(std::make_unique<Ui::visualWin>())
{
    /* 构造函数 */
    ui->setupUi(this);

    plotWX = std::make_unique<Plot>(ui->chartView_WX, Qt::red, Qt::DashLine, "omegaX", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1);
    plotWY = std::make_unique<Plot>(ui->chartView_WY, Qt::red, Qt::DashLine, "omegaY", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1);
    plotWZ = std::make_unique<Plot>(ui->chartView_WZ, Qt::red, Qt::DashLine, "omegaZ", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1);

    plotQ0 = std::make_unique<Plot>(ui->chartView_q0, Qt::red, Qt::DashLine, "Q0", "Time(s)", "", 0, 100, -1, 1);
    plotQ1 = std::make_unique<Plot>(ui->chartView_q1, Qt::red, Qt::DashLine, "Q1", "Time(s)", "", 0, 100, -1, 1);
    plotQ2 = std::make_unique<Plot>(ui->chartView_q2, Qt::red, Qt::DashLine, "Q2", "Time(s)", "", 0, 100, -1, 1);
    plotQ3 = std::make_unique<Plot>(ui->chartView_q3, Qt::red, Qt::DashLine, "Q3", "Time(s)", "", 0, 100, -1, 1);

    plotRX = std::make_unique<Plot>(ui->chartView_RX, Qt::red, Qt::DashLine, "RX", "Time(s)", "", 0, 100, 0, 10);
    plotRY = std::make_unique<Plot>(ui->chartView_RY, Qt::red, Qt::DashLine, "RY", "Time(s)", "", 0, 100, 0, 10);
    plotRZ = std::make_unique<Plot>(ui->chartView_RZ, Qt::red, Qt::DashLine, "RZ", "Time(s)", "", 0, 100, 0, 10);

    plotVX = std::make_unique<Plot>(ui->chartView_VX, Qt::red, Qt::DashLine, "VX", "Time(s)", "", 0, 100, 0, 10);
    plotVY = std::make_unique<Plot>(ui->chartView_VY, Qt::red, Qt::DashLine, "VY", "Time(s)", "", 0, 100, 0, 10);
    plotVZ = std::make_unique<Plot>(ui->chartView_VZ, Qt::red, Qt::DashLine, "VZ", "Time(s)", "", 0, 100, 0, 10);

    plotWboX = std::make_unique<Plot>(ui->chartView_WboX, Qt::red, Qt::DashLine, "WboX", "Time(s)", "", 0, 100, 0, 10);
    plotWboY = std::make_unique<Plot>(ui->chartView_WboY, Qt::red, Qt::DashLine, "WboY", "Time(s)", "", 0, 100, 0, 10);
    plotWboZ = std::make_unique<Plot>(ui->chartView_WboZ, Qt::red, Qt::DashLine, "WboZ", "Time(s)", "", 0, 100, 0, 10);

    plotQbo0 = std::make_unique<Plot>(ui->chartView_qbo0, Qt::red, Qt::DashLine, "Qbo0", "Time(s)", "", 0, 100, -1, 1);
    plotQbo1 = std::make_unique<Plot>(ui->chartView_qbo1, Qt::red, Qt::DashLine, "Qbo1", "Time(s)", "", 0, 100, -1, 1);
    plotQbo2 = std::make_unique<Plot>(ui->chartView_qbo2, Qt::red, Qt::DashLine, "Qbo2", "Time(s)", "", 0, 100, -1, 1);
    plotQbo3 = std::make_unique<Plot>(ui->chartView_qbo3, Qt::red, Qt::DashLine, "Qbo3", "Time(s)", "", 0, 100, -1, 1);

    plotZAngle = std::make_unique<Plot>(ui->chartView_zAngular, Qt::red, Qt::DashLine, "ZAngle", "Time(s)", "", 0, 100, -5, 5);
}

visualWin::~visualWin()
{
    // std::unique_ptr will automatically handle deletion
}

void visualWin::commu_start_success_slot()
{
    /* 子线程绑定端口信号的槽函数 */
    ui->plainUdpClientTextEdit->appendPlainText("Bind Port Success");
}

void visualWin::commu_stop_success_slot()
{
    /* 子线程绑定端口信号的槽函数 */
    ui->plainUdpClientTextEdit->appendPlainText("Unbind Port Success");
}

/**
 * @brief 通用绘图函数
 * 
 * @param plot 指向Plot对象的指针
 * @param dataList 数据列表
 * @param axisX X轴
 * @param axisY Y轴
 * @param timeStep 时间步长
 * @param data 数据
 */
void visualWin::draw_plot(Plot* plot, QList<QPointF>& dataList, QValueAxis* axisX, QValueAxis* axisY, double timeStep, double data)
{
    plot->updateDataList(dataList, axisX, axisY, timeStep, data);
    plot->series->replace(dataList);
}

void visualWin::draw_data(std::shared_ptr<void> unpackedData, CommuDataType dataType)
{
    if (dataType != telemetryType || unpackedData == nullptr)
        return;

    std::shared_ptr<telemetryStruct> udpData = std::static_pointer_cast<telemetryStruct>(unpackedData);

    /* 画图定时器timeout槽函数 */
    if (ui->checkBox->isChecked()) {
        draw_plot(plotWX.get(), WXList, plotWX->axisX, plotWX->axisY, udpData->timeStep, udpData->wx);
        draw_plot(plotWY.get(), WYList, plotWY->axisX, plotWY->axisY, udpData->timeStep, udpData->wy);
        draw_plot(plotWZ.get(), WZList, plotWZ->axisX, plotWZ->axisY, udpData->timeStep, udpData->wz);
    }
    if (ui->checkBox_2->isChecked()) {
        draw_plot(plotQ0.get(), Q0List, plotQ0->axisX, plotQ0->axisY, udpData->timeStep, udpData->q0);
        draw_plot(plotQ1.get(), Q1List, plotQ1->axisX, plotQ1->axisY, udpData->timeStep, udpData->q1);
        draw_plot(plotQ2.get(), Q2List, plotQ2->axisX, plotQ2->axisY, udpData->timeStep, udpData->q2);
        draw_plot(plotQ3.get(), Q3List, plotQ3->axisX, plotQ3->axisY, udpData->timeStep, udpData->q3);
    }
    if (ui->checkBox_3->isChecked()) {
        draw_plot(plotRX.get(), RXList, plotRX->axisX, plotRX->axisY, udpData->timeStep, udpData->rx);
        draw_plot(plotRY.get(), RYList, plotRY->axisX, plotRY->axisY, udpData->timeStep, udpData->ry);
        draw_plot(plotRZ.get(), RZList, plotRZ->axisX, plotRZ->axisY, udpData->timeStep, udpData->rz);
    }
    if (ui->checkBox_4->isChecked()) {
        draw_plot(plotVX.get(), VXList, plotVX->axisX, plotVX->axisY, udpData->timeStep, udpData->vx);
        draw_plot(plotVY.get(), VYList, plotVY->axisX, plotVY->axisY, udpData->timeStep, udpData->vy);
        draw_plot(plotVZ.get(), VZList, plotVZ->axisX, plotVZ->axisY, udpData->timeStep, udpData->vz);
    }
    if (ui->checkBox_5->isChecked()) {
        draw_plot(plotWboX.get(), WboXList, plotWboX->axisX, plotWboX->axisY, udpData->timeStep, udpData->wboX);
        draw_plot(plotWboY.get(), WboYList, plotWboY->axisX, plotWboY->axisY, udpData->timeStep, udpData->wboY);
        draw_plot(plotWboZ.get(), WboZList, plotWboZ->axisX, plotWboZ->axisY, udpData->timeStep, udpData->wboZ);
    }
    if (ui->checkBox_6->isChecked()) {
        draw_plot(plotQbo0.get(), Qbo0List, plotQbo0->axisX, plotQbo0->axisY, udpData->timeStep, udpData->qbo0);
        draw_plot(plotQbo1.get(), Qbo1List, plotQbo1->axisX, plotQbo1->axisY, udpData->timeStep, udpData->qbo1);
        draw_plot(plotQbo2.get(), Qbo2List, plotQbo2->axisX, plotQbo2->axisY, udpData->timeStep, udpData->qbo2);
        draw_plot(plotQbo3.get(), Qbo3List, plotQbo3->axisX, plotQbo3->axisY, udpData->timeStep, udpData->qbo3);
    }
    if (ui->checkBox_7->isChecked()) {
        draw_plot(plotZAngle.get(), zAngleList, plotZAngle->axisX, plotZAngle->axisY, udpData->timeStep, udpData->zAngle);
    }
}

void visualWin::on_OpenNewWidgetButton_2_clicked()
{
    /* 打开故障诊断界面 */
    this->diagWindow->show();
    this->diagWindow->raise();
}

void visualWin::on_ClearUdpClientTextButton_clicked()
{
    ui->plainUdpClientTextEdit->clear();
}

void visualWin::on_checkBox_8_stateChanged(int arg1)
{
    bool flag = false;
    if (arg1 == Qt::Checked)
    {
        flag = true;
    }
    ui->checkBox->setChecked(flag);
    ui->checkBox_2->setChecked(flag);
    ui->checkBox_3->setChecked(flag);
    ui->checkBox_4->setChecked(flag);
    ui->checkBox_5->setChecked(flag);
    ui->checkBox_6->setChecked(flag);
    ui->checkBox_7->setChecked(flag);
}


void visualWin::on_StartButton_clicked()
{
    /* 绑定端口按钮 */
    quint16 bindPort =ui->BindPortspinBox->value();
    QString targetIP=ui->TargetAddresslineEdit->text();
    quint16 targetPort=ui->TargetPortspinBox->value();

    emit this->commu_start_signal(bindPort, targetIP, targetPort); // 发送绑定信号给子线程
}


void visualWin::on_StopButton_clicked()
{
    /* 解除端口绑定按钮 */
    emit this->commu_stop_signal(); // 端口解绑信号，发送给子线程
}


void visualWin::on_RunPlatformButton_clicked()
{
    /* 运行仿真平台按钮 */
    float runTime = ui->simulationTimeSpin->value();
    QByteArray cmd(reinterpret_cast<const char*>(&runTime), sizeof(float));

    std::shared_ptr<QByteArray> cmdPtr = std::make_shared<QByteArray>(cmd);
    emit this->send_command_signal(cmdPtr, CommuDataType::RunPlatformType);
}

void visualWin::on_StopPlatformButton_clicked()
{
    /* 停止仿真平台按钮 */
    std::shared_ptr<QByteArray> cmdPtr = std::make_shared<QByteArray>();
    emit this->send_command_signal(cmdPtr, CommuDataType::StopPlatformType);
}

