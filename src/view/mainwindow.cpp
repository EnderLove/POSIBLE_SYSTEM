#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "productwindow.h"
#include "../model/dbmanagermodel.h"

// 9002490273262 RED BULL THE AMBAR EDITION 250ML

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollAreaProducts->setWidgetResizable(true);

    QString dbPath = QCoreApplication::applicationDirPath() + "/../../database/products.db";
    qDebug() << "Ruta calculada a DB: " << dbPath;

    DBManagerModel *dbManager = new DBManagerModel(this);
    if (!dbManager->connectToDatabase(dbPath))
    {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos");
        return;
    }

    model = new ProductModel(dbManager, this);
    controller = new ProductController(model, this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));


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
    ui->lineEdit->clear();

    // Buscar producto en el modelo mediante el controlador
    QString productName = controller->searchProduct(code);
    double productPrice = controller->getProductPrice(code);

    if (productName.isEmpty()) {
        //QMessageBox::warning(this, "Error", "Producto no encontrado.");
        return;
    }

    // Crear el widget del producto
    ProductItemWidget *item = new ProductItemWidget(productName, productPrice, this);

    // Conectar señales del widget con la ventana principal
    connect(item, &ProductItemWidget::itemDeleted, this, [=](QString name) {
        qDebug() << "Producto eliminado:" << name;
        // Podrías recalcular el total aquí, por ejemplo
    });

    connect(item, &ProductItemWidget::quantityChanged, this, [=](QString name, int qty) {
        qDebug() << "Cantidad actualizada:" << name << qty;
        // Podrías actualizar el subtotal aquí
    });

    // Añadir al layout
    ui->layoutProducts_2->addWidget(item);

    // (Opcional) actualizar totales, etc.
}
