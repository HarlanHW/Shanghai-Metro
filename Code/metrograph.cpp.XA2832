#include "metrograph.h"
#include "ui_metrograph.h"
#include <QDebug>
#include <QPen>
#include <QPainter>
#include <QMessageBox>
#define X0 400
#define Y0 50
#define ratio_x 0.8
#define ratio_y 0.8
#define station_point 5

MetroGraph::MetroGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MetroGraph)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    //*************************************************
    //功    能：站点初始化
    //格    式：文件第一行为站点个数
    //         每一行分别为“站点名称 横坐标 纵坐标 线路1 2……”
    //最后修改：20170909
    //*************************************************
    QFile *info=new QFile("info.txt");
    if(!info->open(QIODevice::ReadOnly|QIODevice::Text))
        qDebug()<<"没打开";

    QString info_str;
    QStringList info_list;
    while(!info->atEnd())
    {
        Node temp_node;
        info_str=info->readLine();
        info_list=info_str.split(" ");
        if(info_list.size()==3)//表示站的信息
        {
            //qDebug()<<info_list[0]<<"  "<<info_list[1]<<"  "<<info_list[2];
            temp_node.name=info_list[0];
            QString x=info_list[1];
            temp_node.x=x.toInt();
            QString y=info_list[2];
            temp_node.y=y.toInt();
            //qDebug()<<temp_node.name<<" "<<temp_node.x<<" "<<temp_node.y;
        }
        while(1)
        {
            Link temp_link;
            info_str=info->readLine();
            info_list=info_str.split(" ");
            if(info_str=="*****\n")
            {
                Nodes.append(temp_node);
                break;
            }
            else if(info_list.size()==4)
            {
                //qDebug()<<info_list[0]<<"  "<<info_list[1]<<"  "<<
                                        //info_list[2]<<"  "<<info_list[3];
                temp_link.to=info_list[0];
                QString n=info_list[1];
                temp_link.line=Line(n.toInt());
                QString f=info_list[2];
                temp_link.flag=f.toInt();
                temp_node.links.append(temp_link);
            }
        }
    }

}

MetroGraph::~MetroGraph()
{
    delete ui;
}

void MetroGraph::showTest()
{
    qDebug()<<Nodes.size();

    for(int i=0;i<Nodes.size();i++)
    {
        qDebug()<<Nodes[i].name<<"  "<<Nodes[i].x<<"  "<<Nodes[i].y;
        for(int j=0;j<Nodes[i].links.size();j++)
        {
            qDebug()<<Nodes[i].links.size();
            qDebug()<<Nodes[i].links[j].to<<"  "<<
                      Nodes[i].links[j].line.get_num()<<"  "<<
                      Nodes[i].links[j].flag;
        }

    }
}

Node MetroGraph::findNode(QString name)
{
    for(int i=0;i<Nodes.size();i++)
    {
        if(Nodes[i].name==name)
            return Nodes[i];
    }
}

void MetroGraph::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    QPen pen;
    if(paint_new)
    {
        for(int i=0;i<Paths.size()-1;i++)
        {
            Line this_line;
            for(int j=0;j<Paths[i].links.size();j++)
            {
                if(Paths[i].links[j].to==Paths[i+1].name)
                    this_line=Paths[i].links[j].line;

            }
            pen=QPen(this_line.color,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawLine(QPoint(Paths[i].x*ratio+X0+x0,Paths[i].y*ratio+Y0+y0),
                             QPoint(Paths[i+1].x*ratio+X0+x0,Paths[i+1].y*ratio+Y0+y0));

        }
        for(int i=0;i<Paths.size();i++)
        {
            if(Paths[i].links.size()>2)//换乘站
                pen=QPen(Qt::black,7*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            else
                pen=QPen(Paths[i].links[0].line.color,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawEllipse(QPoint(Paths[i].x*ratio+X0+x0,Paths[i].y*ratio+Y0+y0),
                                3*ratio,3*ratio);
        }

        for(int i=0;i<Paths.size();i++)
        {
            pen=QPen(Qt::white,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawEllipse(QPoint(Paths[i].x*ratio+X0+x0,Paths[i].y*ratio+Y0+y0),
                                2*ratio,2*ratio);
            pen=QPen(Qt::black,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);

            painter.setPen(pen);
            painter.drawText(QPoint(Paths[i].x*ratio+X0+x0,Paths[i].y*ratio+Y0+y0),
                             Paths[i].name);

        }
    }
    else
    {
        for(int i=0;i<Nodes.size();i++)
        {
            for(int j=0;j<Nodes[i].links.size();j++)
            {
               if(Nodes[i].links[j].flag==0)
                {
                    Node to=findNode(Nodes[i].links[j].to);
                    pen=QPen(Nodes[i].links[j].line.color,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
                    painter.setPen(pen);
                    painter.drawLine(QPoint(Nodes[i].x*ratio+X0+x0,Nodes[i].y*ratio+Y0+y0),
                                     QPoint(to.x*ratio+X0+x0,to.y*ratio+Y0+y0));
                }
                else if(Nodes[i].links[j].flag==1)
                {
                    Node to=findNode(Nodes[i].links[j].to);
                    pen=QPen(Nodes[i].links[j].line.color,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
                    painter.setPen(pen);
                    painter.drawLine(QPoint(Nodes[i].x*ratio+X0+2.5*ratio+x0,
                                            Nodes[i].y*ratio+Y0+2.5*ratio+y0),
                                    QPoint(to.x*ratio+X0+2.5*ratio+x0,
                                           to.y*ratio+Y0+2.5*ratio+y0));
                }
                else if(Nodes[i].links[j].flag==-1)
                {
                    Node to=findNode(Nodes[i].links[j].to);
                    pen=QPen(Nodes[i].links[j].line.color,5*ratio,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
                    painter.setPen(pen);
                    painter.drawLine(QPoint(Nodes[i].x*ratio+X0-2.5*ratio+x0,
                                            Nodes[i].y*ratio+Y0-2.5*ratio+y0),
                                    QPoint(to.x*ratio+X0-2.5*ratio+x0,
                                           to.y*ratio+Y0-2.5*ratio+y0));
                }
            }
        }
        for(int i=0;i<Nodes.size();i++)
        {
            if(Nodes[i].links.size()>2)//换乘站
                pen=QPen(Qt::black,7,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            else
                pen=QPen(Nodes[i].links[0].line.color,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawEllipse(QPoint(Nodes[i].x*ratio+X0+x0,
                                       Nodes[i].y*ratio+Y0+y0),3,3);
        }

        for(int i=0;i<Nodes.size();i++)
        {
            pen=QPen(Qt::white,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawEllipse(QPoint(Nodes[i].x*ratio+X0+x0,Nodes[i].y*ratio+Y0+y0),2,2);
            pen=QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
            painter.setPen(pen);
            painter.drawText(QPoint(Nodes[i].x*ratio+X0+x0,
                                    Nodes[i].y*ratio+Y0+y0),Nodes[i].name);

        }
    }
}

void MetroGraph::findPath(Node start,Node end)
{
    Flag=false;
    open.clear();
    close.clear();
    Paths.clear();
    if(start.name==end.name)
    {
        Paths.push_back(start);
        return;
    }
    start.count=1;
    open.push_back(start);
    while(open.size()!=0)
    {
        if(Flag)
            break;
        Node next=open[0];
        open.pop_front();
        close.push_back(next);
        for(int i=0;i<next.links.size();i++)
        {
            //qDebug()<<count;
            Node temp=findNode(next.links[i].to);
            if(!inOpen(temp))              
                temp.count=next.count+1;
            //qDebug()<<"5："<<temp.name<<end.name;
            if(temp.name==end.name)//temp.name==end.name)
            {
                close.push_back(temp);
                Flag=true;
                break;
            }
            else if(!inOpen(temp)&&!inClose(temp))
            {
                open.push_back(temp);
            }
       }
    }
    Node now=close.last();//最后一个
    Paths.push_front(now);//最后一个放到结果当中
    close.pop_back();//出栈
    while(close.size()>0)
    {
        Node last=close.last();
        if(last.count==now.count)
        {
            close.pop_back();
            continue;
        }
        else if(last.count<now.count)
        {
            bool is=false;
            for(int i=0;i<last.links.size();i++)
            {

                qDebug()<<"last:"<<last.name;
                qDebug()<<"links"<<last.links[i].to;
                qDebug()<<"now"<<now.name;
                Node to=findNode(last.links[i].to);
                if(last.links[i].to==now.name)
                {
                    is=true;
                    Paths.push_front(last);
                    close.pop_back();
                    now=last;
                    qDebug()<<now.name;
                    break;//跳出for循环
                }
            }
            if(!is)
                close.pop_back();
        }
        else
            close.pop_back();
    }

    paint_new=true;

}

void MetroGraph::on_pushButton_clicked()
{
    QString start=ui->StartLine->text();
    QString end=ui->EndLine->text();
    int check=0;
    for(int i=0;i<Nodes.size();i++)
    {
        if(Nodes[i].name==start||Nodes[i].name==end)
            check+=1;
    }
    //qDebug()<<check;
    if(check>=2)
    {
        Node s_n=findNode(start);
        Node e_n=findNode(end);
        for(int i=0;i<s_n.links.size();i++)
        {
            for(int j=0;j<e_n.links.size();j++)
            {
                if(s_n.links[i].line.num==e_n.links[j].line.num)
                {

                    findDirectPath(s_n,e_n,s_n.links[i].line.num);
                    this->repaint();
                    return;
                }
            }
        }
        findPath(s_n,e_n);
        this->repaint();
    }
    else
    {
        QMessageBox::warning(this,tr("警告对话框"),
                             tr("查询站点有误，请重新输入"),QMessageBox::Abort);
    }
}

void MetroGraph::findDirectPath(Node start,Node end,int num)
{
    Flag=false;
    open.clear();
    close.clear();
    Paths.clear();

    start.count=1;
    open.push_back(start);
    if(start.name==end.name)
    {

        Paths.push_back(start);
        return;
    }
    while(open.size()!=0)
    {
        if(Flag)
            break;
        Node next=open[0];
        open.pop_front();
        close.push_back(next);
        for(int i=0;i<next.links.size();i++)
        {
            //qDebug()<<count;
            Node temp=findNode(next.links[i].to);
            if(!inOpen(temp))
                temp.count=next.count+1;
            //qDebug()<<"5："<<temp.name<<end.name;
            if(temp.name==end.name)//temp.name==end.name)
            {
                close.push_back(temp);
                Flag=true;
                break;
            }
            else if(!inOpen(temp)&&!inClose(temp))
            {
                open.push_back(temp);
            }

       }

    }
    Node now=close.last();//最后一个
    Paths.push_front(now);//最后一个放到结果当中
    close.pop_back();//出栈
    while(close.size()>0)
    {
        Node last=close.last();
        /*qDebug()<<"0"<<close.size();
        qDebug()<<"1"<<last.name<<last.count;
        qDebug()<<"2"<<Paths.last().name<<Paths.last().count;
        qDebug()<<"3"<<now.name<<now.count;*/

        if(last.count==now.count)
        {
            close.pop_back();
            continue;
        }
        else if(last.count<now.count)
        {
            bool is=false;
            for(int i=0;i<last.links.size();i++)
            {

                //qDebug()<<"last:"<<last.name;
                //qDebug()<<"links"<<last.links[i].to;
                //qDebug()<<"now"<<now.name;
                Node to=findNode(last.links[i].to);
                if(last.links[i].to==now.name)
                {
                    is=true;
                    Paths.push_front(last);
                    close.pop_back();
                    now=last;
                    //qDebug()<<now.name;
                    break;//跳出for循环
                }
            }
            if(!is)
                close.pop_back();
        }
        else
            close.pop_back();
    }

    paint_new=true;
}

bool MetroGraph::hasInList(Node node)
{
    for(int i=0;i<Paths.size();i++)
    {
        if(Paths[i].name==node.name)
            return true;
    }
    return false;
}

bool MetroGraph::inClose(Node node)
{
    for(int i=0;i<close.size();i++)
    {
        if(close[i].name==node.name)
            return true;
    }
    return false;
}

bool MetroGraph::inOpen(Node node)
{
    for(int i=0;i<open.size();i++)
    {
        if(open[i].name==node.name)
            return true;
    }
    return false;
}

void MetroGraph::wheelEvent(QWheelEvent *event)
{
    //event->accept();      //接收该事件
    //int numDegrees = event->delta() / 1000;//滚动的角度，*8就是鼠标滚动的距离
    //ratio+=numDegrees;
    //this->repaint();
    ;
}

void MetroGraph::on_pushButton_2_clicked()
{
    paint_new=false;
    this->repaint();
}

void MetroGraph::on_pushButton_3_clicked()
{
    ratio+=0.05;
    this->repaint();
}

void MetroGraph::on_pushButton_4_clicked()
{
    ratio-=0.05;
    this->repaint();
}
/*void MetroGraph::mouseMoveEvent(QMouseEvent *e)
{
    x0=0;y0=0;
    e->accept();
    x0=x0+e->pos().x();
    y0=y0+e->pos().y();
    //int x=e->pos().x();
    //int y=e->pos().y();
    //qDebug()<<e->pos();

}
*/
void MetroGraph::on_pushButton_5_clicked()
{
    y0-=10;
    this->repaint();
}

void MetroGraph::on_pushButton_6_clicked()
{
    y0+=10;
    this->repaint();

}

void MetroGraph::on_pushButton_7_clicked()
{
    x0-=10;
    this->repaint();

}

void MetroGraph::on_pushButton_8_clicked()
{
    x0+=10;
    this->repaint();

}

