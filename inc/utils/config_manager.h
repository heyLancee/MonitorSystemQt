#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <QString>
#include <QJsonObject>
#include <QMap>

/**
 * @class ConfigManager
 * @brief 统一管理所有配置文件的单例类
 */
class ConfigManager {
public:
    static ConfigManager& getInstance();
    bool init(const QString& mainConfigPath);
    QJsonObject getConfig(const QString& module);

private:
    ConfigManager() = default;
    ~ConfigManager() = default;
    
    QJsonObject mainConfig;
    QMap<QString, QJsonObject> configCache;
    
    bool loadJsonFile(const QString& path, QJsonObject& output);

public:
    QJsonObject baseConfig;
    QJsonObject commConfig;
};


#define theConfigManager ConfigManager::getInstance()
#define theBaseConfig theConfigManager.baseConfig
#define theCommuConfig theConfigManager.commConfig

#endif // CONFIG_MANAGER_H
