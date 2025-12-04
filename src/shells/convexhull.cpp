#include "convexhull.h"
#include "src/points/cpoint.h"
#include <QDebug>

ConvexHull::ConvexHull(RandomPointsSet* pSet, QGraphicsItem* parent) : QGraphicsItem(parent) {
    CPoint pivot = (*pSet).getPoints()[0];

    std::vector<CPoint> a = (*pSet).getPoints();

    for(const CPoint& p : (*pSet).getPoints()){
        if(p.y() < pivot.y() || (p.y() - pivot.y() <= 1e-9 && p.x() < pivot.x())){
            pivot = p;
        }
    }

    sort(a.begin(), a.end(), [&pivot](const CPoint& a, const CPoint& b) {
        CPoint::OrientationTypes type = CPoint::orientation(pivot, a, b);

        if (type == CPoint::OrientationTypes::collinear) {
            qreal ab = sqrt(pow(a.x() - pivot.x(), 2) + pow(a.y() - pivot.y(), 2));
            qreal ac = sqrt(pow(b.x() - pivot.x(), 2) + pow(b.y() - pivot.y(), 2));
            return (ac < ab);
        }

        return CPoint::OrientationTypes::left == type;
    });

    qDebug() << "pivot x/y" << pivot.x() << "/" << pivot.y();

    qDebug() << "pSet size " << a.size();

    for(int i = 0; i < a.size(); i++){
        qDebug() << "x/y" << a[i].x() << "/" << a[i].y();
    }

    std::vector<CPoint> hull;

    for(int i = 0; i < a.size(); i++){
        while(hull.size() > 1 && CPoint::orientation(hull[hull.size()-2], hull[hull.size()-1], a[i]) == CPoint::OrientationTypes::right){
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }

    qDebug() << "hull size " << hull.size();

    for(int i = 0; i < hull.size(); i++) {
        qDebug() << "x/y" << hull[i].x() << "/" << hull[i].y();
    }

    this->convexShellPoints = hull;
    this->pSetPoints = a;
}

void ConvexHull::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPolygonF polygon;
    for(const CPoint& point : this->convexShellPoints){
        polygon << point;
    }
    painter->drawPolygon(polygon);

    painter->setPen(QPen(Qt::red, 5));

    QFont font = painter->font();
    font.setPointSize(8);
    painter->setFont(font);

    for(int i = 0; i < this->pSetPoints.size(); i++){
        const CPoint& point = this->pSetPoints[i];
        painter->drawPoint(point);
    }
    if(this->pSetPoints.size() < 30){
        for(int i = 0; i < this->pSetPoints.size(); i++){
            const CPoint& point = this->pSetPoints[i];
            QString coordText = QString("(%1, %2), %3").arg(point.x()).arg(point.y()).arg(i);
            painter->drawText(QPointF(point.x() + 5, point.y() - 5), coordText);
        }
    }
}

QRectF ConvexHull::boundingRect() const
{
    qreal minX = this->pSetPoints[0].x();
    qreal maxX = this->pSetPoints[0].x();
    qreal minY = this->pSetPoints[0].y();
    qreal maxY = this->pSetPoints[0].y();

    for (const CPoint& point : this->pSetPoints) {
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
