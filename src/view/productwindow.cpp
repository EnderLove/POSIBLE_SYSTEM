#include "productwindow.h"
#include "ui_productwindow.h"

ProductWindow::ProductWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductWindow)
{
    ui->setupUi(this);
}

ProductWindow::~ProductWindow()
{
    delete ui;
}
