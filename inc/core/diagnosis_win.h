#ifndef FAULTDIAGNOSIS_H
#define FAULTDIAGNOSIS_H

#include <QtCharts>
#include <QWidget>
#include <QMainWindow>
#include <memory>
#include "communication.h"
#include "ui_diagnosis_win.h"
#include "utils.h"
#include "base.h"
//#include <QStringConverter>

using namespace std;

class diagnosisWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit diagnosisWin(QMainWindow *parent = nullptr);
    ~diagnosisWin()=default;

    std::unique_ptr<class Plot> plotAlgo1;
    std::unique_ptr<class Plot> plotAlgo2;

signals:
    void send_command_signal(std::shared_ptr<QByteArray> command, CommuDataType dataType);

private slots:
    void on_cmdInjectButton_clicked();
    void on_saveDataButton_clicked();

private:
    std::unique_ptr<Ui::diagnosisWin> ui;
};

#endif // FAULTDIAGNOSIS_H
