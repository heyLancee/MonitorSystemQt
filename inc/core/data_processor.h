#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <QObject>
#include <QByteArray>
#include <QVariant>
#include "base.h"

/**
 * @brief 数据处理类
 */
class DataProcessor : public QObject {
    Q_OBJECT

public:
    explicit DataProcessor(QObject *parent = nullptr);

signals:
    void data_processed_signal(std::shared_ptr<QVariant> unpackedData, CommuDataType dataType);

public slots:
    void processData(std::shared_ptr<QByteArray> datagram);
};

#endif // DATA_PROCESSOR_H 