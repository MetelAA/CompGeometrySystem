#include "graphicalinterface.h"
#include "ui_graphicalinterface.h"
#include <QGraphicsScene>
#include "simplepolygon.h"

GraphicalInterface::GraphicalInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GraphicalInterface)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    SimplePolygon *polygon = new SimplePolygon(100, 800, 800);

    scene->addItem(polygon);
}

GraphicalInterface::~GraphicalInterface()
{
    delete ui;
}
