#include "productmodel.h"

ProductModel::ProductModel(DBManagerModel *dbManager, QObject *parent): QObject(parent), m_dbManager(dbManager){}

QString ProductModel::getProductName(const QString &barcode) {
    QSqlQuery query(m_dbManager->database());
    query.prepare("SELECT productName FROM products WHERE barCode = :barcode");
    query.bindValue(":barcode", barcode);

    if (query.exec() && query.next())
    {
        return query.value("productName").toString();
    }
    return "";
}

double ProductModel::getProductPrice(const QString &barcode) {
    QSqlQuery query(m_dbManager->database());
    query.prepare("SELECT sellPrice FROM products WHERE barCode = :barcode");
    query.bindValue(":barcode", barcode);

    if (query.exec() && query.next())
        return query.value("sellPrice").toDouble();

    return 0.0;
}

