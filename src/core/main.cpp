#include "monitor_system.h"
#include <QApplication>

int main(int argc, char *argv[])
{   
    // 设置环境变量
    QString projectPath = QFileInfo(__FILE__).absolutePath() + "/../..";
    QProcess::setEnvironment(QStringList() << "PROJECT_PATH=" + projectPath);
    QProcess::setEnvironment(QStringList() << "ConfigPath=" + projectPath + "/config");

    // 初始化配置管理器
    if (!theConfigManager.init(projectPath + "/config/config.json")){
        qDebug() << "Failed to init ConfigManager";
        return -1;
    }

    QApplication app(argc, argv);

    MonitorSystem monitorSystemWindow;

    return app.exec();
}
