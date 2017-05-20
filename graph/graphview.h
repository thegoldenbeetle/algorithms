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
    struct Node_
    {
        float x;
        float y;
    };

protected:
    void paintEvent(QPaintEvent *event ) override;

private:
    void drawNode(int x, int y, QString a);
    void drawLine(int x0, int y0, int x, int y, QColor color);
    void imagegraph();
    std::vector<Node_> drawNodes();
    void drawLines(std::vector<Node_> nodes);
    void drawBridges(std::vector<Node_> nodes);
    graph_t d;

};

#endif // GRAPHVIEW_H
