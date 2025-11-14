#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class GraphicalInterface;
}

class GraphicalInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicalInterface(QWidget *parent = nullptr);
    ~GraphicalInterface();

private:
    Ui::GraphicalInterface *ui;
    QGraphicsScene *scene;
};

#endif // GRAPHICALINTERFACE_H
