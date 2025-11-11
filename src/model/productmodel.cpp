#include "productmodel.h"

ProductModel::ProductModel() {
    // Datos de ejemplo (esto normalmente vendría de una base de datos)
    m_products.append(new Product("001", "Coca Cola", 3.50));
    m_products.append(new Product("002", "Inka Cola", 3.00));
    m_products.append(new Product("003", "Agua San Luis", 2.00));
}

QString ProductModel::getProductName(const QString &barcode) const {
    for (auto p : m_products)
        if (p->getBarcode() == barcode)
            return p->getName();
    return "";
}

double ProductModel::getProductPrice(const QString &barcode) const {
    for (auto p : m_products)
        if (p->getBarcode() == barcode)
            return p->getPrice();
    return 0.0;
}

Product* ProductModel::findByBarcode(const QString &barcode) {
    for (auto p : m_products)
        if (p->getBarcode() == barcode)
            return p;
    return nullptr;
}
