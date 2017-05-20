/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "graphview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *AdjacencyMatrix;
    QPushButton *EnterNodesNumb;
    QPushButton *DrawGraph;
    QLineEdit *NodesNumb;
    graphview *widget;
    QLabel *TextGraphImage;
    QLabel *TextEnterNodesNumb;
    QLabel *TextEnterDistances;
    QLabel *TextEnterDistances2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 481);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AdjacencyMatrix = new QTableWidget(centralWidget);
        AdjacencyMatrix->setObjectName(QString::fromUtf8("AdjacencyMatrix"));
        AdjacencyMatrix->setGeometry(QRect(20, 150, 241, 192));
        EnterNodesNumb = new QPushButton(centralWidget);
        EnterNodesNumb->setObjectName(QString::fromUtf8("EnterNodesNumb"));
        EnterNodesNumb->setGeometry(QRect(110, 50, 91, 31));
        DrawGraph = new QPushButton(centralWidget);
        DrawGraph->setObjectName(QString::fromUtf8("DrawGraph"));
        DrawGraph->setGeometry(QRect(20, 360, 111, 41));
        NodesNumb = new QLineEdit(centralWidget);
        NodesNumb->setObjectName(QString::fromUtf8("NodesNumb"));
        NodesNumb->setGeometry(QRect(20, 50, 71, 31));
        widget = new graphview(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(290, 70, 431, 361));
        TextGraphImage = new QLabel(centralWidget);
        TextGraphImage->setObjectName(QString::fromUtf8("TextGraphImage"));
        TextGraphImage->setGeometry(QRect(280, 30, 441, 21));
        QFont font;
        font.setPointSize(10);
        TextGraphImage->setFont(font);
        TextEnterNodesNumb = new QLabel(centralWidget);
        TextEnterNodesNumb->setObjectName(QString::fromUtf8("TextEnterNodesNumb"));
        TextEnterNodesNumb->setGeometry(QRect(20, 30, 181, 16));
        TextEnterNodesNumb->setFont(font);
        TextEnterDistances = new QLabel(centralWidget);
        TextEnterDistances->setObjectName(QString::fromUtf8("TextEnterDistances"));
        TextEnterDistances->setGeometry(QRect(20, 100, 161, 21));
        TextEnterDistances->setFont(font);
        TextEnterDistances2 = new QLabel(centralWidget);
        TextEnterDistances2->setObjectName(QString::fromUtf8("TextEnterDistances2"));
        TextEnterDistances2->setGeometry(QRect(20, 120, 151, 16));
        TextEnterDistances2->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bridges", 0, QApplication::UnicodeUTF8));
        EnterNodesNumb->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", 0, QApplication::UnicodeUTF8));
        DrawGraph->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", 0, QApplication::UnicodeUTF8));
        TextGraphImage->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\263\321\200\320\260\321\204\320\260, \321\200\320\265\320\261\321\200\320\260-\320\274\320\276\321\201\321\202\321\213 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\321\213 \320\272\321\200\320\260\321\201\320\275\321\213\320\274 \321\206\320\262\320\265\321\202\320\276\320\274", 0, QApplication::UnicodeUTF8));
        TextEnterNodesNumb->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 \320\262\320\265\321\200\321\210\320\270\320\275 \320\263\321\200\320\260\321\204\320\260", 0, QApplication::UnicodeUTF8));
        TextEnterDistances->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\274\320\265\320\266\320\264\321\203", 0, QApplication::UnicodeUTF8));
        TextEnterDistances2->setText(QApplication::translate("MainWindow", "\320\262\320\265\321\200\321\210\320\270\320\275\320\260\320\274\320\270 \320\263\321\200\320\260\321\204\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
