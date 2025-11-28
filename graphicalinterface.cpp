#include "graphicalinterface.h"
#include <QGraphicsScene>
#include "starpolygon.h"
#include "customgraphicsview.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QApplication>

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
    this->customView->setScene(scene);

    // Создаем и добавляем полигон
    StarPolygon *polygonN = new StarPolygon(this->pointsCount, this->width, this->height);
    scene->addItem(polygonN);
    this->polygon = polygonN;

    // Центрируем вид на полигоне
    this->customView->centerOn(polygonN);

    // Инициализация курсоров (раскомментируйте когда нужно)
    QPixmap redC = QPixmap("../res/red.png");
    QPixmap greenC = QPixmap("../res/green.png");
    this->redCurs = QCursor(redC);
    this->greenCurs = QCursor(greenC);
}

void GraphicalInterface::callback(const CPoint &p)
{
    bool pInP = this->polygon->point_in_polygon(p);

    if (pInP) {
        QApplication::setOverrideCursor(this->greenCurs);
    } else {
        QApplication::setOverrideCursor(this->redCurs);
    }
}

GraphicalInterface::~GraphicalInterface()
{

}
