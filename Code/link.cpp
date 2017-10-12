#include "link.h"

Link::Link()
{
    weight=1;
}

Link::Link(QStringList strlist)
{
    to=strlist[0];
    int l=strlist[1].toInt();
    line=Line(l);
    flag=strlist[2].toInt();
    weight=1;
}
