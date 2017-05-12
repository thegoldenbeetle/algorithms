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

void graphview::imagegraph()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,size().width()-2,size().height()-2);
}

void graphview::drawNode(int x, int y, QString &a)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawEllipse(x, y, 6, 6);
    painter.setPen(Qt::black);
    painter.drawText(x-9,y+2,a);
}

void graphview::drawLine(int x0, int y0, int x, int y)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.drawLine(x0,y0,x,y);
}

void graphview::drawArrows(int x, int y,)
{
    drawLine(x, y, )
    drawLine(x, y, )
}
/*void graphview::paint(rbtree *b, int x0, int y0, float alpha, float r)
{
    if (b!=nullptr && b->key!=0)
    {
        drawNode(x0-3,y0-3,QString::number(b->key), b->color);
       if (b->left!=nullptr && b->left->key!=0)
        {
           drawLine(x0-3,y0+3,x0-r*sin(alpha),y0+r*cos(alpha));
           paint(b->left,x0-r*sin(alpha),y0+r*cos(alpha), alpha/1.8, r/1.2);
        }
        if (b->right!=nullptr && b->right->key!=0)
        {
            drawLine(x0+3,y0+3,x0+r*sin(alpha),y0+r*cos(alpha));
            paint(b->right,x0+r*sin(alpha),y0+r*cos(alpha), alpha/1.8, r/1.2);
        }
    }
}*/

void graphview::paintEvent(QPaintEvent *event)
{
    imagegraph();
    float r = 160;
    float alpha = (2*3.1416)/float(d.size());
    float alpha0 = alpha;
    std::vector<Node_> nodes;
    for (int i = 0; i < d.size(); i++)
    {
        float x0 = r*sin(alpha)+ 210;
        float y0 = r*cos(alpha) + 180;
        drawNode(x0, y0, QString::number(i+1));
        nodes.push_back({x0, y0});
        alpha += alpha0;
    }
    for (int i = 0; i < d.size(); i++)
        for (int j = 0; j < d.size(); j++)
        {
            if (d[i][j] != 0)
            {
                float x1 = nodes[i].x;
                float y1 = nodes[i].y;
                float x2 = nodes[j].x;
                float y2 = nodes[j].y;
                drawLine(x1 + 3, y1 + 2, x2 + 3, y2 + 2);
                if (d[j][i] == 0)
                {
                    drawArrows(x2 + 3, y2 + 2, );
                }
            }
        }
}
