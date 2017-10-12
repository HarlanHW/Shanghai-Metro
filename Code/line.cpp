#include "line.h"

Line::Line()
{
    int n=0;
    color=QColor(0,0,0);
}

Line::Line(int input_n)
{
    /*********************上海地铁颜色rgb**********************
      1         234,4,55
      2         135,211,0
      3         255,209,0
      4         79,31,145
      5         162,76,200
      6         229,15,159
      7         255,114,0
      8         0,162,221
      9         120,199,235
      10        221,160,221
      11        139,0,0
      12        16,97,74
      13        231,125,173
     *******************************************************/
       num=input_n;
       switch (num) {
       case 1:
           color=QColor(234,4,55);
           break;
       case 2:
           color=QColor(135,211,0);
           break;
       case 3:
           color=QColor(255,209,0);
           break;
       case 4:
           color=QColor(79,31,145);
           break;
       case 5:
           color=QColor(162,76,200);
           break;
       case 6:
           color=QColor(229,15,159);
           break;
       case 7:
           color=QColor(255,114,0);
           break;
       case 8:
           color=QColor(0,162,221);
           break;
       case 9:
           color=QColor(120,199,235);
           break;
       case 10:
           color=QColor(221,160,221);
           break;
       case 11:
           color=QColor(139,0,0);
           break;
       case 12:
           color=QColor(16,97,74);
           break;
       case 13:
           color=QColor(231,125,173);
           break;
       case 16:
           color=QColor(100,0,200);
           break;
       default:
           color=QColor(0,0,0);
           break;
       }
}

int Line::get_num()
{
    return num;
}
