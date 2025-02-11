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
        platformCommands["FrameHead"].toString().toStdString(),
        platformCommands["FrameTail"].toString().toStdString()
    );

    MonitorSystem monitorSystemWindow;

    return app.exec();
}
