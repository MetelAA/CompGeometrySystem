#ifndef STARPOLYGON_H
#define STARPOLYGON_H

#include<QPainter>
#include "src/cpoint.h"
#include <vector>
#include "custompolygon.h"

class StarPolygon : public CustomPolygon
{
public:
    StarPolygon(int pCount, int width, int height, QGraphicsItem* parent = nullptr);
    bool point_in_polygon(const CPoint& z) override;
protected:
    std::vector<CPoint> points;
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // STARPOLYGON_H
