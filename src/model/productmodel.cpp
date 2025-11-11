#include "productmodel.h"

ProductModel::ProductModel() {
    // simulamos una "base de datos"
    products["123"] = "Coca-Cola 500ml";
    products["456"] = "Papas Lays";
    products["789"] = "Chocolate Sublime";
}

QString ProductModel::getProductName(const QString &barcode) const {
    return products.value(barcode, "Producto no encontrado");
}
