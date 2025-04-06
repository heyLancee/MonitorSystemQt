#include "core/monitor_system.h"
#include "utils/config_manager.h"
#include <QApplication>
#include <QFileInfo>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);
    // 设置环境变量
    QString projectPath = QFileInfo(__FILE__).absolutePath() + "/../../";
    qputenv("PROJECT_PATH", projectPath.toUtf8());
    qputenv("ConfigPath", (projectPath + "config").toUtf8());

    // 初始化配置管理器
    if (!theConfigManager.init(projectPath + "config/config.json")){
        qDebug() << "Failed to init ConfigManager";
        return -1;
    }

    // 初始化包管理器
    QJsonObject platformCommands = theCommuConfig["PlatformCommands"].toObject();
    thePackageManager.setPackageParams(
        platformCommands["FrameHead"].toString().toUtf8(),
        platformCommands["FrameTail"].toString().toUtf8()
    );

    // 本地参数
    QJsonObject localParams = theCommuConfig["LocalParams"].toObject();
    int localPort = localParams["LocalPort"].toInt();

    // 远程参数
    QJsonObject remoteParams = theCommuConfig["RemoteParams"].toObject();
    QString remoteIP = remoteParams["RemoteIP"].toString();
    int remotePort = remoteParams["RemotePort"].toInt();

    MonitorSystem monitorSystemWindow;
    monitorSystemWindow.set_comm_params(localPort, remoteIP, remotePort);

    return app.exec();
}
