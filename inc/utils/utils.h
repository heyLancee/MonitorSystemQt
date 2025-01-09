#ifndef UTILS_H
#define UTILS_H

#include <QMainWindow>
#include <QtCharts>
#include "base.h"

class Plot
{
public:
    Plot(QChartView* chartView, const QColor& color = Qt::red, Qt::PenStyle style = Qt::SolidLine, 
        const QString& title = "", const QString& axisXLabel = "", const QString& axisYLabel = "", 
        double minX = 0, double maxX = 100, double minY = 0, double maxY = 100, bool legendShow = false);
    QChart* chart;
    QLineSeries* series;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QPen pen;

public:
    void refreshYAxis(QList<QPointF> VList, float& minValue, float& maxValue);
    void updateDataList(QList<QPointF>& dataList, QValueAxis &axisX, QValueAxis &axisY, float xValue, float yValue,
                        float xCurrMinRange=-1, float xCurrMaxRange=-1, float yCurrMinRange=-1, float yCurrMaxRange=-1);

private:
    unsigned int telemetryCount;

}

bool readCsv(QString filePath, QList<QStringList>& data);
bool writeCsv(QString filePath, QList<QStringList>& data);



#endif // UTILS_H
