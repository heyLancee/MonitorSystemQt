#ifndef VISUALIZATION_WINDOW_H
#define VISUALIZATION_WINDOW_H

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

    void set_comm_params(int localPort, QString remoteIP, int remotePort);

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

signals:
    void show_diag_window_signal();

signals:
    void commu_start_signal(quint16 bindPort,QString targetIP,quint16 targetPort);
    void commu_stop_signal();

public slots:
    void commu_start_success_slot();
    void commu_stop_success_slot();

    void draw_data(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType);

private slots:
    void on_OpenNewWidgetButton_2_clicked();
    void on_ClearUdpClientTextButton_clicked();
    void on_checkBox_8_stateChanged(int arg1);
    void on_StartButton_clicked();
    void on_StopButton_clicked();
    void on_CleanCanvasButton_clicked();

private:
void clear_data();
    std::unique_ptr<Ui::visualWin> ui;
};
#endif // VISUALIZATION_WINDOW_H
