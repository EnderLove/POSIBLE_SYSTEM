#ifndef PRODUCTWINDOW_H
#define PRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class ProductWindow;
}

class ProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductWindow(QWidget *parent = nullptr);
    ~ProductWindow();

private:
    Ui::ProductWindow *ui;
};

#endif // PRODUCTWINDOW_H
