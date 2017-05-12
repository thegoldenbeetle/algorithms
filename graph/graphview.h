#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <sstream>
#include <iostream>

class graphview : public QWidget
{
    Q_OBJECT
public:
    explicit graphview(QWidget *parent = 0);
    void setData(std::vector<std::vector<int> > b) {  d = b;}

protected:
    void paintEvent(QPaintEvent *event ) override;

private:
    void drawNode(int x, int y, QString &a);
    void drawLine(int x0, int y0, int x, int y);
    void imagegraph();
    std::vector<std::vector<int> > d;
    struct Node_
    {
        float x;
        float y;
    };
};

#endif // GRAPHVIEW_H
