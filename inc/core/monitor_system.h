#ifndef MONITOR_SYSTEM_H
#define MONITOR_SYSTEM_H

#include <QMainWindow>
#include <QThread>
#include "visualization_window.h"
#include "communication.h"
#include "diagnosis_win.h"
#include <memory>

class MonitorSystem : public QObject {
    Q_OBJECT

public:
    explicit MonitorSystem(QMainWindow *parent = nullptr);
    ~MonitorSystem();

public slots:
    void startCommunication(quint16 bindPort, QString targetIP, quint16 targetPort);
    void stopCommunication();

private:
    std::unique_ptr<visualWin> visualWindow;
    std::unique_ptr<diagnosisWin> diagWindow;
    std::unique_ptr<QThread> thread;
    std::unique_ptr<Communication> communication;
};

#endif // MONITOR_SYSTEM_H
