#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/productmodel.h"
#include "../controller/productcontroller.h"
#include "../widgets/productitemwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;   // This class was automatically created by Qt Designer in ui_mainwindow.h
}                   // We can refer to this class by using Ui::MainWindow... or smth like that
QT_END_NAMESPACE

class MainWindow : public QMainWindow   // Here we inheritate QMainWindow for our class MainWindow adding (menus, toolbars, statusbar, widget...)
{
    Q_OBJECT                            // This is a powerful macro that habilitates event mechanisms

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

    QMap<QString, ProductItemWidget*> productWidgets;
};

#endif // MAINWINDOW_H
