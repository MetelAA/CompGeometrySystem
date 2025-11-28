#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include <QWidget>
#include <QGraphicsScene>
#include "GenerationType.h"

class CustomGraphicsView;
class CPoint;
class CustomPolygon;

class GraphicalInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicalInterface(GenerationType polygonType, int pointsCount, QWidget *parent = nullptr);
    void callback(const CPoint& p);
    ~GraphicalInterface();

private:
    QGraphicsScene *scene;
    int width = 1300, height = 950;
    int pointsCount;
    GenerationType polygonType;
    CustomPolygon* polygon;
    CustomGraphicsView* customView;
    QCursor redCurs, greenCurs;
};

#endif // GRAPHICALINTERFACE_H
