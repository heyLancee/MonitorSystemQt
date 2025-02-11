#include "visualization_window.h"
#include "utils.h"
#include "base.h"

visualWin::visualWin(QMainWindow *parent): QMainWindow(parent), ui(std::unique_ptr<Ui::visualWin>(new Ui::visualWin()))
{
    /* 构造函数 */
    ui->setupUi(this);

    plotWX = std::unique_ptr<Plot>(new Plot(ui->chartView_WX, Qt::red, Qt::DashLine, "omegaX", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1));
    plotWY = std::unique_ptr<Plot>(new Plot(ui->chartView_WY, Qt::red, Qt::DashLine, "omegaY", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1));
    plotWZ = std::unique_ptr<Plot>(new Plot(ui->chartView_WZ, Qt::red, Qt::DashLine, "omegaZ", "Time(s)", "Omega(deg/s)", 0, 100, 0, 1));

    plotQ0 = std::unique_ptr<Plot>(new Plot(ui->chartView_q0, Qt::red, Qt::DashLine, "Q0", "Time(s)", "", 0, 100, -1, 1));
    plotQ1 = std::unique_ptr<Plot>(new Plot(ui->chartView_q1, Qt::red, Qt::DashLine, "Q1", "Time(s)", "", 0, 100, -1, 1));
    plotQ2 = std::unique_ptr<Plot>(new Plot(ui->chartView_q2, Qt::red, Qt::DashLine, "Q2", "Time(s)", "", 0, 100, -1, 1));
    plotQ3 = std::unique_ptr<Plot>(new Plot(ui->chartView_q3, Qt::red, Qt::DashLine, "Q3", "Time(s)", "", 0, 100, -1, 1));

    plotRX = std::unique_ptr<Plot>(new Plot(ui->chartView_RX, Qt::red, Qt::DashLine, "RX", "Time(s)", "", 0, 100, 0, 10));
    plotRY = std::unique_ptr<Plot>(new Plot(ui->chartView_RY, Qt::red, Qt::DashLine, "RY", "Time(s)", "", 0, 100, 0, 10));
    plotRZ = std::unique_ptr<Plot>(new Plot(ui->chartView_RZ, Qt::red, Qt::DashLine, "RZ", "Time(s)", "", 0, 100, 0, 10));

    plotVX = std::unique_ptr<Plot>(new Plot(ui->chartView_VX, Qt::red, Qt::DashLine, "VX", "Time(s)", "", 0, 100, 0, 10));
    plotVY = std::unique_ptr<Plot>(new Plot(ui->chartView_VY, Qt::red, Qt::DashLine, "VY", "Time(s)", "", 0, 100, 0, 10));
    plotVZ = std::unique_ptr<Plot>(new Plot(ui->chartView_VZ, Qt::red, Qt::DashLine, "VZ", "Time(s)", "", 0, 100, 0, 10));

    plotWboX = std::unique_ptr<Plot>(new Plot(ui->chartView_WboX, Qt::red, Qt::DashLine, "WboX", "Time(s)", "", 0, 100, 0, 10));
    plotWboY = std::unique_ptr<Plot>(new Plot(ui->chartView_WboY, Qt::red, Qt::DashLine, "WboY", "Time(s)", "", 0, 100, 0, 10));
    plotWboZ = std::unique_ptr<Plot>(new Plot(ui->chartView_WboZ, Qt::red, Qt::DashLine, "WboZ", "Time(s)", "", 0, 100, 0, 10));

    plotQbo0 = std::unique_ptr<Plot>(new Plot(ui->chartView_qbo0, Qt::red, Qt::DashLine, "Qbo0", "Time(s)", "", 0, 100, -1, 1));
    plotQbo1 = std::unique_ptr<Plot>(new Plot(ui->chartView_qbo1, Qt::red, Qt::DashLine, "Qbo1", "Time(s)", "", 0, 100, -1, 1));
    plotQbo2 = std::unique_ptr<Plot>(new Plot(ui->chartView_qbo2, Qt::red, Qt::DashLine, "Qbo2", "Time(s)", "", 0, 100, -1, 1));
    plotQbo3 = std::unique_ptr<Plot>(new Plot(ui->chartView_qbo3, Qt::red, Qt::DashLine, "Qbo3", "Time(s)", "", 0, 100, -1, 1));

    plotZAngle = std::unique_ptr<Plot>(new Plot(ui->chartView_zAngular, Qt::red, Qt::DashLine, "ZAngle", "Time(s)", "", 0, 100, -5, 5));

    // 注册telemetryStruct类型
    qRegisterMetaType<telemetryStruct>();
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

void visualWin::draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType)
{
    if (dataType != telemetryType || unpackedData == nullptr)
        return;

    telemetryStruct udpData = unpackedData->value<telemetryStruct>();

    /* 画图定时器timeout槽函数 */
    if (ui->checkBox->isChecked()) {
        plotWX->updateDataList(*plotWX->axisX, *plotWX->axisY, udpData.timeStep, udpData.wx);
        plotWY->updateDataList(*plotWY->axisX, *plotWY->axisY, udpData.timeStep, udpData.wy);
        plotWZ->updateDataList(*plotWZ->axisX, *plotWZ->axisY, udpData.timeStep, udpData.wz);
    }
    if (ui->checkBox_2->isChecked()) {
        plotQ0->updateDataList(*plotQ0->axisX, *plotQ0->axisY, udpData.timeStep, udpData.q0);
        plotQ1->updateDataList(*plotQ1->axisX, *plotQ1->axisY, udpData.timeStep, udpData.q1);
        plotQ2->updateDataList(*plotQ2->axisX, *plotQ2->axisY, udpData.timeStep, udpData.q2);
        plotQ3->updateDataList(*plotQ3->axisX, *plotQ3->axisY, udpData.timeStep, udpData.q3);
    }
    if (ui->checkBox_3->isChecked()) {
        plotRX->updateDataList(*plotRX->axisX, *plotRX->axisY, udpData.timeStep, udpData.rx);
        plotRY->updateDataList(*plotRY->axisX, *plotRY->axisY, udpData.timeStep, udpData.ry);
        plotRZ->updateDataList(*plotRZ->axisX, *plotRZ->axisY, udpData.timeStep, udpData.rz);
    }
    if (ui->checkBox_4->isChecked()) {
        plotVX->updateDataList(*plotVX->axisX, *plotVX->axisY, udpData.timeStep, udpData.vx);
        plotVY->updateDataList(*plotVY->axisX, *plotVY->axisY, udpData.timeStep, udpData.vy);
        plotVZ->updateDataList(*plotVZ->axisX, *plotVZ->axisY, udpData.timeStep, udpData.vz);
    }
    if (ui->checkBox_5->isChecked()) {
        plotWboX->updateDataList(*plotWboX->axisX, *plotWboX->axisY, udpData.timeStep, udpData.wboX);
        plotWboY->updateDataList(*plotWboY->axisX, *plotWboY->axisY, udpData.timeStep, udpData.wboY);
        plotWboZ->updateDataList(*plotWboZ->axisX, *plotWboZ->axisY, udpData.timeStep, udpData.wboZ);
    }
    if (ui->checkBox_6->isChecked()) {
        plotQbo0->updateDataList(*plotQbo0->axisX, *plotQbo0->axisY, udpData.timeStep, udpData.qbo0);
        plotQbo1->updateDataList(*plotQbo1->axisX, *plotQbo1->axisY, udpData.timeStep, udpData.qbo1);
        plotQbo2->updateDataList(*plotQbo2->axisX, *plotQbo2->axisY, udpData.timeStep, udpData.qbo2);
        plotQbo3->updateDataList(*plotQbo3->axisX, *plotQbo3->axisY, udpData.timeStep, udpData.qbo3);
    }
    if (ui->checkBox_7->isChecked()) {
        plotZAngle->updateDataList(*plotZAngle->axisX, *plotZAngle->axisY, udpData.timeStep, udpData.zAngle);
    }
}

void visualWin::on_CleanCanvasButton_clicked()
{
    // 清除所有数据
    plotWX->series->clear();
    plotWY->series->clear();
    plotWZ->series->clear();
    plotQ0->series->clear();
    plotQ1->series->clear();
    plotQ2->series->clear();
    plotQ3->series->clear();
    plotRX->series->clear();
    plotRY->series->clear();
    plotRZ->series->clear();
    plotVX->series->clear();
    plotVY->series->clear();
    plotVZ->series->clear();
    plotWboX->series->clear();
    plotWboY->series->clear();
    plotWboZ->series->clear();
    plotQbo0->series->clear();
    plotQbo1->series->clear();
    plotQbo2->series->clear();
    plotQbo3->series->clear();
    plotZAngle->series->clear();
}

void visualWin::on_OpenNewWidgetButton_2_clicked()
{
    /* 打开故障诊断界面 */
    emit show_diag_window_signal();
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

    ui->plainUdpClientTextEdit->appendPlainText("Thread Start");

    emit this->commu_start_signal(bindPort, targetIP, targetPort); // 发送绑定信号给子线程
}


void visualWin::on_StopButton_clicked()
{
    /* 解除端口绑定按钮 */
    ui->plainUdpClientTextEdit->appendPlainText("Thread Stopped");
    emit this->commu_stop_signal(); // 端口解绑信号，发送给子线程
}

