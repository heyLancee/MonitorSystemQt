#include "diagnosis_win.h"
#include "utils.h"

DiagnosisWin::DiagnosisWin(QMainWindow *parent) : QMainWindow(parent), ui(std::unique_ptr<Ui::DiagnosisWin>(new Ui::DiagnosisWin()))
{
    ui->setupUi(this);

    plotAlgo1 = std::unique_ptr<Plot>(new Plot(ui->chartView_Algo1, Qt::red, Qt::SolidLine, "Algorithm 1", "Time(s)", "Value", 0, 100, -0.02, 0.02));
    ui->chartView_Algo1->setChart(plotAlgo1->chart.get());

    plotAlgo2 = std::unique_ptr<Plot>(new Plot(ui->chartView_Algo2, Qt::red, Qt::SolidLine, "Algorithm 2", "Time(s)", "Value", 0, 100, -0.02, 0.02));
    ui->chartView_Algo2->setChart(plotAlgo2->chart.get());

    // 注册faultResultStruct类型
    qRegisterMetaType<FaultResultStruct>();
    qRegisterMetaType<FaultParams>();
}

void DiagnosisWin::on_cmdInjectButton_clicked()
{
    // 初步测试
    float startTime = ui->faultStartTime->value();
    float endTime = ui->faultEndTime->value();
    FaultType type = FaultType(ui->faultType->currentIndex() + 1);
    QString paramsString = ui->faultParams->text();
    // 将字符串分割成浮点数列表
    QStringList paramsList = paramsString.split(" ");
    // 去除空字符串
    paramsList.removeAll("");
    std::vector<double> params;
    params.resize(paramsList.size());
    for (int i = 0; i < paramsList.size(); ++i) {
        params[i] = paramsList[i].toFloat();
    }
    FaultParams faultData;
    faultData.faultStartTime = startTime;
    faultData.faultEndTime = endTime;
    faultData.faultType = type;
    faultData.params = params;
    if (
        type == FaultType::GYRO_INTERMITTENT_FAULT || 
        type == FaultType::GYRO_SLOW_FAULT ||
        type == FaultType::GYRO_SLOW_FAULT
    ) {
        faultData.gyro_fault_idx = ui->gyroIDSpin_2->value();
    }else if (
        type == FaultType::FLYWHEEL_PARTIAL_LOSS ||
        type == FaultType::FLYWHEEL_BIAS ||
        type == FaultType::FLYWHEEL_COMPREHENSIVE
    ) {
        faultData.flywheel_fault_idx = ui->FLywheelIDSpin->value();
    };

    QByteArray cmd = faultData.toByteArray();
    std::shared_ptr<QByteArray> cmdPtr = std::make_shared<QByteArray>(cmd);

    emit this->send_command_signal(cmdPtr, CommuDataType::FAULT_PARA);
}

void DiagnosisWin::draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType)
{
    if (dataType != CommuDataType::FAULT_RESULT || unpackedData == nullptr)
        return;

    FaultResultStruct udpData = unpackedData->value<FaultResultStruct>();

    /* 画图定时器timeout槽函数 */
    if (udpData.faultType == 1) {
        plotAlgo1->updateDataList(*plotAlgo1->axisX, *plotAlgo1->axisY, udpData.timeStep, udpData.faultValue);
    } else if (udpData.faultType == 2) {
        plotAlgo1->updateDataList(*plotAlgo2->axisX, *plotAlgo2->axisY, udpData.timeStep, udpData.faultValue);
    }
}
