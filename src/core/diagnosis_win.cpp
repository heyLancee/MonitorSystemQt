﻿#include "diagnosis_win.h"
#include "utils.h"

DiagnosisWin::DiagnosisWin(QMainWindow *parent) : QMainWindow(parent), ui(std::unique_ptr<Ui::DiagnosisWin>(new Ui::DiagnosisWin()))
{
    ui->setupUi(this);

    plotAlgo1 = std::unique_ptr<Plot>(new Plot(ui->chartView_Algo1, Qt::red, Qt::SolidLine, "Algorithm 1", "Time(s)", "Value", 0, 100, -0.02, 0.02));
    ui->chartView_Algo1->setChart(plotAlgo1->chart.get());

    plotAlgo2 = std::unique_ptr<Plot>(new Plot(ui->chartView_Algo2, Qt::red, Qt::SolidLine, "Algorithm 2", "Time(s)", "Value", 0, 100, -0.02, 0.02));
    ui->chartView_Algo2->setChart(plotAlgo2->chart.get());

    // 注册faultResultStruct类型
    qRegisterMetaType<faultResultStruct>();
}

void DiagnosisWin::on_cmdInjectButton_clicked()
{
    faultParaStruct faultPara;
    // 故障注入
    faultPara.faultTimeLow = ui->faultTimeDoubleSpin->value();
    faultPara.faultTimeUp = ui->faultTimeDoubleSpin_2->value();
    faultPara.faultAttLow = ui->faultAttDoubleSpin->value();
    faultPara.faultAttUp = ui->faultAttDoubleSpin_2->value();
    faultPara.faultType = ui->faultTypeCombo->currentIndex();

    faultPara.gyroGroup = ui->gyroGroupSpin->value()-1;
    faultPara.gyroID = ui->gyroIDSpin->value()-1;

    if (ui->rateDampRadio->isChecked())
    {
        faultPara.runMode = 1;
    }
    else if (ui->sunPointRadio->isChecked())
    {
        faultPara.runMode = 2;
    }
    else
    {
        faultPara.runMode = 3;
    }

    QByteArray cmd = faultPara.toByteArray();
    std::shared_ptr<QByteArray> cmdPtr = std::make_shared<QByteArray>(cmd);

    emit this->send_command_signal(cmdPtr, CommuDataType::faultParaType);
}

void DiagnosisWin::on_saveDataButton_clicked()
{
    /* 保存数据按钮 */
    saveDataStruct saveData;

    saveData.gyroIsChecked = ui->gyroCheckBox->isChecked();
    saveData.starIsChecked = ui->starCheckBox->isChecked();
    saveData.sunIsChecked = ui->sunCheckBox->isChecked();
    saveData.rwIsChecked = ui->rwCheckBox->isChecked();

    // 保存路径
    saveData.path = QFileDialog::getExistingDirectory(this, "选择文件夹", "/");
    if (saveData.path.isEmpty())
        return;
    
    QByteArray cmd = saveData.toByteArray();
    std::shared_ptr<QByteArray> cmdPtr = std::make_shared<QByteArray>(cmd);
    emit this->send_command_signal(cmdPtr, CommuDataType::saveDataType);
}

void DiagnosisWin::draw_plot(Plot* plot, QList<QPointF>& dataList, QValueAxis& axisX, QValueAxis& axisY, double timeStep, double data)
{
    plot->updateDataList(dataList, axisX, axisY, timeStep, data);
    plot->series->replace(dataList);
}


void DiagnosisWin::draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType)
{
    if (dataType != faultResultType || unpackedData == nullptr)
        return;

    faultResultStruct udpData = unpackedData->value<faultResultStruct>();

    /* 画图定时器timeout槽函数 */
    if (udpData.faultType == 1) {
        draw_plot(plotAlgo1.get(), faultRes1List, *plotAlgo1->axisX, *plotAlgo1->axisY, udpData.timeStep, udpData.faultValue);
    } else if (udpData.faultType == 2) {
        draw_plot(plotAlgo2.get(), faultRes2List, *plotAlgo2->axisX, *plotAlgo2->axisY, udpData.timeStep, udpData.faultValue);
    }
}
