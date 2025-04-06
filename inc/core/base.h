#ifndef BASE_H
#define BASE_H

#include <QtCore>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

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
        if (data.size() != 25 * sizeof(double)) {
            return false;
        }

        const double* values = reinterpret_cast<const double*>(data.constData());
        timeStep = values[0];
        wx = values[1]; wy = values[2]; wz = values[3];
        q0 = values[4]; q1 = values[5]; q2 = values[6]; q3 = values[7];
        rx = values[8]; ry = values[9]; rz = values[10];
        vx = values[11]; vy = values[12]; vz = values[13];
        wboX = values[14]; wboY = values[15]; wboZ = values[16];
        qbo0 = values[17]; qbo1 = values[18]; qbo2 = values[19]; qbo3 = values[20];
        tx = values[21]; ty = values[22]; tz = values[23];
        zAngle = values[24];

        return true;
    }

    QByteArray toByteArray() const {
        QByteArray data;
        data.resize(25 * sizeof(double));
        double* values = reinterpret_cast<double*>(data.data());

        values[0] = timeStep;
        values[1] = wx; values[2] = wy; values[3] = wz;
        values[4] = q0; values[5] = q1; values[6] = q2; values[7] = q3;
        values[8] = rx; values[9] = ry; values[10] = rz;
        values[11] = vx; values[12] = vy; values[13] = vz;
        values[14] = wboX; values[15] = wboY; values[16] = wboZ;
        values[17] = qbo0; values[18] = qbo1; values[19] = qbo2; values[20] = qbo3;
        values[21] = tx; values[22] = ty; values[23] = tz;
        values[24] = zAngle;

        return data;
    }

} TelemetryStruct;

Q_DECLARE_METATYPE(TelemetryStruct)

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
} FaultResultStruct;

Q_DECLARE_METATYPE(FaultResultStruct)

enum class FaultType : uint8_t {
    NO_FAULT = 0,
    GYRO_INTERMITTENT_FAULT = 1,
    GYRO_SLOW_FAULT = 2,
    GYRO_MULTI_FAULT = 3,
    FLYWHEEL_PARTIAL_LOSS = 4,
    FLYWHEEL_BIAS = 5,
    FLYWHEEL_COMPREHENSIVE = 6
};

struct FaultParams {
    std::vector<double> params;
    
    // Fault parameters
    double f1 = 0.0;          // Intermittent fault coefficient
    double lambda_s = 0.0;     // Slow variation coefficient
    double k_s = 0.0;          // Slow variation exponent
    double lambda_m = 0.0;     // Multiplicative coefficient
    double e = 0.0;            // Partial failure coefficient
    double b = 0.0;            // Bias coefficient

    static size_t getExpectedParamCount(FaultType type) {
        static const std::map<FaultType, size_t> PARAM_COUNTS = {
            {FaultType::NO_FAULT, 1},
            {FaultType::GYRO_INTERMITTENT_FAULT, 1},
            {FaultType::GYRO_SLOW_FAULT, 2},
            {FaultType::GYRO_MULTI_FAULT, 1},
            {FaultType::FLYWHEEL_PARTIAL_LOSS, 1},
            {FaultType::FLYWHEEL_BIAS, 1},
            {FaultType::FLYWHEEL_COMPREHENSIVE, 2}
        };
        return PARAM_COUNTS.at(type);
    }

    void validateAndAssignParams(FaultType type) {
        size_t expected_count = getExpectedParamCount(type);
        if (params.size() != expected_count) {
            throw std::runtime_error("Parameter count mismatch for fault type");
        }

        switch (type) {
            case FaultType::GYRO_INTERMITTENT_FAULT:
                f1 = params[0];
                break;
            case FaultType::GYRO_SLOW_FAULT:
                lambda_s = params[0];
                k_s = params[1];
                break;
            case FaultType::GYRO_MULTI_FAULT:
                lambda_m = params[0];
                break;
            case FaultType::FLYWHEEL_PARTIAL_LOSS:
                e = params[0];
                break;
            case FaultType::FLYWHEEL_BIAS:
                b = params[0];
                break;
            case FaultType::FLYWHEEL_COMPREHENSIVE:
                e = params[0];
                b = params[1];
                break;
            case FaultType::NO_FAULT:
            default:
                break;
        }
    }

    QByteArray toByteArray() const {
        QByteArray data;
        data.resize(params.size() * sizeof(double));
        double* values = reinterpret_cast<double*>(data.data());
        for (size_t i = 0; i < params.size(); ++i) {
            values[i] = params[i];
        }
        return data;
    }

    static FaultParams fromByteArray(const QByteArray& data, FaultType type) {
        size_t num_params = getExpectedParamCount(type);
        if (data.size() != num_params * sizeof(double)) {
            throw std::runtime_error("Invalid data length for fault type");
        }

        const double* values = reinterpret_cast<const double*>(data.constData());
        FaultParams result;
        result.params.assign(values, values + num_params);
        result.validateAndAssignParams(type);
        return result;
    }
};
Q_DECLARE_METATYPE(FaultParams)

struct FaultDataStruct {
    float faultStartTime;
    float faultEndTime;
    FaultType faultType;
    FaultParams faultParams;

    QByteArray toByteArray() const {
        QByteArray data;
        data.resize(2 * sizeof(float) + sizeof(uint32_t));
        float* floatData = reinterpret_cast<float*>(data.data());
        uint32_t* intData = reinterpret_cast<uint32_t*>(floatData + 2);
        
        floatData[0] = faultStartTime;
        floatData[1] = faultEndTime;
        *intData = static_cast<uint32_t>(faultType);
        
        data.append(faultParams.toByteArray());
        return data;
    }

    static FaultDataStruct fromByteArray(const QByteArray& data) {
        if (data.size() < 12) {  // 2 floats + 1 int
            throw std::runtime_error("Data too short");
        }

        const float* floatData = reinterpret_cast<const float*>(data.constData());
        const uint32_t* intData = reinterpret_cast<const uint32_t*>(floatData + 2);
        
        FaultDataStruct result;
        result.faultStartTime = floatData[0];
        result.faultEndTime = floatData[1];
        result.faultType = static_cast<FaultType>(*intData);
        
        QByteArray paramsData = data.mid(12);
        result.faultParams = FaultParams::fromByteArray(paramsData, result.faultType);
        
        return result;
    }
};
Q_DECLARE_METATYPE(FaultDataStruct)

enum class CommuDataType : uint32_t {
    TELEMETRY = 1,
    FAULT_RESULT = 2,
    FAULT_PARA = 3
};

class PackageManager {
public:
    static PackageManager& getInstance() {
        static PackageManager instance;
        return instance;
    }
    
    void setPackageParams(const QByteArray& header, const QByteArray& tail) {
        this->header = header;
        this->tail = tail;
    }
    
    QByteArray package(const QByteArray& data, CommuDataType commuType) const {
        QByteArray package;
        package.append(header);
        
        uint32_t typeValue = static_cast<uint32_t>(commuType);
        package.append(reinterpret_cast<const char*>(&typeValue), sizeof(uint32_t));
        
        package.append(data);
        package.append(tail);
        return package;
    }
    
    QByteArray unpackage(const QByteArray& package, CommuDataType& commuType) const {
        if (!validatePackage(package)) {
            return QByteArray();
        }
        
        // Calculate positions
        int typeStart = header.size();
        int dataStart = typeStart + sizeof(uint32_t);
        int dataEnd = package.size() - tail.size();
        
        // Extract type
        uint32_t typeValue = *reinterpret_cast<const uint32_t*>(package.constData() + typeStart);
        commuType = static_cast<CommuDataType>(typeValue);
        
        // Extract data
        QByteArray data = package.mid(dataStart, dataEnd - dataStart);
        
        return data;
    }

private:
    bool validatePackage(const QByteArray& package) const {
        // Minimum length: header + type (uint32_t) + tail
        if (package.size() < header.size() + sizeof(uint32_t) + tail.size()) {
            return false;
        }
        
        // Check header and tail
        if (!package.startsWith(header) || !package.endsWith(tail)) {
            return false;
        }
        
        return true;
    }

    PackageManager() = default;
    ~PackageManager() = default;
    PackageManager(const PackageManager&) = delete;
    PackageManager& operator=(const PackageManager&) = delete;
    
    QByteArray header;
    QByteArray tail;
};

#define thePackageManager PackageManager::getInstance()

#endif // BASE_H
