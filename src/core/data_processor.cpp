#include "data_processor.h"
#include <QDebug>
#include <QVariant>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

void DataProcessor::processData(std::shared_ptr<QByteArray> datagram, const QByteArray& frameHeadArray, const QByteArray& frameTailArray) {
    if (!datagram->startsWith(frameHeadArray) || !datagram->endsWith(frameTailArray)) {
        qWarning() << "Invalid datagram frame.";
        return;
    }

    // 去掉帧头和帧尾
    datagram->remove(0, frameHeadArray.size());
    datagram->remove(datagram->size() - frameTailArray.size(), frameTailArray.size());

    // 提取类型标识符
    char typeChar = datagram->at(1); // 假设类型标识符在帧头之后
    CommuDataType dataType = static_cast<CommuDataType>(typeChar);

    // 提取不包括类型标识符的数据
    QByteArray data = datagram->mid(1, datagram->size() - 1); // 跳过帧头和类型标识符，去掉帧尾

    std::shared_ptr<QVariant> unpackedDataVariant = std::make_shared<QVariant>();
    switch (dataType) {
        case CommuDataType::telemetryType: {
            telemetryStruct telemetryData;
            if (!telemetryData.fromByteArray(*datagram)) {
                qWarning() << "Failed to unpack telemetry data.";
                return;
            }
            *unpackedDataVariant = QVariant::fromValue(telemetryData);
            break;
        }
        // 处理其他数据类型
        default:
            qWarning() << "Unknown data type.";
            return;
    }
    emit data_processed_signal(unpackedDataVariant, dataType);
} 