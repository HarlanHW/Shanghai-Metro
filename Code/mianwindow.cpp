#include "mianwindow.h"
#include "ui_mianwindow.h"

MianWindow::MianWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MianWindow)
{
    ui->setupUi(this);
}

MianWindow::~MianWindow()
{
    delete ui;
}
