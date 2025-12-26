#include "custompolygon.h"

CustomPolygon::CustomPolygon(GenerationType type, QGraphicsItem* parent)
    : QGraphicsItem(parent), type(type)
{
}

std::vector<CPoint>& CustomPolygon::getPoints()
{
    return points;
}
