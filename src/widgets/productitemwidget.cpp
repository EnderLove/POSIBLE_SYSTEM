#include "productitemwidget.h"
#include "ui_productitemwidget.h"

ProductItemWidget::ProductItemWidget(QString name, double price, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ProductItemWidget),
    m_name(name),
    m_price(price)
{
    ui->setupUi(this);
    ui->lblProductName->setText(name);
    ui->lblProductPrice->setText(QString::number(price, 'f', 2));
    ui->spnQuantity->setValue(1);
}

ProductItemWidget::~ProductItemWidget()
{
    delete ui;
}

QString ProductItemWidget::getName() const { return m_name; }
double ProductItemWidget::getPrice() const { return m_price; }
int ProductItemWidget::getQuantity() const { return ui->spnQuantity->value(); }

void ProductItemWidget::on_btnPlus_clicked()
{
    ui->spnQuantity->setValue(ui->spnQuantity->value() + 1);
}

void ProductItemWidget::on_btnMinus_clicked()
{
    if (ui->spnQuantity->value() > 1)
        ui->spnQuantity->setValue(ui->spnQuantity->value() - 1);
}

void ProductItemWidget::on_btnDelete_clicked()
{
    emit itemDeleted(m_name);
    deleteLater(); // Elimina el widget de la interfaz
}

void ProductItemWidget::on_spnQuantity_valueChanged(int value)
{
    emit quantityChanged(m_name, value);
}
