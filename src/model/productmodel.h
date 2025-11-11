#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QString>
#include <QMap>

class ProductModel {
public:
    ProductModel();

    QString getProductName(const QString &barcode) const;

private:
    QMap<QString, QString> products; // código -> nombre
};

#endif // PRODUCTMODEL_H
