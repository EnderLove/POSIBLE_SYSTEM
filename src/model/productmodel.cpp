#include "productmodel.h"

ProductModel::ProductModel(DBManagerModel *dbManager, QObject *parent): QObject(parent), m_dbManager(dbManager)
{
    QSqlQuery temp(m_dbManager->database());
    temp.exec("SELECT productName FROM products LIMIT 1");
    qDebug() << "Query error:" << temp.lastError();
}

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

