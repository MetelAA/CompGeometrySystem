#include "customgraphicsview.h"
#include "src/points/cpoint.h"
#include "interface/graphicalinterface.h"


CustomGraphicsView::CustomGraphicsView(int width, int height, GraphicalInterface* callback, QWidget *parent) : QGraphicsView(parent), width(width), height(height), callback(callback)
{
    setMouseTracking(true);
    viewport()->setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);

    setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    // Устанавливаем AnchorUnderMouse по умолчанию
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // Включаем режим перетаскивания для перемещения
    setDragMode(QGraphicsView::ScrollHandDrag);

    setSceneRect(QRectF((-1) * this->width, (-1) * this->height, (2) * this->width, (2) * this->height));
    // setSceneRect(QRectF(0, 0, (1) * this->width, (1) * this->height));
    setMinimumSize(this->width, this->height);
}

void CustomGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        double angle = event->angleDelta().y();
        double factor = (angle > 0) ? 1.1 : 0.9;
        scale(factor, factor);
    }
    event->accept();
}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    CPoint point(scenePos.x(), scenePos.y());
    this->callback->callback(point);
    QGraphicsView::mouseMoveEvent(event);
}
