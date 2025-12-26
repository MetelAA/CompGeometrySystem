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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphicalinterface.h"

QT_BEGIN_NAMESPACE

class Ui_GraphicalInterface
{
public:
    QVBoxLayout *verticalLayout;
    CustomGraphicsView *graphicsView;

    void setupUi(QWidget *GraphicalInterface)
    {
        if (GraphicalInterface->objectName().isEmpty())
            GraphicalInterface->setObjectName("GraphicalInterface");
        GraphicalInterface->resize(901, 633);
        verticalLayout = new QVBoxLayout(GraphicalInterface);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new CustomGraphicsView(GraphicalInterface);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);


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
