/********************************************************************************
** Form generated from reading UI file 'graphicalinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICALINTERFACE_H
#define UI_GRAPHICALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicalInterface
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GraphicalInterface)
    {
        if (GraphicalInterface->objectName().isEmpty())
            GraphicalInterface->setObjectName("GraphicalInterface");
        GraphicalInterface->resize(716, 494);
        graphicsView = new QGraphicsView(GraphicalInterface);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 20, 721, 481));

        retranslateUi(GraphicalInterface);

        QMetaObject::connectSlotsByName(GraphicalInterface);
    } // setupUi

    void retranslateUi(QWidget *GraphicalInterface)
    {
        GraphicalInterface->setWindowTitle(QCoreApplication::translate("GraphicalInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicalInterface: public Ui_GraphicalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALINTERFACE_H
