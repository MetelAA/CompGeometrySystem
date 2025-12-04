#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include "src/polygons/simplepolygon.h"

class GraphicalInterface;

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(int width, int height, GraphicalInterface* callback, QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    int width;
    int height;
    GraphicalInterface* callback;
};

#endif // CUSTOMGRAPHICSVIEW_H
