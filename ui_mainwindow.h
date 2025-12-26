/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *generateBtn;
    QTextEdit *angleCountTextInput;
    QComboBox *generationType;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(688, 426);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        generateBtn = new QPushButton(centralwidget);
        generateBtn->setObjectName("generateBtn");
        generateBtn->setGeometry(QRect(150, 280, 371, 51));
        generateBtn->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        angleCountTextInput = new QTextEdit(centralwidget);
        angleCountTextInput->setObjectName("angleCountTextInput");
        angleCountTextInput->setGeometry(QRect(35, 110, 621, 81));
        generationType = new QComboBox(centralwidget);
        generationType->addItem(QString());
        generationType->addItem(QString());
        generationType->addItem(QString());
        generationType->addItem(QString());
        generationType->addItem(QString());
        generationType->setObjectName("generationType");
        generationType->setGeometry(QRect(0, 0, 691, 27));
        generationType->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 688, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        generateBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\274\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        angleCountTextInput->setMarkdown(QString());
        angleCountTextInput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        angleCountTextInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", nullptr));
        generationType->setItemText(0, QCoreApplication::translate("MainWindow", "simple poygon", nullptr));
        generationType->setItemText(1, QCoreApplication::translate("MainWindow", "star polygon", nullptr));
        generationType->setItemText(2, QCoreApplication::translate("MainWindow", "convex polygon", nullptr));
        generationType->setItemText(3, QCoreApplication::translate("MainWindow", "convex hull", nullptr));
        generationType->setItemText(4, QCoreApplication::translate("MainWindow", "triangulation", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
