#include "simplepolygon.h"
#include <algorithm>
#include <QRandomGenerator>
#include "GenerationType.h"
#include <QDebug>

SimplePolygon::SimplePolygon(int pCount, int width, int height, QGraphicsItem *parent): CustomPolygon(GenerationType::SimplePolygon, parent)
{

    std::vector<CPoint> points;

    // Генерация точек
    for(int i = 0; i < pCount; i++){
        qreal x = (QRandomGenerator::global()->generateDouble() - 0.5) * width;
        qreal y = (QRandomGenerator::global()->generateDouble() - 0.5) * height;
        points.push_back(CPoint(x, y));
    }

    // Находим центр МАСС (не геометрический центр!)
    CPoint center(0, 0);
    for (const CPoint& p : points) {
        center += p;
    }
    center /= points.size();

    // Сортируем относительно центра
    std::sort(points.begin(), points.end(),
              [center](const CPoint& a, const CPoint& b) {
                  return atan2(a.y() - center.y(), a.x() - center.x()) <
                         atan2(b.y() - center.y(), b.x() - center.x());
              });

    this->points = points;


    QPointF scenePos = this->pos();
    for(const CPoint& p : points){
        qreal localX = p.x();
        qreal localY = p.y();
        qreal sceneX = localX + scenePos.x();
        qreal sceneY = localY + scenePos.y();

        qDebug() <<  "x/y: (" << sceneX << ", " << sceneY << "\n";
    }
}

bool SimplePolygon::point_in_polygon(const CPoint& z){
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
}


void SimplePolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    for(const CPoint& point : this->points){
        polygon << point;
    }
    painter->drawPolygon(polygon);

    painter->setPen(QPen(Qt::red, 5));

    QFont font = painter->font();
    font.setPointSize(8);
    painter->setFont(font);

    for(int i = 0; i < this->points.size(); i++){
        const CPoint& point = this->points[i];
        painter->drawPoint(point);
    }
    if(this->points.size() < 30){
        for(int i = 0; i < this->points.size(); i++){
            const CPoint& point = this->points[i];
            QString coordText = QString("(%1, %2), %3").arg(point.x()).arg(point.y()).arg(i);
            painter->drawText(QPointF(point.x() + 5, point.y() - 5), coordText);
        }
    }
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

    const qreal padding = 0.5; // Отступ для пера
    return QRectF(minX - padding, minY - padding,
                            maxX - minX + 2 * padding,
                            maxY - minY + 2 * padding);
}
