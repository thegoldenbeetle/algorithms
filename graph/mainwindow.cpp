#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sstream>
#include <iostream>
#include <QString>
#include <QtGui>
#include <QErrorMessage>
#include <vector>
#include "bridge.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->DrawGraph, &QPushButton::clicked,
            this, &MainWindow::Click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ErrorMsg(QString s)
{
    QErrorMessage errorMessage;
    errorMessage.setWindowTitle("Graph");
    errorMessage.showMessage(s);
    errorMessage.exec();
}

void MainWindow::Click()
{
    int numb = ui->AdjacencyMatrix->rowCount();
    graph_t graph; //наш граф

    QString str;

    //забиваем вершины
    for (int i = 0; i < numb; i++)
    {
        boost::add_vertex(graph);
    }

    //забиваем связи между вершинами
    for (int i = 0; i < numb; i++)
    {
        for (int j = 0; j < numb; j++)
        {
            if (i < j)
            {
                str = ui->AdjacencyMatrix->item(i, j)->text();
                if (str.toInt() != 0)
                {
                    boost::add_edge(i, j, str.toInt(), graph); //забиваем в tree связи i и j вершин
                    boost::add_edge(j, i, str.toInt(), graph); //забиваем в tree связи j и i вершин
                }
            }
        }
    }
    ui->widget->setData(graph);
    ui->widget->update();
}

//действия по вводу числа вершин
void MainWindow::on_EnterNodesNumb_clicked()
{
    int nodes_numb = (ui->NodesNumb->text()).toInt();
    if ((nodes_numb > 0) && (nodes_numb <= 15))
    {
        ui->AdjacencyMatrix->setColumnCount(nodes_numb);
        ui->AdjacencyMatrix->setRowCount(nodes_numb);
        for (int j = 0; j < nodes_numb; j++)
        {
            for (int i = 0; i < nodes_numb; i++)
            {
                if (i >= j)
                {
                    QTableWidgetItem *newItem = new QTableWidgetItem(QLatin1String("0"));
                    newItem->setFlags(newItem->flags() & ~Qt::ItemIsEditable);
                    ui->AdjacencyMatrix->setItem(i, j, newItem);
                    ui->AdjacencyMatrix->item(i, j)->setBackgroundColor(Qt::lightGray);
                }
                else
                {
                    QTableWidgetItem *newItem = new QTableWidgetItem( "0" );
                    ui->AdjacencyMatrix->setItem( i, j, newItem );
                }
            }
            ui->AdjacencyMatrix->setColumnWidth(j, 20);
            ui->AdjacencyMatrix->setRowHeight(j, 20);
        }
    }
    else
    {
        ErrorMsg("Ошибка! Количество вершин в графе должно быть положительным и меньше 15!");
    }
}


void MainWindow::on_AdjacencyMatrix_itemSelectionChanged()
{
    for (int i = 0; i < ui->AdjacencyMatrix->rowCount(); i++)
        for (int j = 0; j < ui->AdjacencyMatrix->rowCount(); j++)
        {
            if (i < j)
            {
                if ((ui->AdjacencyMatrix->item(i, j)->text()).toInt() < 0)
                    ErrorMsg("Ошибка! Значение вес ребра должен быть положительным!");
                ui->AdjacencyMatrix->item(j, i)->setText(ui->AdjacencyMatrix->item(i, j)->text());
            }
        }
}

