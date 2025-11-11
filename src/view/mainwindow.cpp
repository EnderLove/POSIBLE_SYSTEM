#include "mainwindow.h"
#include "productwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new ProductModel();
    controller = new ProductController(model, this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));

    //connect(ui->lineEdit, &QLineEdit::editingFinished, this, [this]()
    //{
    //    ui->label->setText(ui->lineEdit->text());
    //});

    connect(ui->lineEdit, &QLineEdit::returnPressed,this, &MainWindow::onBarcodeEntered);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ProductWindow *p = new ProductWindow();
    p->show();
}

void MainWindow::onBarcodeEntered()
{
    QString code = ui->lineEdit->text();
    QString productName = controller->searchProduct(code);
    ui->label->setText(productName);
}
