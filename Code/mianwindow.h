#ifndef MIANWINDOW_H
#define MIANWINDOW_H

#include <QWidget>

namespace Ui {
class MianWindow;
}

class MianWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MianWindow(QWidget *parent = 0);
    ~MianWindow();

private:
    Ui::MianWindow *ui;
};

#endif // MIANWINDOW_H
