#include "dbmanagermodel.h"

DBManagerModel::DBManagerModel(QObject *parent)
    : QObject(parent) {}

DBManagerModel::~DBManagerModel() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DBManagerModel::connectToDatabase(const QString &dbPath) {

    QString absolutePath = QFileInfo(dbPath).absoluteFilePath();
    qDebug() << "Ruta relativa recibida:" << dbPath;
    qDebug() << "Ruta absoluta usada:" << absolutePath;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qWarning() << "Error al abrir la base de datos:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Base de datos abierta correctamente:" << absolutePath;
    qDebug() << "Tablas encontradas:" << m_db.tables();

// TEST QUERY TABLE =======================

    QSqlQuery query;
    QString selectQuery = "SELECT barCode, productName FROM products LIMIT 5";

    if(query.exec(selectQuery)){
        while(query.next()){
            QString codigo = query.value("barCode").toString();
            QString nombre = query.value("productName").toString();
            qDebug() << "   Nombre:" << nombre << " |       Cod:" << codigo;
        }
    }
// =========================================

    return true;
}

QSqlDatabase DBManagerModel::database() const {
    return m_db;
}
