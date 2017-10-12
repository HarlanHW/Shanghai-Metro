#ifndef LINE_H
#define LINE_H
#include <QColor>
//*************************************************
//类    名：Line
//说    明：线路类，内容为线路编号和颜色
//
//最后修改：20170915
//*************************************************
class Line
{
public:
    Line();
    Line(int input_n);
    int get_num();
//private:
    int num;
    QColor color;
};

#endif // LINE_H
