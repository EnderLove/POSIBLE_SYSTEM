#ifndef DBMANAGERMODEL_H
#define DBMANAGERMODEL_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QFileInfo>
#include <iomanip>

// id, productName, barCode, basePrice, sellPrice, minimunStock, actualStock

class DBManagerModel : public QObject {
    Q_OBJECT

public:
    explicit DBManagerModel(QObject *parent = nullptr);
    ~DBManagerModel();

    bool connectToDatabase(const QString &dbPath);
    QSqlDatabase database() const;

private:
    QSqlDatabase m_db;
};
#endif // DBMANAGERMODEL_H
