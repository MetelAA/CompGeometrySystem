#include "starpolygon.h"
#include <QRandomGenerator>


#define PI 3.14159265
StarPolygon::StarPolygon(int pCount, int width, int height) : ConvexPolygon(pCount, width, height) {
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
    int x, y, itRad;
    QPointF scenePos = this->pos();
    for(int i = 0; i < pCount; i++){
        itRad = radius * (fmod(QRandomGenerator::global()->generateDouble(), 0.7) + 0.3);
        x = scenePos.x() + itRad * std::cos(angles[i]);
        y = scenePos.y() + itRad * std::sin(angles[i]);
        points.push_back(CPoint(x, y));
    }

    this->points = points;
}
