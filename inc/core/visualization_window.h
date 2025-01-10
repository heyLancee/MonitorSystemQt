#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QThread>
#include <memory>
#include <QTimer>
#include <algorithm>
#include "communication.h"
#include "utils.h"
#include "base.h"
#include "ui_visualization_window.h"

QT_BEGIN_NAMESPACE

using namespace std;
QT_END_NAMESPACE

class visualWin : public QMainWindow
{
    Q_OBJECT
public:
    visualWin(QMainWindow *parent = nullptr);
    ~visualWin();

public:
    std::unique_ptr<class Plot> plotWX;
    std::unique_ptr<class Plot> plotWY;
    std::unique_ptr<class Plot> plotWZ;

    std::unique_ptr<class Plot> plotQ0;
    std::unique_ptr<class Plot> plotQ1;
    std::unique_ptr<class Plot> plotQ2;
    std::unique_ptr<class Plot> plotQ3;

    std::unique_ptr<class Plot> plotRX;
    std::unique_ptr<class Plot> plotRY;
    std::unique_ptr<class Plot> plotRZ;

    std::unique_ptr<class Plot> plotVX;
    std::unique_ptr<class Plot> plotVY;
    std::unique_ptr<class Plot> plotVZ;

    std::unique_ptr<class Plot> plotWboX;
    std::unique_ptr<class Plot> plotWboY;
    std::unique_ptr<class Plot> plotWboZ;

    std::unique_ptr<class Plot> plotQbo0;
    std::unique_ptr<class Plot> plotQbo1;
    std::unique_ptr<class Plot> plotQbo2;
    std::unique_ptr<class Plot> plotQbo3;

    std::unique_ptr<class Plot> plotZAngle;

    QList<QPointF> WXList;
    QList<QPointF> WYList;
    QList<QPointF> WZList;

    QList<QPointF> Q0List;
    QList<QPointF> Q1List;
    QList<QPointF> Q2List;
    QList<QPointF> Q3List;

    QList<QPointF> RXList;
    QList<QPointF> RYList;
    QList<QPointF> RZList;

    QList<QPointF> VXList;
    QList<QPointF> VYList;
    QList<QPointF> VZList;

    QList<QPointF> WboXList;
    QList<QPointF> WboYList;
    QList<QPointF> WboZList;

    QList<QPointF> Qbo0List;
    QList<QPointF> Qbo1List;
    QList<QPointF> Qbo2List;
    QList<QPointF> Qbo3List;

    QList<QPointF> zAngleList;

public:
    void draw_plot(Plot* plot, QList<QPointF>& dataList, QValueAxis& axisX, QValueAxis& axisY, double timeStep, double data);

signals:
    void show_diag_window_signal();

signals:
    void send_command_signal(std::shared_ptr<QByteArray> command, CommuDataType dataType);
    void commu_start_signal(quint16 bindPort,QString targetIP,quint16 targetPort);
    void commu_stop_signal();

public slots:
    void commu_start_success_slot();
    void commu_stop_success_slot();

    void draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType);

private slots:
    void on_OpenNewWidgetButton_2_clicked();
    void on_ClearUdpClientTextButton_clicked();
    void on_RunPlatformButton_clicked();
    void on_checkBox_8_stateChanged(int arg1);
    void on_StartButton_clicked();
    void on_StopButton_clicked();
    void on_StopPlatformButton_clicked();

private:
    std::unique_ptr<Ui::visualWin> ui;
};
#endif // MAINWINDOW_H
