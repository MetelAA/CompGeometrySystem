#include "simplepolygon.h"
#include <algorithm>
#include <QRandomGenerator>

SimplePolygon::SimplePolygon(int pCount, int width, int height, QGraphicsItem *parent): QGraphicsItem(parent)
{
    for(int i = 0; i < pCount; i++){
        qreal x = QRandomGenerator::global()->generateDouble() * (width/2);
        qreal y = QRandomGenerator::global()->generateDouble() * (height/2);
        this->points.push_back(CPoint(x, y));
    }

    CPoint pivot = points[0];

    std::sort(points.begin(), points.end(),
              [pivot](const CPoint& a, const CPoint& b) {

                  // Исключаем саму опорную точку
                  if (a == pivot) return true;
                  if (b == pivot) return false;

                  // Векторы от опорной точки (могут иметь отрицательные компоненты)
                  CPoint vecA = a - pivot;
                  CPoint vecB = b - pivot;

                  // Вычисляем углы через atan2 (работает с отрицательными координатами)
                  double angleA = atan2(vecA.y(), vecA.x());
                  double angleB = atan2(vecB.y(), vecB.x());

                  return angleA < angleB;
              });
}

void SimplePolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    for(const CPoint& point : this->points){
        polygon << point;
    }

    painter->drawPolygon(polygon);
}

QRectF SimplePolygon::boundingRect() const
{
    qreal minX = points[0].x();
    qreal maxX = points[0].x();
    qreal minY = points[0].y();
    qreal maxY = points[0].y();

    for (const CPoint& point : points) {
        minX = std::min(minX, point.x());
        maxX = std::max(maxX, point.x());
        minY = std::min(minY, point.y());
        maxY = std::max(maxY, point.y());
    }

    const qreal padding = 2.0; // Отступ для пера
    return QRectF(minX - padding, minY - padding,
                            maxX - minX + 2 * padding,
                            maxY - minY + 2 * padding);
}
