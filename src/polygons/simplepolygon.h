#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H


#include "src/points/cpoint.h"
#include <vector>
#include "custompolygon.h"

class SimplePolygon : public CustomPolygon
{
public:
    SimplePolygon(int pCount, int width, int height, QGraphicsItem* parent = nullptr);
    bool point_in_polygon(const CPoint& z) override;
protected:
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // SIMPLEPOLYGON_H
