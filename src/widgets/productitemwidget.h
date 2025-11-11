#ifndef PRODUCTITEMWIDGET_H
#define PRODUCTITEMWIDGET_H

#include <QWidget>

namespace Ui {
class ProductItemWidget;
}

class ProductItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductItemWidget(QString name, double price, QWidget *parent = nullptr);
    ~ProductItemWidget();

    QString getName() const;
    double getPrice() const;
    int getQuantity() const;

signals:
    void itemDeleted(QString name);
    void quantityChanged(QString name, int quantity);

private slots:
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnDelete_clicked();
    void on_spnQuantity_valueChanged(int value);

private:
    Ui::ProductItemWidget *ui;
    QString m_name;
    double m_price;
};

#endif // PRODUCTITEMWIDGET_H
