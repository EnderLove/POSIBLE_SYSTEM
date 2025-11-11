#ifndef PRODUCTCONTROLLER_H
#define PRODUCTCONTROLLER_H

#include "../model/productmodel.h"
#include <QObject>

class ProductController : public QObject {
    Q_OBJECT
public:
    explicit ProductController(ProductModel *model, QObject *parent = nullptr);

    QString searchProduct(const QString &barcode);

private:
    ProductModel *m_model;
};

#endif // PRODUCTCONTROLLER_H
