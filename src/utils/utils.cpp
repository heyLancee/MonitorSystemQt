#include "utils.h"
#include "config_manager.h"
#include <memory>

// 构造函数
Plot::Plot(QChartView* chartView, const QColor& color, Qt::PenStyle style, const QString& title, 
            const QString& axisXLabel, const QString& axisYLabel, double minX, double maxX, double minY, double maxY, 
            bool legendShow) 
{
    // 使用std::make_unique初始化成员变量
    this->chart = std::unique_ptr<QChart>(new QChart());
    this->series = std::unique_ptr<QLineSeries>(new QLineSeries());
    this->chart->addSeries(this->series.get());
    this->chart->setTitle(title);

    // 初始化X轴
    this->axisX = std::unique_ptr<QValueAxis>(new QValueAxis());
    this->axisX->setTitleText(axisXLabel);
    this->axisX->setRange(minX, maxX);
    this->chart->addAxis(this->axisX.get(), Qt::AlignBottom);
    this->series->attachAxis(this->axisX.get());

    // 初始化Y轴
    this->axisY = std::unique_ptr<QValueAxis>(new QValueAxis());
    this->axisY->setTitleText(axisYLabel);
    this->axisY->setRange(minY, maxY);
    this->chart->addAxis(this->axisY.get(), Qt::AlignLeft);
    this->series->attachAxis(this->axisY.get());

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
    chartView->setChart(this->chart.get());
    chartView->setRenderHint(QPainter::Antialiasing);

    telemetryCount = 0;
}

void Plot::refreshAxes(QValueAxis &axisX, QValueAxis &axisY, float xCurrMinRange, float xCurrMaxRange, float yCurrMinRange, float yCurrMaxRange)
{
    int count = this->series->count();
    if (count == 0) return;

    // 更新X轴坐标
    float x_min = this->series->at(0).x();
    if (xCurrMinRange != -1)
        x_min = qMin(x_min, xCurrMinRange);
        
    float x_max = this->series->at(count - 1).x();
    if (xCurrMaxRange != -1)
        x_max = qMax(x_max, xCurrMaxRange);

    x_min -= abs(x_min) * 0.05f;
    x_max += abs(x_max) * 0.05f;

    // 更新Y轴坐标
    // 使用QLineSeries的at()方法获取第一个点的y值作为初始值
    float y_min = std::numeric_limits<float>::max();
    float y_max = std::numeric_limits<float>::lowest();

    // 使用QLineSeries的points()方法一次性获取所有点
    const QList<QPointF> points = this->series->points();
    for (const QPointF& point : points) {
        float y = static_cast<float>(point.y());
        y_min = qMin(y_min, y);
        y_max = qMax(y_max, y);
    }
    y_min -= abs(y_min) * 0.1f;
    y_max += abs(y_max) * 0.1f;

    if (yCurrMinRange != -1)
        y_min = qMin(y_min, yCurrMinRange);
    if (yCurrMaxRange != -1)
        y_max = qMax(y_max, yCurrMaxRange);

    axisX.setRange(x_min, x_max);
    axisY.setRange(y_min, y_max);
}

void Plot::updateDataList(QValueAxis &axisX, QValueAxis &axisY, float xValue, float yValue,
                            float xCurrMinRange, float xCurrMaxRange, float yCurrMinRange, float yCurrMaxRange)
{
    if (this->telemetryCount % theBaseConfig["axis_refresh_freq"].toInt() == 0)
    {
        refreshAxes(axisX, axisY, xCurrMinRange, xCurrMaxRange, yCurrMinRange, yCurrMaxRange);
    }

    this->series->append(QPointF(xValue, yValue));
    this->telemetryCount++;

    if (this->series->count() < 2) 
    {
        return;
    }

    // 检查并移除超出时间窗口的数据点
    while (this->series->at(this->series->count() - 1).x() - this->series->at(0).x() >= theBaseConfig["max_draw_duration"].toDouble())
    {
        this->series->remove(0);
    }
}

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



