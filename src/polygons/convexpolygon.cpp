#include "convexpolygon.h"
#include "GenerationType.h"
#include <QRandomGenerator>

#include<chrono>
#include<thread>

#define PI 3.14159265

ConvexPolygon::ConvexPolygon(int pCount, int width, int height, QGraphicsItem* parent)
    : CustomPolygon(GenerationType::ConvexPolygon, parent)
{
    int radius = std::min(width, height);
    double randomFactor = 0.5 + fmod(QRandomGenerator::global()->generateDouble(), 0.4);
    radius = static_cast<int>(ceil(radius * randomFactor * 0.6));


    std::vector<qreal> angles;
    for(int i = 0; i < pCount; i++){
        angles.push_back((QRandomGenerator::global()->generateDouble() * 2) * PI);
    }


    std::sort(angles.begin(), angles.end(),
              [](const qreal& a, const qreal& b) {
                    return a < b;
              });

    std::vector<CPoint> points;
    int x, y;
    QPointF scenePos = this->pos();
    for(int i = 0; i < pCount; i++){
        x = scenePos.x() + radius * std::cos(angles[i]);
        y = scenePos.y() + radius * std::sin(angles[i]);
        points.push_back(CPoint(x, y));
    }

    this->points = points;
    this->radius = radius;
}

bool ConvexPolygon::point_in_polygon(const CPoint &z)
{

    // qDebug() << "pointZ x/y" << z.x() << "/" << z.y();

    // std::this_thread::sleep_for(std::chrono::milliseconds(500));


    CPoint q(0, 0);
    for(const CPoint& p : this->points) {
        q.setX(q.x() + p.x());
        q.setY(q.y() + p.y());
    }
    q.setX(q.x() / this->points.size());
    q.setY(q.y() / this->points.size());


    int l = 0, r = this->points.size();
    CPoint ps = this->points[l];
    CPoint pm = this->points[(l+r) / 2];

    while(r - l > 1) {
        int mid = (l + r) / 2;
        CPoint ps = this->points[l];
        CPoint pm = this->points[mid];

        if(CPoint::orientation(q, ps, pm) == CPoint::OrientationTypes::left) {
            if(CPoint::orientation(q, ps, z) != CPoint::OrientationTypes::right &&
                CPoint::orientation(q, pm, z) == CPoint::OrientationTypes::right) {
                r = mid;
            } else {
                l = mid;
            }
        } else {
            if(CPoint::orientation(q, ps, z) == CPoint::OrientationTypes::right &&
                CPoint::orientation(q, pm, z) != CPoint::OrientationTypes::right) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }

    int i = l % this->points.size();
    int j = r % this->points.size();
    // qDebug() << "your point is between the " << this->points[l].x() << "\\" << this->points[l].y() << " and the " << this->points[r].x() << "\\" << this->points[r].y();
    return CPoint::orientation(this->points[i], this->points[j], z) == CPoint::OrientationTypes::left;
}

void ConvexPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF ConvexPolygon::boundingRect() const
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
