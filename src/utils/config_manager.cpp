#include "config_manager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QDir>


ConfigManager& ConfigManager::getInstance() {
    static ConfigManager instance;
    return instance;
}

bool ConfigManager::init(const QString& mainConfigPath) {
    if (!loadJsonFile(mainConfigPath, mainConfig)) {
        qDebug() << "Failed to load main config file";
        return false;
    }

    baseConfig = this->getConfig("base_config");
    commConfig = this->getConfig("commu_config");

    return true;
}

QJsonObject ConfigManager::getConfig(const QString& module) {
    // 如果配置已经被加载过，直接从缓存返回
    if (configCache.contains(module)) {
        return configCache[module];
    }
    
    // 从主配置中获取子配置文件路径
    auto configs = mainConfig["configs"].toObject();
    if (!configs.contains(module)) {
        qDebug() << "Module" << module << "not found in config";
        return QJsonObject();
    }
    
    // 加载子配置文件
    QString configPath = configs[module].toString();
    QString projectPath = qgetenv("PROJECT_PATH");

    QJsonObject moduleConfig;
    if (!loadJsonFile(projectPath+configPath, moduleConfig)) {
        qDebug() << "Failed to load config for module:" << module;
        return QJsonObject();
    }
    
    // 缓存并返回
    configCache[module] = moduleConfig;
    return moduleConfig;
}

bool ConfigManager::loadJsonFile(const QString& path, QJsonObject& output) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file:" << path;
        return false;
    }
    
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qDebug() << "Invalid JSON in file:" << path;
        return false;
    }
    
    output = doc.object();
    return true;
}

