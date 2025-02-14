#ifndef BASE_H
#define BASE_H

#include <QtCore>
#include <string>

typedef struct
{
    float timeStep;
    float wx, wy, wz;
    
    float q0, q1, q2, q3;
    float rx, ry, rz;
    float vx, vy, vz;
    float wboX, wboY, wboZ;
    float qbo0, qbo1, qbo2, qbo3;
    float tx, ty, tz;
    float zAngle;

    bool fromByteArray(const QByteArray& data) {
        if (data.isEmpty()) {
            return false;
        }

        QDataStream stream(data);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream >> timeStep
               >> wx >> wy >> wz
               >> q0 >> q1 >> q2 >> q3
               >> rx >> ry >> rz
               >> vx >> vy >> vz
               >> wboX >> wboY >> wboZ
               >> qbo0 >> qbo1 >> qbo2 >> qbo3
               >> tx >> ty >> tz
               >> zAngle;

        return stream.status() == QDataStream::Ok;
    }

    QByteArray toByteArray() const {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream << timeStep
               << wx << wy << wz
               << q0 << q1 << q2 << q3
               << rx << ry << rz
               << vx << vy << vz
               << wboX << wboY << wboZ
               << qbo0 << qbo1 << qbo2 << qbo3
               << tx << ty << tz
               << zAngle;

        return data;
    }

} telemetryStruct;

Q_DECLARE_METATYPE(telemetryStruct)

typedef struct{
    float timeStep;
    float faultValue;
    int faultType;

    QByteArray toByteArray() const {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream << timeStep
               << faultValue
               << faultType;

        return data;
    }

    bool fromByteArray(const QByteArray& data) {
        if (data.isEmpty()) {
            return false;
        }

        QDataStream stream(data);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream >> timeStep
               >> faultValue
               >> faultType;
               
        return stream.status() == QDataStream::Ok;
    }
} faultResultStruct;

Q_DECLARE_METATYPE(faultResultStruct)

typedef struct{
    float faultTimeLow;
    float faultAttLow;
    float faultTimeUp;
    float faultAttUp;
    int faultType;

    int gyroGroup;
    int gyroID;

    int runMode;

    QByteArray toByteArray() const {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);
        
        stream << faultTimeLow << faultTimeUp
               << faultAttLow << faultAttUp
               << faultType
               << gyroGroup << gyroID
               << runMode;
        
        return data;
    }

    bool fromByteArray(const QByteArray& data) {
        if (data.isEmpty()) {
            return false;
        }

        QDataStream stream(data);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream >> faultTimeLow >> faultTimeUp
               >> faultAttLow >> faultAttUp
               >> faultType
               >> gyroGroup >> gyroID
               >> runMode;
               
        return stream.status() == QDataStream::Ok;
    }
} faultParaStruct;

enum CommuDataType : uint8_t {
    telemetryType = 0,
    faultResultType = 1,
    faultParaType = 2,
};

class PackageManager {
public:
    static PackageManager& getInstance() {
        static PackageManager instance;
        return instance;
    }
    
    void setPackageParams(const std::string& header, const std::string& tail) {
        this->header = header;
        this->tail = tail;
    }
    
    std::string package(const std::string& data, CommuDataType identifier) const {
        std::string package;
        package.append(this->header);
        package.push_back(static_cast<char>(identifier));
        package.append(data);
        package.append(this->tail);
        return package;
    }
    
    std::string unpackage(const std::string& package, CommuDataType& dataType) const {
        if (!validatePackage(package, dataType)) {
            return std::string();
        }
        
        // 计算数据部分的起始和结束位置
        size_t dataStart = this->header.length() + 1;  // 帧头长度 + 标识符长度
        size_t dataEnd = package.length() - this->tail.length();
        
        // 提取数据部分
        return package.substr(dataStart, dataEnd - dataStart);
    }

private:
    bool validatePackage(const std::string& package, CommuDataType& dataType) const {
        // 检查包长度是否合理
        size_t minLength = this->header.length() + 1 + this->tail.length();
        if (package.length() < minLength) {
            return false;
        }
        
        // 验证帧头和帧尾
        if (package.substr(0, header.length()) != header || 
            package.substr(package.length() - tail.length()) != tail) {
            return false;
        }
        
        // 提取类型标识符
        dataType = static_cast<CommuDataType>(package[this->header.length()]); 
        
        return true;
    }

private:
    PackageManager() = default;
    ~PackageManager() = default;
    PackageManager(const PackageManager&) = delete;
    PackageManager& operator=(const PackageManager&) = delete;
    
    std::string header;
    std::string tail;
};

#define thePackageManager PackageManager::getInstance()

#endif // BASE_H
