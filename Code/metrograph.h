#ifndef METROGRAPH_H
#define METROGRAPH_H

#include <QWidget>
#include <QVector>
#include "node.h"
#include <QPaintEvent>
#include <QList>
#include <QStack>
#include <QQueue>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QToolButton>
#include <QDrag>
namespace Ui {
class MetroGraph;
}

class MetroGraph : public QWidget
{
    Q_OBJECT

public:
    explicit MetroGraph(QWidget *parent = 0);
    ~MetroGraph();
    void showTest();
    Node findNode(QString name);
    void paintEvent(QPaintEvent * /*event*/);
    void findPath(Node start,Node end);
    void findDirectPath(Node start,Node end,int num);
    bool hasInList(Node node);
    bool inClose(Node node);
    bool inOpen(Node node);
    void wheelEvent(QWheelEvent *event);
    //void mousePressEvent(QMouseEvent *e);
    //void mouseMoveEvent(QMouseEvent *e);
    bool enterBtn(QPoint pp, QToolButton *btn);
    double ratio=0.7;
    int x0=0;
    int y0=0;
    int x;
    int y;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MetroGraph *ui;
    QVector <Node> Nodes;
    QStack <Node> Paths;
    QQueue <Node> open;
    QQueue <Node> close;
    QQueue <int> ceng;
    bool Flag=false;
    bool paint_new=false;//没计算之前

};

#endif // METROGRAPH_H
