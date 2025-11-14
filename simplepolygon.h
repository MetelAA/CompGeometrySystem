#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H

#include <QGraphicsItem>
#include<QPainter>
#include "src/cpoint.h"
#include <vector>

class SimplePolygon : public QGraphicsItem
{
public:
    explicit SimplePolygon(int pCount, int width, int height, QGraphicsItem* parent = nullptr);

protected:
    std::vector<CPoint> points;
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // SIMPLEPOLYGON_H
