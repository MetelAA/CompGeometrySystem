#include "graphicalinterface.h"
#include <QGraphicsScene>
#include "src/polygons/simplepolygon.h"
#include "customgraphicsview.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QApplication>
#include "GenerationType.h"
#include "src/polygons/convexpolygon.h"
#include "src/polygons/starpolygon.h"
#include "src/shells/convexhull.h"
#include "src/shells/randompointsset.h"

GraphicalInterface::GraphicalInterface(GenerationType polygonType, int pointsCount, QWidget *parent)
    : QWidget(parent)
    , pointsCount(pointsCount)
    , polygonType(polygonType)
{
    // Устанавливаем минимальный размер
    setMinimumSize(this->width, this->height);

    // Создаем главный layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // Создаем кастомный view
    this->customView = new CustomGraphicsView(this->width, this->height, this);
    verticalLayout->addWidget(this->customView);

    // Создаем сцену
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, this->width, this->height);
    this->customView->setScene(scene);

    switch(polygonType){
    case GenerationType::ConvexPolygon:
    {
        ConvexPolygon *polygonN = new ConvexPolygon(this->pointsCount, this->width, this->height);
        scene->addItem(polygonN);
        this->polygon = polygonN;
    }
        break;
    case GenerationType::SimplePolygon:
    {
        SimplePolygon *polygonN = new SimplePolygon(this->pointsCount, this->width, this->height);
        scene->addItem(polygonN);
        this->polygon = polygonN;
    }
        break;
    case GenerationType::StarPolygon:
    {
        StarPolygon *polygonN = new StarPolygon(this->pointsCount, this->width, this->height);
        scene->addItem(polygonN);
        this->polygon = polygonN;
    }
        break;
    case GenerationType::ConvexHull:{
        this->polygon = nullptr;
        RandomPointsSet *set = new RandomPointsSet(this->pointsCount, this->width, this->height);
        ConvexHull *hull = new ConvexHull(set);
        scene->addItem(hull);
    }
        break;
    }


    QPixmap redC = QPixmap("../res/red.png");
    QPixmap greenC = QPixmap("../res/green.png");
    this->redCurs = QCursor(redC);
    this->greenCurs = QCursor(greenC);
}

void GraphicalInterface::callback(const CPoint &p)
{
    if(this->polygon != nullptr){
        bool pInP = this->polygon->point_in_polygon(p);

        if (pInP) {
            QApplication::setOverrideCursor(this->greenCurs);
        } else {
            QApplication::setOverrideCursor(this->redCurs);
        }
    }

}

GraphicalInterface::~GraphicalInterface()
{

}
