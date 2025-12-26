#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include "GenerationType.h"
#include "interface/graphicalinterface.h"
#include "interface/triangulationinterface.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateBtn_clicked()
{
    QString angleCount = ui->angleCountTextInput->toPlainText().trimmed();
    try {
        int number = std::stoi(angleCount.toStdString());
        // Успешное преобразование
        if(number < 3){
            throw std::invalid_argument("");
        }


        GenerationType type = generationTypeFromString(ui->generationType->currentText());

        qDebug() << ui->generationType->currentText();
        qDebug() << static_cast<int>(type);
        if(type == GenerationType::Triangulation){
            TriangulationInterface *interface = new TriangulationInterface(number);
            interface->show();
        }else{
            GraphicalInterface *interface = new GraphicalInterface(type, number);
            interface->show();
        }

    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат числа!");
        ui->angleCountTextInput->setFocus();
        ui->angleCountTextInput->selectAll();
    } catch (const std::out_of_range& e) {
        QMessageBox::warning(this, "Ошибка", "Число слишком большое!");
        ui->angleCountTextInput->setFocus();
        ui->angleCountTextInput->selectAll();
    }
}

