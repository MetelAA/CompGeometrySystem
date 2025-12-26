#include "triangulationinterface.h"
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QPixmap>
#include <QApplication>
#include "customgraphicsview.h"
#include "src/triangulation/triangulationearclipping.h"
#include "src/polygons/convexpolygon.h"
#include "src/polygons/simplepolygon.h".h"

TriangulationInterface::TriangulationInterface(int pointsCount, QWidget *parent) : QWidget(parent)
    , pointsCount(pointsCount)
{
    // Устанавливаем минимальный размер
    setMinimumSize(this->width, this->height);
    // Устанавливаем фокус на виджет, чтобы он получал события клавиатуры
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    // Создаем главный layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // Создаем кастомный view
    this->customView = new CustomGraphicsView(this->width, this->height, nullptr);
    verticalLayout->addWidget(this->customView);

    // Создаем сцену
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, this->width, this->height);
    this->customView->setScene(scene);


    this->polygon = new SimplePolygon(this->pointsCount, this->width, this->height);

    QPolygonF q;
    for(const CPoint& point : this->polygon->getPoints()){
        q << point;
    }
    scene->addPolygon(q);
}

void TriangulationInterface::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {


        scene->clear();  // Очищаем сцену

        QPolygonF q;
        for(const CPoint& point : this->polygon->getPoints()){
            q << point;
        }
        scene->addPolygon(q);

        TriangulationEarClipping clipping;
        std::vector<triangle> triang = clipping.EarClipping(polygon->getPoints());

        // Добавляем треугольники на сцену
        for (const triangle &t : triang) {
            QPolygonF q;
            q << QPointF(t.p1.x(), t.p1.y())
              << QPointF(t.p2.x(), t.p2.y())
              << QPointF(t.p3.x(), t.p3.y());


            scene->addPolygon(q);
        }

    }

    // Вызываем базовую реализацию
    QWidget::keyPressEvent(event);
}
