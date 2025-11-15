#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/productmodel.h"
#include "../controller/productcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void onBarcodeEntered();

private:
    Ui::MainWindow *ui;

    ProductModel *model;
    ProductController *controller;
};
#endif // MAINWINDOW_H
