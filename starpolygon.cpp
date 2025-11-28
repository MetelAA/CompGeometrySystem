#include "starpolygon.h"
#include <algorithm>
#include <QRandomGenerator>
#include "GenerationType.h"
#include <QDebug>

StarPolygon::StarPolygon(int pCount, int width, int height, QGraphicsItem *parent): CustomPolygon(GenerationType::StarPolygon, parent)
{
    width = ceil(width * 0.85);
    height = ceil(height * 0.85);

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


    // for(const CPoint& p : points){
    //     qDebug() << "pCoords x\\y: " << p.x() << "\\" << p.y() << "\n";
    // }
}

bool StarPolygon::point_in_polygon(const CPoint& z){
    size_t intersections = 0;
    for (size_t i = 0, j = this->points.size() - 1; i < this->points.size(); j = i, i++) {
        CPoint b = this->points.at(i);
        CPoint t = this->points.at(j);

        if (b.y() > t.y()) {
            std::swap(b, t);
        }

        if (b.y() < z.y() && t.y() >= z.y() && CPoint::orientation(b, t, z) == CPoint::OrientationTypes::right) {
            intersections++;
        }
    }


    return intersections % 2 == 1;
    // return intersections > 0;
}


void StarPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    for(const CPoint& point : this->points){
        polygon << point;
    }

    painter->drawPolygon(polygon);
}

QRectF StarPolygon::boundingRect() const
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

    const qreal padding = 0.5; // Отступ для пера
    return QRectF(minX - padding, minY - padding,
                            maxX - minX + 2 * padding,
                            maxY - minY + 2 * padding);
}
