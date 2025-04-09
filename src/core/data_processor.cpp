#include "data_processor.h"
#include <QDebug>
#include <QVariant>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

void DataProcessor::processData(std::shared_ptr<QByteArray> datagram) {
    CommuDataType dataType;
    QByteArray data;

    data = thePackageManager.unpackage(*datagram, dataType);

    if (data.isEmpty()) {
        qWarning() << "Unpackage failed.";
        return;
    }

    std::shared_ptr<QVariant> unpackedDataVariant = std::make_shared<QVariant>();
    switch (dataType) {
        case CommuDataType::TELEMETRY: {
            TelemetryStruct telemetryData;
            if (!telemetryData.fromByteArray(data)) {
                qWarning() << "Failed to unpack telemetry data.";
                return;
            }
            *unpackedDataVariant = QVariant::fromValue(telemetryData);
            break;
        }
        case CommuDataType::FAULT_RESULT: {
            FaultResultStruct faultResultData;
            if (!faultResultData.fromByteArray(data)) {
                qWarning() << "Failed to unpack fault result data.";
                return;
            }
            *unpackedDataVariant = QVariant::fromValue(faultResultData);
            break;
        }
        // 处理其他数据类型
        default:
            qWarning() << "Unknown data type.";
            return;
    }
    
    emit data_processed_signal(unpackedDataVariant, dataType);
}
