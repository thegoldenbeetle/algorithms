#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <sstream>
#include <iostream>
#include "bridge.h"

class graphview : public QWidget
{
    Q_OBJECT
public:
    explicit graphview(QWidget *parent = 0);
    void setData(graph_t b) {  d = b;}

protected:
    void paintEvent(QPaintEvent *event ) override;

private:
    void drawNode(int x, int y, QString a);
    void drawLine(int x0, int y0, int x, int y, QColor color);
    void imagegraph();
    graph_t d;
    struct Node_
    {
        float x;
        float y;
    };
};

#endif // GRAPHVIEW_H
