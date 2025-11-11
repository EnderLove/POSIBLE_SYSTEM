#include "productcontroller.h"

ProductController::ProductController(ProductModel *model, QObject *parent)
    : QObject(parent), m_model(model) {}

QString ProductController::searchProduct(const QString &barcode) {
    return m_model->getProductName(barcode);
}
