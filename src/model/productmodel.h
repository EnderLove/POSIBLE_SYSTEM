#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QVector>
#include <QString>

class Product {
public:
    Product(QString barcode, QString name, double price)
        : m_barcode(barcode), m_name(name), m_price(price) {}

    QString getBarcode() const { return m_barcode; }
    QString getName() const { return m_name; }
    double getPrice() const { return m_price; }

private:
    QString m_barcode;
    QString m_name;
    double m_price;
};

class ProductModel {
public:
    ProductModel();

    QString getProductName(const QString &barcode) const;
    double getProductPrice(const QString &barcode) const;

    Product* findByBarcode(const QString &barcode);

private:
    QVector<Product*> m_products;
};

#endif // PRODUCTMODEL_H
