#ifndef TRIANGULATIONINTERFACE_H
#define TRIANGULATIONINTERFACE_H

#include <QWidget>
#include <QGraphicsScene>

class CustomGraphicsView;
class CPoint;
class CustomPolygon;

class TriangulationInterface : public QWidget
{
    Q_OBJECT

public:
    TriangulationInterface(int pointsCount, QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;  // Добавляем обработку клавиш
private:
    QGraphicsScene *scene;
    int width = 1300, height = 950;
    int pointsCount;
    CustomPolygon* polygon;
    CustomGraphicsView* customView;
};

#endif // TRIANGULATIONINTERFACE_H
