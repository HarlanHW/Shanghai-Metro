#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "metrograph.h"
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image;
    image.load("main.jpg");
    setAutoFillBackground(true);   // 这个属性一定要设置
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::IgnoreAspectRatio,
                       Qt::SmoothTransformation)));
    setPalette(pal);
    MainWindow::setWindowTitle("数据结构2.8.6");
    //ui->pushButton->setIcon(QIcon("image/main.jpg"));
    //ui->pushButton->setIconSize(QSize(50, 200));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MetroGraph *m=new MetroGraph();
    m->show();
    //m->showTest();
}
