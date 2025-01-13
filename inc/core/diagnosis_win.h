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

class DiagnosisWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit DiagnosisWin(QMainWindow *parent = nullptr);
    ~DiagnosisWin()=default;

    std::unique_ptr<class Plot> plotAlgo1;
    std::unique_ptr<class Plot> plotAlgo2;

    void draw_plot(Plot *plot, QList<QPointF> &dataList, QValueAxis &axisX, QValueAxis &axisY, double timeStep, double data);
    void draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType);

signals:
    void send_command_signal(std::shared_ptr<QByteArray> command, CommuDataType dataType);

private slots:
    void on_cmdInjectButton_clicked();
    void on_saveDataButton_clicked();

private:
    std::unique_ptr<Ui::DiagnosisWin> ui;
    QList<QPointF> faultRes1List;
    QList<QPointF> faultRes2List;

};

#endif // FAULTDIAGNOSIS_H
