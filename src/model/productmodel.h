#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QObject>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
//#include "product.h"
#include "dbmanagermodel.h"

class ProductModel : public QObject {
    Q_OBJECT

public:
    explicit ProductModel(DBManagerModel *dbManager, QObject *parent = nullptr);

    QString getProductName(const QString &barcode);
    double getProductPrice(const QString &barcode);
    //Product* findByBarcode(const QString &barcode);

private:
    DBManagerModel *m_dbManager;
};

#endif // PRODUCTMODEL_H
