#ifndef CUSTOMPOLYGON_H
#define CUSTOMPOLYGON_H

#include <QGraphicsItem>
#include "GenerationType.h"

class CPoint;

class CustomPolygon : public QGraphicsItem
{
public:
    CustomPolygon(GenerationType type, QGraphicsItem* parent = nullptr) : type(type), QGraphicsItem(parent){}
    GenerationType type;
    virtual bool point_in_polygon(const CPoint& z) = 0;
};

#endif // CUSTOMPOLYGON_H
