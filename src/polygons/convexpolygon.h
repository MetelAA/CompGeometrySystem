#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "src/polygons/custompolygon.h"

class ConvexPolygon : public CustomPolygon{
public:
    ConvexPolygon(int pCount, int width, int height, QGraphicsItem* parent = nullptr);


    bool point_in_polygon(const CPoint& z) override;
protected:
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
    int radius;

};

#endif // CONVEXPOLYGON_H
