#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sstream>
#include <iostream>
#include <QString>
#include <QtGui>
#include <QErrorMessage>
#include <vector>

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

bool MainWindow::CorrectMatrix(std::vector<std::vector<int> > matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix.size(); j++)
        {
            if ((i == j) && (matrix[i][j] != 0))
                return false;
            if (matrix[i][j] < 0)
                return false;
        }
    return true;
}

void MainWindow::Click()
{
    int numb = ui->AdjacencyMatrix->rowCount();
    std::vector<std::vector<int> > matrix(numb, std::vector<int> (numb, 0));
    QString str;
    for (int i = 0; i < numb; i++)
    {
        for (int j = 0; j < numb; j++)
        {
            str = ui->AdjacencyMatrix->item(i, j)->text();
            matrix[i][j] = str.toInt();
        }
    }
    if (CorrectMatrix(matrix))
    {
        ui->widget->setData(matrix);
        ui->widget->update();
    }
    else
    {
        ErrorMsg("Ошибка! Матрица смежности введена некорректно!");
    }
}


void MainWindow::on_EnterNodesNumb_clicked()
{
    int nodes_numb = (ui->NodesNumb->text()).toInt();
    if (nodes_numb > 0)
    {
        ui->AdjacencyMatrix->setColumnCount(nodes_numb);
        ui->AdjacencyMatrix->setRowCount(nodes_numb);
        for (int j = 0; j < nodes_numb; j++)
        {
            for (int i = 0; i < nodes_numb; i++)
            {
                QTableWidgetItem *newItem = new QTableWidgetItem( "0" );
                ui->AdjacencyMatrix->setItem( i, j, newItem );
            }
            ui->AdjacencyMatrix->setColumnWidth(j, 20);
            ui->AdjacencyMatrix->setRowHeight(j, 20);
        }
    }
    else
    {
        ErrorMsg("Ошибка! Количество вершин в графе должно быть положительным!");
    }
}
