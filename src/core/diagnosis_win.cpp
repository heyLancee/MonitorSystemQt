#include "diagnosis_win.h"
#include "utils.h"

diagnosisWin::diagnosisWin(QMainWindow *parent) : QMainWindow(parent), ui(std::make_unique<Ui::diagnosisWin>())
{
    ui->setupUi(this);

    plotAlgo1 = std::make_unique<Plot>(Qt::red, Qt::SolidLine, "Algorithm 1", "Time(s)", "Value", 0, 100, -0.02, 0.02);
    ui->chartView_Algo1->setChart(plotAlgo1->chart);

    plotAlgo2 = std::make_unique<Plot>(Qt::red, Qt::SolidLine, "Algorithm 2", "Time(s)", "Value", 0, 100, -0.02, 0.02);
    ui->chartView_Algo2->setChart(plotAlgo2->chart);
}

void diagnosisWin::on_cmdInjectButton_clicked()
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

    emit this->send_command_signal(cmdPtr, CommuDataType::FaultInjectType);
}

void diagnosisWin::on_saveDataButton_clicked()
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
    emit this->send_command_signal(cmdPtr, CommuDataType::SaveDataType);
}

