#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <QGraphicsItem>
#include "src/shells/randompointsset.h"
#include <QPainter>

class ConvexHull : public QGraphicsItem {
public:
    ConvexHull(RandomPointsSet* pSet, QGraphicsItem* parent = nullptr);

protected:
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;
    QRectF boundingRect() const override;

    std::vector<CPoint> convexShellPoints;
    std::vector<CPoint> pSetPoints;

};

#endif // CONVEXHULL_H
