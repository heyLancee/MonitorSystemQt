#include "data_processor.h"
#include <QDebug>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent) {}

void DataProcessor::processData(std::shared_ptr<QByteArray> datagram, const QString& frameHead, const QString& frameTail) {
    if (!datagram->startsWith(frameHead) || !datagram->endsWith(frameTail)) {
        qWarning() << "Invalid datagram frame.";
        return;
    }

    // 去掉帧头和帧尾
    datagram->remove(0, frameHead.size());
    datagram->remove(datagram->size() - frameTail.size(), frameTail.size());

    // 提取类型标识符
    char typeChar = datagram->at(1); // 假设类型标识符在帧头之后
    CommuDataType dataType = static_cast<CommuDataType>(typeChar);

    // 提取不包括类型标识符的数据
    QByteArray data = datagram->mid(1, datagram->size() - 1); // 跳过帧头和类型标识符，去掉帧尾

    void* unpackedData = nullptr;
    switch (dataType) {
        case CommuDataType::telemetryType: {
            telemetryStruct *telemetryData = new telemetryStruct();
            if (!telemetryData->fromByteArray(data)) {
                qWarning() << "Failed to unpack telemetry data.";
                return;
            }
            unpackedData = telemetryData;
            break;
        }
        // 处理其他数据类型
        default:
            qWarning() << "Unknown data type.";
            return;
    }
    emit data_processed_signal(std::shared_ptr<void>(unpackedData), dataType);
} 