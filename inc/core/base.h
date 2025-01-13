#ifndef BASE_H
#define BASE_H

#include <QMainWindow>
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

} telemetryStruct;

Q_DECLARE_METATYPE(telemetryStruct)

typedef struct{
    float timeStep;
    float faultValue;
    int faultType;
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
} faultParaStruct;

typedef struct {
    bool gyroIsChecked;
    bool starIsChecked;
    bool sunIsChecked;
    bool rwIsChecked;
    QString path;

    QByteArray toByteArray() const {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);
        
        stream << gyroIsChecked << starIsChecked
               << sunIsChecked << rwIsChecked
               << path;
        
        return data;
    }
} saveDataStruct;

// enmu 表示数据类型
enum CommuDataType {
    telemetryType = 0,
    faultResultType = 1,
    runPlatformType = 2,
    stopPlatformType = 3,
    faultParaType = 4,
    saveDataType = 5
};

#endif // BASE_H
