#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphview.h"
#include <QPainter>
#include <QPaintEvent>
#include <sstream>
#include <iostream>
#include "ui_mainwindow.h"

graphview::graphview(QWidget *parent) : QWidget(parent)
{
}

//рисуем черную рамочку где полотно для рисования
void graphview::imagegraph()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,size().width()-2,size().height()-2);
}

//рисуем вершину графа в указанных координатах и с указанным номером
void graphview::drawNode(int x, int y, QString a)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawEllipse(x, y, 6, 6);
    painter.setPen(Qt::black);
    painter.drawText(x-9,y+2,a);
}

//рисуем линию с указанными координатами начала, конца и цвета
void graphview::drawLine(int x0, int y0, int x, int y, QColor color)
{
    QPainter painter(this);
    painter.setPen(color);
    painter.drawLine(x0,y0,x,y);
}

std::vector<graphview::Node_> graphview::drawNodes()
{
    float r = 160;
    float alpha = (2*3.1416)/float(boost::num_vertices(d));
    float alpha0 = alpha;
    vertex_iterator v, v_end;
    std::vector<Node_> nodes;
    //рисуем все вешины графа, располагая их по окружности
    for (boost::tie(v, v_end) = vertices(d); v != v_end; ++v)
    {
        float x0 = r*sin(alpha)+ 210;
        float y0 = r*cos(alpha) + 180;
        drawNode(x0, y0, QString::number(*v + 1));
        nodes.push_back({x0, y0});
        alpha += alpha0;
    }
    return nodes;
}

void graphview::drawLines(std::vector<Node_> nodes)
{
    adjacency_iterator u, u_end;
    vertex_iterator v, v_end;
    //рисуем линии между необходимыми вершинами
    for (boost::tie(v, v_end) = vertices(d); v != v_end; ++v)
    {
        for (boost::tie(u, u_end) = boost::adjacent_vertices(*v, d); u != u_end; ++u)
        {
            float x1 = nodes[*u].x;
            float y1 = nodes[*u].y;
            float x2 = nodes[*v].x;
            float y2 = nodes[*v].y;
            drawLine(x1 + 3, y1 + 3, x2 + 3, y2 + 3, Qt::black);
        }
    }
}

void graphview::drawBridges(std::vector<Node_> nodes)
{
    //ищем мосты и рисуем ребра-мосты красным цветом
    auto bridges = bridge_find(d);
    for (auto p : bridges)
    {
        float x1 = nodes[p.first].x;
        float y1 = nodes[p.first].y;
        float x2 = nodes[p.second].x;
        float y2 = nodes[p.second].y;
        drawLine(x1 + 3, y1 + 3, x2 + 3, y2 + 3, Qt::red);
    }
}

void graphview::paintEvent(QPaintEvent *event)
{
    imagegraph();
    std::vector<Node_> nodes = drawNodes();
    drawLines(nodes);
    drawBridges(nodes);
}
