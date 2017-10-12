#ifndef LINK_H
#define LINK_H
#include <QString>
#include "line.h"
//*************************************************
//类    名：Link
//说    明：线路类，内容为线路编号和颜色
//
//最后修改：20170915
//*************************************************
class Link
{
public:
    Link();
    //构造函数说明：站名，线路，flag
    Link(QStringList strlist);
//private:
    QString to;//下一站的名字
    Line line;//所在线路
    int flag;//标签，画图使用
    int weight;
};

#endif // LINK_H
