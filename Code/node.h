#ifndef NODE_H
#define NODE_H
#include <QString>
#include <QVector>
#include <QList>
#include "link.h"
//*************************************************
//类    名：Node
//说    明：节点类，表示每个站点
//
//最后修改：20170915
//*************************************************
class Node
{
public:
    Node();
    bool operator ==(const Node b);
    QString name;//站名
    int x;//横坐标
    int y;//纵坐标
    QList <Link> links;
    int count=-1;

};

#endif // NODE_H
