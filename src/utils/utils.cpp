#include "utils.h"
#include "config_manager.h"

// 构造函数
Plot::Plot(QChartView* chartView, const QColor& color, Qt::PenStyle style, const QString& title, 
            const QString& axisXLabel, const QString& axisYLabel, double minX, double maxX, double minY, double maxY, 
            bool legendShow) 
{
    // 初始化图表和系列
    this->chart = new QChart();
    this->series = new QLineSeries();
    this->chart->addSeries(this->series);
    this->chart->setTitle(title);

    // 初始化X轴
    this->axisX = new QValueAxis();
    this->axisX->setTitleText(axisXLabel);
    this->axisX->setRange(minX, maxX);
    this->chart->addAxis(this->axisX, Qt::AlignBottom);
    this->series->attachAxis(this->axisX);

    // 初始化Y轴
    this->axisY = new QValueAxis();
    this->axisY->setTitleText(axisYLabel);
    this->axisY->setRange(minY, maxY);
    this->chart->addAxis(this->axisY, Qt::AlignLeft);
    this->series->attachAxis(this->axisY);

    // 设置画笔
    this->pen.setColor(color);
    this->pen.setStyle(style);
    this->series->setPen(this->pen);

    // 显示图例
    if (legendShow) {
        this->chart->legend()->show();
        this->chart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
    }

    // 设置图表到QChartView
    chartView->setChart(this->chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->telemetryCount = 0;
}

/**
 * @brief 刷新X轴和Y轴的最小值和最大值
 * 
 * @param dataList 数据点列表
 * @param axisX X轴指针
 * @param axisY Y轴指针
 * @param xCurrMinRange 当前X最小范围
 * @param xCurrMaxRange 当前X最大范围
 * @param yCurrMinRange 当前Y最小范围
 * @param yCurrMaxRange 当前Y最大范围
 */
void Plot::refreshAxes(QList<QPointF> dataList, QValueAxis *axisX, QValueAxis *axisY,
                       float xCurrMinRange, float xCurrMaxRange, float yCurrMinRange, float yCurrMaxRange)
{
    if (dataList.isEmpty()) return;

    // 更新X轴坐标
    float x_min = dataList.first().x();
    if (xCurrMinRange != -1)
        x_min = qMin(x_min, xCurrMinRange);
    float x_max = qMax(dataList.last().x(), static_cast<float>(theBaseConfig.draw_time_max));
    if (xCurrMaxRange != -1)
        x_max = qMax(x_max, xCurrMaxRange);

    // 更新Y轴坐标
    float y_min = dataList.first().y();
    float y_max = dataList.first().y();
    for (const auto& point : dataList) {
        y_max = qMax(y_max, static_cast<float>(point.y()));
        y_min = qMin(y_min, static_cast<float>(point.y()));
    }
    y_min -= abs(y_min) * 0.1f;
    y_max += abs(y_max) * 0.1f;

    if (yCurrMinRange != -1)
        y_min = qMin(y_min, yCurrMinRange);
    if (yCurrMaxRange != -1)
        y_max = qMax(y_max, yCurrMaxRange);

    axisX->setRange(x_min, x_max);
    axisY->setRange(y_min, y_max);
}

/**
 * @brief 更新数据列表并刷新坐标轴
 * 
 * @param udpData UDP数据结构
 * @param dataList 数据列表
 * @param axisX X轴指针
 * @param axisY Y轴指针
 * @param yValue Y值
 * @param axisRefreshNum 坐标轴刷新计数
 * @param xCurrMinRange 当前X最小范围
 * @param xCurrMaxRange 当前X最大范围
 * @param yCurrMinRange 当前Y最小范围
 * @param yCurrMaxRange 当前Y最大范围
 * @return 更新后的数据列表
 */
void Plot::updateDataList(QList<QPointF>& dataList, QValueAxis &axisX, QValueAxis &axisY, float xValue, float yValue,
                            float xCurrMinRange, float xCurrMaxRange, float yCurrMinRange, float yCurrMaxRange)
{
    if (!dataList.isEmpty() && this->telemetryCount % theBaseConfig.axis_refresh_freq == 0)
    {
        refreshAxes(dataList, axisX, axisY, xCurrMinRange, xCurrMaxRange, yCurrMinRange, yCurrMaxRange);
    }

    dataList.append(QPointF(xValue, yValue));

    while (dataList.last().x() - dataList.first().x() >= theBaseConfig.draw_time_max)
        dataList.removeFirst();

    this->telemetryCount++;
}

/**
 * @brief 读取CSV文件
 * 
 * @param filePath 文件路径
 * @param data 数据列表
 * @return 是否成功读取
 */
bool readCsv(QString filePath, QList<QStringList>& data)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList row = line.split(',', Qt::SkipEmptyParts);
        data.append(row);
    }

    file.close();
    return true;
}

/**
 * @brief 写入CSV文件
 * 
 * @param filePath 文件路径
 * @param data 数据列表
 * @return 是否成功写入
 */
bool writeCsv(QString filePath, QList<QStringList>& data)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    for (const auto& row : data)
    {
        stream << row.join(",") << "\n";
    }

    file.close();
    return true;
}



