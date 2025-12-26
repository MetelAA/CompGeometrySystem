#ifndef CUSTOMPOLYGON_H
#define CUSTOMPOLYGON_H

#include <QPainter>
#include <QGraphicsItem>
#include "GenerationType.h"
#include "src/points/cpoint.h"

class CPoint;

class CustomPolygon : public QGraphicsItem
{
public:
    CustomPolygon(GenerationType type, QGraphicsItem* parent = nullptr);
    GenerationType type;
    virtual bool point_in_polygon(const CPoint& z) = 0;
    std::vector<CPoint>& getPoints();  // Только объявление, без реализации
protected:
    std::vector<CPoint> points;
};

#endif // CUSTOMPOLYGON_H
