#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Click();
    void on_EnterNodesNumb_clicked();
    bool CorrectMatrix(std::vector<std::vector<int> > matrix);
    void ErrorMsg(QString s);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
